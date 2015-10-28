#include "parse.hpp"
#include "Errors.hpp"

parse::parse() : _end_instructions(false) {
	_fill_start_array();
	_input_read();
	// _check_instructions();
	_list_errors();
}

parse::parse(char *name) : _end_instructions(false) {
	std::cout<<"File read : "<< name <<std::endl;
	_fill_start_array();
	_file_read(name);
	// _check_instructions();
	_list_errors();
}

parse::parse(parse const & src) {
	*this = src;
}

parse &parse::operator=(parse const & rhs) {
	*this = rhs;
	return (*this);
}

parse::~parse() {
	// std::cout<<"Parse destructor"<<std::endl;
}

void 	parse::_check_semicolon(std::string line) {
	std::size_t found;
	found = line.find(';', 0);
	if (found == 0) {
		if ((line.find(';', 1)) == 1)
			_end_instructions = true;
		return ;
	}
	if (found != std::string::npos) {
		line = line.substr(0, found);
	}
	_raw_file.push_back(line);
}

void	parse::_read_line(std::string line) {
	std::cout << line << std::endl;
}

void	parse::_input_read() {
	std::string tmpline;
	while (std::getline(std::cin, tmpline)) {
		_check_semicolon(tmpline);
		if (_end_instructions == true)
			break ; 
	}
	for (std::list<std::string>::iterator it = _raw_file.begin(); it != _raw_file.end(); it++) {
		split(*it, ' ');
	}
	_check_tokens();
}

void	parse::_file_read(char *name) {
	std::ifstream ifs;
	ifs.open(name, std::ifstream::in);
	if (ifs.is_open()) {
		std::string tmpline;
		while (std::getline(ifs, tmpline)) {
			_check_semicolon(tmpline);
		}
		ifs.close();
		for (std::list<std::string>::iterator it = _raw_file.begin(); it != _raw_file.end(); it++) {
			split(*it, ' ');
		}
		_check_tokens();
	}
	else
		throw FileError();
		// std::cout<<"Error while opening the file : " << name <<std::endl;
}

void	parse::_fill_start_array() {
	_instructions_type.push_back("push");
	_instructions_type.push_back("pop");
	_instructions_type.push_back("dump");
	_instructions_type.push_back("assert");
	_instructions_type.push_back("add");
	_instructions_type.push_back("sub");
	_instructions_type.push_back("div");
	_instructions_type.push_back("mod");
	_instructions_type.push_back("mul");
	_instructions_type.push_back("print");
	_instructions_type.push_back("exit");
	_values_type.push_back("int8");
	_values_type.push_back("int16");
	_values_type.push_back("int32");
	_values_type.push_back("float");
	_values_type.push_back("double");
}

void					parse::_check_tokens() {
	size_t				found_value;
	size_t				found_instruction;

	vecTok = new std::vector<Token>;
	for (std::vector<int>::size_type i = 0; i != _tokens.size(); i++) {
		for (std::vector<int>::size_type j = 0; j != _instructions_type.size(); j++) {
			if ((found_instruction = _tokens[i].find(_instructions_type[j], 0)) != std::string::npos) {
				instructions.push_back(_tokens[i]);
				instr = _tokens[i];				
				if (_tokens[i] == "push" || _tokens[i] == "assert") {
					if (!_tokens[i + 1].empty()) {
						for (std::vector<int>::size_type k = 0; k != _values_type.size(); k++) {
							if ((found_value = _tokens[i + 1].find(_values_type[k], 0)) != std::string::npos) {
								type = _values_type[k];
								size_t start = _tokens[i + 1].find("(",0) + 1;
								size_t stop = _tokens[i + 1].find(")",0) ;
								std::string r_value = _tokens[i + 1].substr(start, stop - start);
								if (!r_value.empty() && stop != std::string::npos && start != std::string::npos) {
									if (_check_values(_tokens[i + 1], r_value)) {
										value = r_value;
										vecTok->push_back(Token(instr, type, value));
									}
								}
								if ((stop - start < 1) || (stop == std::string::npos || start == std::string::npos))
									errors.push_back("Error - Value not found : " + _tokens[i + 1]);
								i++;
								break ;
							}
						}
						if (found_value == std::string::npos) 
							errors.push_back("Error - Value type not found : " + _tokens[i]);
				 	}
				}
				else
					vecTok->push_back(Token(instr));
				break;
			}
			if (j == (_instructions_type.size() - 1))
				errors.push_back("Error - Syntax error : " + _tokens[i]);
		}
	}
}

bool					parse::_check_values(std::string type, std::string value) {
	if (type.find("int8", 0, 4) != std::string::npos)	{
		std::regex reg("[-]?[0-9]+");
		if (!std::regex_match(value, reg)) {
			errors.push_back("Error - Value is no 8 bits integer : " + value);
			return (false);
		}
		if ((std::stod(value) > 127) || (std::stod(value) < -128)) {
			std::string tmp = "Error - " + value + " is beyond an int 8 bits";
			errors.push_back(tmp);
			return (false);
		}
	}

	if (type.find("int16", 0, 5) != std::string::npos)	{
		std::regex reg("[-]?[0-9]+");
		if (!std::regex_match(value, reg)) {
			errors.push_back("Error - Value is no 16 bits integer : " + value);
			return (false);
		}
		if ((std::stod(value) > 32767) || (std::stod(value) < -32768)) {
			std::string tmp = "Error - " + value + " is beyond an int 16 bits";
			errors.push_back(tmp);
			return (false);
		}
	}

	if (type.find("int32", 0, 5) != std::string::npos)	{
		std::regex reg("[-]?[0-9]+");
		if (!std::regex_match(value, reg)) {
			errors.push_back("Error - Value is no 32 bits integer : " + value);
			return (false);
		}
		if ((std::stod(value) > 2147483647) || (std::stod(value) < -2147483648)) {
			std::string tmp = "Error - " + value + " is beyond an int 32 bits";
			errors.push_back(tmp);
			return (false);
		} 
	}

	if (type.find("float", 0, 5) != std::string::npos)	{
		std::regex reg("[-]?[0-9]+[.][0-9]+");
		if (!std::regex_match(value, reg)) {
			errors.push_back("Error - Value is not a float : " + value);
			return (false);
		}
		
		if ((std::stod(value) > std::numeric_limits<float>::max()) || (std::stod(value) < std::numeric_limits<float>::min())) {
			// throw OverflowError();
			std::string tmp = "Error - " + value + " is beyond a float";
			errors.push_back(tmp);
			return (false);
		}
	}

	// check overflow
	if (type.find("double", 0, 6) != std::string::npos)	{		
		std::regex reg("[-]?[0-9]+[.][0-9]+");
		if (!std::regex_match(value, reg)) {
			errors.push_back("Error - Value is not a double : " + value);
			return (false);
		}
	}
	return (true);
}

void					parse::_list_errors() {
	if (!errors.empty()) {
		for (std::vector<std::string>::iterator it = errors.begin(); it != errors.end() ; it++) {
			std::cout<<*it<<std::endl;
		}
	}
}

std::vector<std::string> &parse::split(const std::string &s, char delim, std::vector<std::string> &_tokens) {
    std::stringstream	ss(s);
    std::string 		item;
    while (std::getline(ss, item, delim)) {
        if (!item.empty())
        	_tokens.push_back(item);
    }
    return _tokens;
}

void parse::split(const std::string &s, char delim) {
    split(s, delim, _tokens);
}


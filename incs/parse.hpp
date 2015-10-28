#ifndef PARSE_HPP
# define PARSE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <list>
# include <string>
# include <vector>
# include <cctype>
# include <stdlib.h>
# include <regex>
# include "Token.hpp"

class parse
{
public:
	parse();
	parse(char *name);
	parse(parse const & src);
	~parse();
	parse &operator=(parse const & rhs);

	std::vector<std::string>	&split(const std::string &s, char delim, std::vector<std::string> &elems);
	void						split(const std::string &s, char delim);
	std::vector<std::string>	instructions;
	std::vector<std::string>	errors;
	std::string					instr;
	std::string					type;
	std::string					value;
	std::vector<Token>			*vecTok;

private:
	void						_input_read();
	void						_file_read(char *name);
	void						_read_line(std::string);
	void						_check_semicolon(std::string);
	void						_tokenize(std::string line);
	void						_check_tokens();
	void						_check_instructions();
	void						_fill_start_array();
	void						_list_errors();
	void						_print_values();
	bool						_check_values(std::string type, std::string value);
	std::list<std::string>		_raw_file;
	std::vector<std::string>	_tokens;
	std::vector<std::string>	_tmp;
	std::vector<std::string>	_instructions_type;
	std::vector<std::string>	_values_type;
	// std::vector<std::string>	_operands_type;
	bool						_end_instructions;
	bool						_parse_error;
};
// std::ostream &   operator<<(std::ostream &a, Vector2 const &vec);

#endif
#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <string>

class Token
{
public:
	Token(std::string instr);
	Token(std::string instr, std::string type,std::string value);
	Token(Token const & src);
	Token &operator=(Token const & rhs);
	~Token();
	std::string	getInstr(void) const;
	std::string	getType(void) const;
	std::string	getValue(void) const;

private:
	Token();
	std::string	_instr;
	std::string	_type;
	std::string	_value;
};

#endif
#include "token.hpp"

Token::Token() {

}

Token::Token(std::string instr):_instr(instr) {

}

Token::Token(std::string instr, std::string type,std::string value):_instr(instr), _type(type), _value(value) {

}

Token::Token(Token const & src) {
	*this = src;
}

Token & Token::operator=(Token const & rhs) {
	if (this != &rhs) {
		_instr = rhs.getInstr();
		_type = rhs.getType();
		_value = rhs.getValue();
	}
	return(*this);
}

Token::~Token() {

}

std::string	Token::getInstr(void) const {
	return (_instr);
}

std::string	Token::getType(void) const {
	return (_type);
}

std::string	Token::getValue(void) const {
	return (_value);
}

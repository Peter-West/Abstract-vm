#include "Errors.hpp"

const char * UnderflowError::what() const throw () {
	return ("Error : Underflow");
}

const char * OverflowError::what() const throw () {
	return ("Error : Overflow");
}

const char * EmptyStackError::what() const throw() {
	return ("Error : The Stack is empty");
}

const char * AssertError::what() const throw() {
	return ("Error : Assert");
}

const char * NotEnoughValuesError::what() const throw() {
	return ("Error : Not enough Values");
}
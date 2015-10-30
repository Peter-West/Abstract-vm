#include "Errors.hpp"

const char * FileError::what() const throw () {
	return ("Error : File Error");
}

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

const char * DivByZeroError::what() const throw() {
	return ("Error : Can't divide by Zero");
}

const char * ExitError::what() const throw() {
	return ("Error : No Exit instruction");
}

const char * Int8ArgError::what() const throw() {
	return ("Error : Int8 argument");
}

const char * Int8OverError::what() const throw() {
	return ("Error : Int8 Overflow");
}

const char * Int8UnderError::what() const throw() {
	return ("Error : Int8 Underflow");
}

const char * Int16ArgError::what() const throw() {
	return ("Error : Int16 argument");
}

const char * Int16OverError::what() const throw() {
	return ("Error : Int16 Overflow");
}

const char * Int16UnderError::what() const throw() {
	return ("Error : Int16 Underflow");
}

const char * Int32ArgError::what() const throw() {
	return ("Error : Int32 argument");
}

const char * Int32OverError::what() const throw() {
	return ("Error : Int32 Overflow");
}

const char * Int32UnderError::what() const throw() {
	return ("Error : Int32 Underflow");
}

const char * FloatArgError::what() const throw() {
	return ("Error : Float argument");
}

const char * FloatOverError::what() const throw() {
	return ("Error : Float Overflow");
}

const char * FloatUnderError::what() const throw() {
	return ("Error : Float Underflow");
}

const char * DoubleArgError::what() const throw() {
	return ("Error : Double argument");
}

const char * DoubleOverError::what() const throw() {
	return ("Error : Double Overflow");
}

const char * DoubleUnderError::what() const throw() {
	return ("Error : Double Underflow");
}

#include "Factory.hpp"
#include "Ops.hpp"

static Factory* t_instance;

Factory* Factory::instance() {
	return (t_instance);
}

Factory::Factory() {
	t_instance = this;
	_funct.push_back(&Factory::createInt8);
	_funct.push_back(&Factory::createInt16);
	_funct.push_back(&Factory::createInt32);
	_funct.push_back(&Factory::createFloat);
	_funct.push_back(&Factory::createDouble);
}

Factory::Factory(Factory const & src) {
	*this = src;
}

Factory::~Factory() {
		std::cout << "Factory Destroyed !" << std::endl;
}

Factory &Factory::operator=(Factory const & rhs) {
	*this = rhs;
	return (*this);	
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
	return ((this->*(_funct[type]))(value));
}

IOperand const * Factory::createInt8( std::string const & value ) const {
	return (new Int8(stod(value)));
}

IOperand const * Factory::createInt16( std::string const & value ) const {
	
	return (new Int16(stod(value)));
}

IOperand const * Factory::createInt32( std::string const & value ) const {
	
	return (new Int32(stod(value)));
}

IOperand const * Factory::createFloat( std::string const & value ) const {
	
	return (new Float(stod(value)));
}

IOperand const * Factory::createDouble( std::string const & value ) const {
	
	return (new Double(stod(value)));
}
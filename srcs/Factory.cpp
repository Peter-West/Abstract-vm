#include "Factory.hpp"
#include "Ops.hpp"
#include "Errors.hpp"
#include <stdexcept>
#include <climits>
#include <cfloat>
#include <cfenv>

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
		// std::cout << "Factory Destroyed !" << std::endl;
}

Factory &Factory::operator=(Factory const & rhs) {
	*this = rhs;
	return (*this);	
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
	return ((this->*(_funct[type]))(value));
}

IOperand const * Factory::createInt8( std::string const & value ) const {
	double	test;

	std::feclearexcept(FE_OVERFLOW);
	std::feclearexcept(FE_UNDERFLOW);
	test = stod(value);
	if (std::fetestexcept(FE_UNDERFLOW))
		throw UnderflowError();
	if (std::fetestexcept(FE_OVERFLOW))
		throw OverflowError();
	if (test < SCHAR_MIN)
		throw UnderflowError();
	else if (test > SCHAR_MAX)
		throw OverflowError();
	return (new Int8(test));
}

IOperand const * Factory::createInt16( std::string const & value ) const {
	double	test;

	std::feclearexcept(FE_OVERFLOW);
	std::feclearexcept(FE_UNDERFLOW);
	test = stod(value);
	if (std::fetestexcept(FE_UNDERFLOW))
		throw UnderflowError();
	if (std::fetestexcept(FE_OVERFLOW))
		throw OverflowError();
	if (test < SHRT_MIN)
		throw UnderflowError();
	else if (test > SHRT_MAX)
		throw OverflowError();
	return (new Int16(test));
}

IOperand const * Factory::createInt32( std::string const & value ) const {
	
	double	test;

	std::feclearexcept(FE_OVERFLOW);
	std::feclearexcept(FE_UNDERFLOW);
	test = stod(value);
	if (std::fetestexcept(FE_UNDERFLOW))
		throw UnderflowError();
	if (std::fetestexcept(FE_OVERFLOW))
		throw OverflowError();
	if (test < INT_MIN)
		throw UnderflowError();
	else if (test > INT_MAX)
		throw OverflowError();
	return (new Int32(test));
}

IOperand const * Factory::createFloat( std::string const & value ) const {
	double test;

	std::feclearexcept(FE_OVERFLOW);
    std::feclearexcept(FE_UNDERFLOW);
	test = stod(value);
	if (std::fetestexcept(FE_UNDERFLOW))
		throw UnderflowError();
	if (std::fetestexcept(FE_OVERFLOW))
		throw OverflowError();
	if (test < FLT_MIN)
		throw UnderflowError();
	if (test > FLT_MAX)
		throw OverflowError();
	return (new Float(test));
}

IOperand const * Factory::createDouble( std::string const & value ) const {
	double	test;

	std::feclearexcept(FE_OVERFLOW);
    std::feclearexcept(FE_UNDERFLOW);
	test = stod(value);
	if (std::fetestexcept(FE_UNDERFLOW))
		throw UnderflowError();
	if (std::fetestexcept(FE_OVERFLOW))
		throw OverflowError();
	return (new Double(test));
}
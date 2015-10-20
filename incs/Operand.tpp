#ifndef OPERAND_TPP
# define OPERAND_TPP

# include <iostream>
# include <math.h>
# include "IOperand.hpp"
# include "Factory.hpp"

template<typename T>
class Operand : public IOperand
{
private:
	T					_value;
	eOperandType		_type;
	std::string			_str;

	Operand<T>(void);
	Operand<T>(Operand<T> const & src);
	Operand<T> & operator=(Operand<T> const & rhs);
	
public:
	Operand<T>(T value, eOperandType type) : _value(value), _type(type), _str(std::to_string(_value)) {
	}
	
	virtual ~Operand<T>(void);

	virtual int getPrecision( void ) const {
		return (_type);
	}

	virtual eOperandType getType( void ) const {
		return (_type);
	}

	virtual T getValue( void ) const {
		return (_value);
	}

	virtual IOperand const * operator+( IOperand const & rhs ) const {
		eOperandType type =  (getPrecision() < rhs.getPrecision()) ? rhs.getType() : _type;
		return Factory::instance()->createOperand(type, std::to_string(this->_value + std::stod(rhs.toString())));
	}

	virtual IOperand const * operator-( IOperand const & rhs ) const {
		eOperandType type =  (getPrecision() < rhs.getPrecision()) ? rhs.getType() : _type;
		return Factory::instance()->createOperand(type, std::to_string(this->_value - std::stod(rhs.toString())));
	}

	virtual IOperand const * operator*( IOperand const & rhs ) const {
		eOperandType type =  (getPrecision() < rhs.getPrecision()) ? rhs.getType() : _type;
		return Factory::instance()->createOperand(type, std::to_string(this->_value * std::stod(rhs.toString())));
	}

	virtual IOperand const * operator/( IOperand const & rhs ) const {
		eOperandType type =  (getPrecision() < rhs.getPrecision()) ? rhs.getType() : _type;
		return Factory::instance()->createOperand(type, std::to_string(this->_value / std::stod(rhs.toString())));
	}

	virtual IOperand const * operator%( IOperand const & rhs ) const {
		std::string	res;
		eOperandType type =  (getPrecision() < rhs.getPrecision()) ? rhs.getType() : _type;
		res = std::to_string(fmod(this->_value, std::stod(rhs.toString())));
		return Factory::instance()->createOperand(type, res);
	}

	virtual std::string const & toString( void ) const {
		return _str;
	}
};

#endif
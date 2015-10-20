#ifndef FACTORY_HPP
# define FACTORY_HPP

# include <iostream>
# include <vector>
# include "IOperand.hpp"

class Factory;

typedef IOperand const * (Factory::*funct)(std::string const &)const;

class Factory
{
public:
	Factory();
	Factory(std::vector<std::string> instructions, std::vector<std::string> values);
	Factory(Factory const & src);
	~Factory();
	Factory		&operator=(Factory const & rhs);

	std::vector<std::string>	instructions;
	std::vector<std::string>	values;
	static Factory* instance();
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
	std::vector<funct>			_funct;	

	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
};

#endif
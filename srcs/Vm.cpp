#include "Vm.hpp"
#include <cstdlib>
#include <vector>
#include "Errors.hpp"
#include "parse.hpp"
#include "Ops.hpp"

// Vm::Vm() {
// }

Vm::Vm() {
	vmt = new std::vector<IOperand const *>();
	
		_typeMap["int8"] = INT8;
		_typeMap["int16"] = INT16;
		_typeMap["int32"] = INT32;
		_typeMap["float"] = FLOAT;
		_typeMap["double"] = DOUBLE;

		_functInstr["push"] = &Vm::push;
		_functInstrNoArgs["pop"] = &Vm::pop;
		_functInstr["assert"] = &Vm::assert;
		_functInstrNoArgs["dump"] = &Vm::dump;
		_functInstrNoArgs["add"] = &Vm::add;
		_functInstrNoArgs["sub"] = &Vm::sub;
		_functInstrNoArgs["mul"] = &Vm::mul;
		_functInstrNoArgs["div"] = &Vm::div;
		_functInstrNoArgs["mod"] = &Vm::mod;
		_functInstrNoArgs["exit"] = &Vm::exit;
		_functInstrNoArgs["print"] = &Vm::print;
}

Vm::Vm(Vm const &src) {
	*this = src;
}

Vm	&Vm::operator=(Vm const & rhs) {
	*this = rhs;
	return (*this);
}

Vm::~Vm() {

}

void	Vm::push(IOperand const * io){
	vmt->push_back(io);
}

void	Vm::pop(){
	if (vmt->empty())
		throw EmptyStackError();
	else
		vmt->pop_back();
}

void	Vm::dump(){
	std::vector<IOperand const *>::reverse_iterator it;

	for (it = vmt->rbegin(); it != vmt->rend(); ++it) {
		std::cout<< (*it)->toString() << std::endl;
	}
}

void	Vm::assert(IOperand const * io){
	if (vmt->empty() || vmt->back()->getType() != io->getType() || vmt->back()->toString() != io->toString() )
		throw AssertError();
}

void	Vm::add(){
	IOperand const *nb0;
	IOperand const *nb1;

	if (vmt->empty() || (vmt->size() < 2))
		throw NotEnoughValuesError();
	nb1 = vmt->back();
	vmt->pop_back();
	nb0 = vmt->back();
	vmt->pop_back();
	vmt->push_back(*nb0 + *nb1);
	delete nb0;
	delete nb1;
}

void	Vm::sub(){
	IOperand const *nb0;
	IOperand const *nb1;

	if (vmt->empty() || (vmt->size() < 2))
		throw NotEnoughValuesError();
	nb1 = vmt->back();
	vmt->pop_back();
	nb0 = vmt->back();
	vmt->pop_back();
	vmt->push_back(*nb0 - *nb1);
	delete nb0;
	delete nb1;
}

void	Vm::mul(){
	IOperand const *nb0;
	IOperand const *nb1;

	if (vmt->empty() || (vmt->size() < 2))
		throw NotEnoughValuesError();
	nb1 = vmt->back();
	vmt->pop_back();
	nb0 = vmt->back();
	vmt->pop_back();
	vmt->push_back(*nb0 * *nb1);
	delete nb0;
	delete nb1;
}

void	Vm::div(){
	IOperand const *nb0;
	IOperand const *nb1;

	if (vmt->empty() || (vmt->size() < 2))
		throw NotEnoughValuesError();
	nb1 = vmt->back();
	vmt->pop_back();
	nb0 = vmt->back();
	vmt->pop_back();
	vmt->push_back(*nb0 / *nb1);
	delete nb0;
	delete nb1;
}

void	Vm::mod(){
	IOperand const *nb0;
	IOperand const *nb1;

	if (vmt->empty() || (vmt->size() < 2))
		throw NotEnoughValuesError();
	nb1 = vmt->back();
	vmt->pop_back();
	nb0 = vmt->back();
	vmt->pop_back();
	vmt->push_back(*nb0 % *nb1);
	delete nb0;
	delete nb1;
}

void	Vm::print(){
	if (vmt->empty())
		throw EmptyStackError();
	if (vmt->back()->getType() != INT8)
		throw AssertError();
	std::cout<<static_cast<Int8 const *>(vmt->back())->getValue();
}

void	Vm::exit(void){
	std::exit(EXIT_SUCCESS);
}


void	Vm::exec(std::vector<Token> &listInstr)
{
	Factory		f;

	for (std::vector<Token>::iterator it = listInstr.begin(); it != listInstr.end(); ++it) {
		if (_functInstr.find(it->getInstr()) != _functInstr.end()) {
			// std::cout << it->getInstr() << " " <<  it->getType() << " " << it->getValue() << std::endl;
			(this->*_functInstr[it->getInstr()])(f.createOperand(Vm::_typeMap[it->getType()], it->getValue()));
		}
		else if (_functInstrNoArgs.find(it->getInstr()) != _functInstrNoArgs.end()) {
			// std::cout << it->getInstr() << std::endl;
			(this->*_functInstrNoArgs[it->getInstr()])();
			// (this->*(_functionInstruction[it->name]))(*it);

		}
		/*if (!(it->getType()).empty())
			std::cout << it->getInstr() << " args : " <<  it->getType() << ", " << it->getValue() << std::endl;
		else
			std::cout << it->getInstr() << std::endl;*/
	}
	throw ExitError();
}

/*
void	Vm::exec(std::vector<Token> & vt)
{
	Factory						 f;
	std::vector<Token>::iterator it;

	for (it = vt.begin(); it != vt.end(); ++it)
	{
		if (Parser::instrNoArg.find((*it).getInstr()) != Parser::instrNoArg.end())
		{
			if (this->verb)
				std::cout << (*it).getInstr() << std::endl;
			(this->*Parser::instrNoArg[(*it).getInstr()])();
		}
		else if (Parser::instrWithArg.find((*it).getInstr()) != Parser::instrWithArg.end())
		{
			if (this->verb)
				std::cout << (*it).getType() << " " << (*it).getValue()  << std::endl;
			(this->*Parser::instrWithArg[(*it).getInstr()])(f.createOperand(Parser::typeResolver[(*it).getType()], (*it).getValue()));
		}
		else
			throw UnknownCommandError();
	}
	throw ExitError();
}


*/











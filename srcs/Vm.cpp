#include "Vm.hpp"
#include <cstdlib>
#include <vector>

Vm::Vm() {
}

Vm::Vm(std::vector<Token> *listInstr) {
	vmt = new std::vector<IOperand const *>();
	std::map<std::string, eOperandType> _typeMap = {
		{"int8", INT8},
		{"int16", INT16},
		{"int32", INT32},
		{"float", FLOAT},
		{"double", DOUBLE}
	};

	std::map<std::string, functInstr>	_functInstr = {
		{"push"], &Vm::push},
		{"pop"], &Vm::pop},
		{"assert"], &Vm::assert},
		{"dump"], &Vm::dump},
		{"add"], &Vm::add},
		{"sub"], &Vm::sub},
		{"mul"], &Vm::mul},
		{"div"], &Vm::div},
		{"mod"], &Vm::mod},
		{"exit"], &Vm::exit},
		{"print"], &Vm::print}
	};
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
	std::vector<IOperand const *>reverse_iterator it;

	for (it = vmt->rbegin(); it != vmt->rend(); ++it) {
		std::cout<< it->to_string() << std::endl;
	}
}

void	Vm::assert(IOperand const * io){
	if (vmt->empty() || vmt->st->back()->getType() != io->getType() || vmt->st->back()->getValue() != io->getValue() )
		throw AssertError();
}

void	Vm::add(){
	IOperand const *nb0;
	IOperand const *nb1;

	if (vmt->empty() || (vmt->size() < 2))
		throw NotEnoughValuesError();
	nb0 = vmt->back();
	vmt->pop_back();
	nb1 = vmt->back();
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
	nb0 = vmt->back();
	vmt->pop_back();
	nb1 = vmt->back();
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
	nb0 = vmt->back();
	vmt->pop_back();
	nb1 = vmt->back();
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
	nb0 = vmt->back();
	vmt->pop_back();
	nb1 = vmt->back();
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
	nb0 = vmt->back();
	vmt->pop_back();
	nb1 = vmt->back();
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
	std::cout<<vmt->back()->to_string()<<std::endl;
}

void	Vm::exit(void){
	std::exit(EXIT_SUCCESS);
}


void	Vm::exec(std::vector<Token> *listInstr)
{
	Factory		f;
	Token		*tmpInstr;

	for (std::vector<Token>::iterator it = listInstr->begin(); it != listInstr->end(); ++it) {
		tmpInstr = *it;
		if (it->getInstr() == "push" || it->getInstr() == "assert") {
			f.createOperand(Vm::_typeMap[it->getType()], it->getValue())
		}
		/*if (!(it->getType()).empty())
			std::cout << it->getInstr() << " args : " <<  it->getType() << ", " << it->getValue() << std::endl;
		else
			std::cout << it->getInstr() << std::endl;*/
	}
}


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
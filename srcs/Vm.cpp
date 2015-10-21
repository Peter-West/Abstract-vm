#include "Vm.hpp"
#include <cstdlib>
#include <vector>

Vm::Vm() {
	
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

void	Vm::push(){

}

void	Vm::pop(){

}

void	Vm::dump(){

}

void	Vm::assert(){

}

void	Vm::add(){

}

void	Vm::sub(){

}

void	Vm::mul(){

}

void	Vm::div(){

}

void	Vm::mod(){

}

void	Vm::print(){

}

void	Vm::exit(void){
	std::exit(EXIT_SUCCESS);
}

void	Vm::exec(std::vector<Token> *listInstr)
{
	for (std::vector<Token>::iterator it = listInstr->begin(); it != listInstr->end(); it++) {
		if (!(it->getType()).empty())
			std::cout << it->getInstr() << " args : " <<  it->getType() << ", " << it->getValue() << std::endl;
		else
			std::cout << it->getInstr() << std::endl;
	}
}

#ifndef VM_HPP
# define VM_HPP

#include <vector>
#include <iostream>
#include "Token.hpp"

class Vm {
	private:
		Vm();
		Vm(Vm const &src);
		Vm &operator=(Vm const & rhs);
		Vm(std::vector<Token> *listInstr);
		std::vector<IOperand const *> *vmt;

		std::map<std::string, eOperandType>	_typeMap;
		std::map<std::string, functInstr>	_functInstr;


	public: 
		~Vm();
		void	push();
		void	pop();
		void	dump();
		void	assert();
		void	add();
		void	sub();
		void	mul();
		void	div();
		void	mod();
		void	print();
		void	exit(void);
		void	exec(std::vector<Token>*);
	};


#endif
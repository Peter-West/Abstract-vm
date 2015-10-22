#ifndef VM_HPP
# define VM_HPP

#include <vector>
#include <iostream>
#include <map>
#include "Token.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"

class Vm {
	private:
		Vm(Vm const &src);
		Vm &operator=(Vm const & rhs);
		std::vector<IOperand const *> *vmt;

		typedef void (Vm::*functInstr)(IOperand const *);
		typedef void (Vm::*functInstrNoArgs)(void);

		std::map<std::string, eOperandType>	_typeMap;
		std::map<std::string, functInstr>	_functInstr;
		std::map<std::string, functInstrNoArgs>	_functInstrNoArgs;


	public: 
		Vm();
		~Vm();
		void	push(IOperand const * io);
		void	pop(void);
		void	dump(void);
		void	assert(IOperand const * io);
		void	add(void);
		void	sub(void);
		void	mul(void);
		void	div(void);
		void	mod(void);
		void	print(void);
		void	exit(void);
		void	exec(std::vector<Token> &);
	};


#endif
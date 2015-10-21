#ifndef VM_HPP
# define VM_HPP

#include <vector>
#include <iostream>
#include "Token.hpp"

class Vm {
	private:
		Vm(Vm const &src);
		Vm &operator=(Vm const & rhs);

	public: 
		Vm();
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
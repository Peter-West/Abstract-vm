#ifndef VM_HPP
# define VM_HPP

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
	};


#endif
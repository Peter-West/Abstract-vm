#include "parse.hpp"
#include "Factory.hpp"
#include "Ops.hpp"
#include <stdlib.h>

int main(int argc, char **argv)
{
	parse		*P;

	if (argc == 2) {
		P = new parse(argv[1]);
		// F = new Factory(P->instructions, P->values);
	}
	else if (argc == 1)
		P = new parse();
	else {
		std::cout<<"Error : Wrong usage "<<std::endl;
		exit(0);
	}
	delete(P);
	return (0);
}
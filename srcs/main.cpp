#include "parse.hpp"
#include "Factory.hpp"
#include "Ops.hpp"
#include "Vm.hpp"
#include <stdlib.h>
#include <stdexcept>

int main(int argc, char **argv)
{
	parse		*P;
	Vm			*VirM;

	try
	{
		if (argc == 2) {
			P = new parse(argv[1]);
			VirM = new Vm();
			VirM->exec(*P->vecTok);
		}
		else if (argc == 1)
			P = new parse();
		else {
			std::cout<<"Error : Wrong usage "<<std::endl;
			exit(0);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete(P);
	return (0);
}
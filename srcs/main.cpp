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
		if (argc == 3 && argv[1][0] == '-' && argv[1][1] == 'v' && argv[1][2] == '\0') {
			P = new parse(argv[2]);
			VirM = new Vm();
			VirM->exec(*P->vecTok, true);
		}
		else if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'v' && argv[1][2] == '\0') {
			P = new parse();
			VirM = new Vm();
			VirM->exec(*P->vecTok, true);
		}
		else if (argc == 2) {
			P = new parse(argv[1]);
			VirM = new Vm();
			VirM->exec(*P->vecTok, false);
		}
		else if (argc == 1) {
			P = new parse();
			VirM = new Vm();
			VirM->exec(*P->vecTok, false);
		}
		else {
			std::cout<<"usage : [filename]" <<std::endl << "Verbose mode : -v"<<std::endl;
			exit(0);
		}
		if (P)
			delete(P);
		if (VirM)
			delete(VirM);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
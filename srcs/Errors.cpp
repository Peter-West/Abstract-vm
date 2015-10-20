#include "Errors.hpp"

const char * UnderflowError::what() const throw ()
{
	return ("Error : Underflow");
}

const char * OverflowError::what() const throw ()
{
	return ("Error : Overflow");
}
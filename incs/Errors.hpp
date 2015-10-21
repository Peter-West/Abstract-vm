#ifndef ERRORS_HPP
# define ERRORS_HPP

# include <exception>
# include <string>

class UnderflowError : public std::exception {
	virtual const char* what() const throw ();
};

class OverflowError : public std::exception {
	virtual const char* what() const throw ();
};

class EmptyStackError : public std::exception {
	virtual const char* what() const throw ();
};

class AssertError : public std::exception {
	virtual const char* what() const throw ();
};

class NotEnoughValuesError : public std::exception {
	virtual const char* what() const throw ();
};

#endif
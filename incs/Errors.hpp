#ifndef ERRORS_HPP
# define ERRORS_HPP

# include <exception>
# include <string>

class FileError : public std::exception {
	virtual const char* what() const throw ();
};

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

class DivByZeroError : public std::exception {
	virtual const char* what() const throw ();
};

class ExitError : public std::exception {
	virtual const char* what() const throw ();
};

class Int8ArgError : public std::exception {
	virtual const char* what() const throw ();
};

class Int8OverError : public std::exception {
	virtual const char* what() const throw ();
};

class Int8UnderError : public std::exception {
	virtual const char* what() const throw ();
};

class Int16ArgError : public std::exception {
	virtual const char* what() const throw ();
};

class Int16OverError : public std::exception {
	virtual const char* what() const throw ();
};

class Int16UnderError : public std::exception {
	virtual const char* what() const throw ();
};

class Int32ArgError : public std::exception {
	virtual const char* what() const throw ();
};

class Int32OverError : public std::exception {
	virtual const char* what() const throw ();
};

class Int32UnderError : public std::exception {
	virtual const char* what() const throw ();
};

class FloatArgError : public std::exception {
	virtual const char* what() const throw ();
};

class FloatOverError : public std::exception {
	virtual const char* what() const throw ();
};

class FloatUnderError : public std::exception {
	virtual const char* what() const throw ();
};

class DoubleArgError : public std::exception {
	virtual const char* what() const throw ();
};

class DoubleOverError : public std::exception {
	virtual const char* what() const throw ();
};

class DoubleUnderError : public std::exception {
	virtual const char* what() const throw ();
};

#endif

#ifndef OPS_HPP
# define OPS_HPP
	
# include "Operand.tpp"

class Int8 : public Operand <int8_t>
{
	public:
		Int8(int8_t value);
};

class Int16 : public Operand <int16_t>
{
	public:
		Int16(int16_t value);
};

class Int32 : public Operand <int32_t>
{
	public:
		Int32(int value);
};

class Float : public Operand <float>
{
	public:
		Float(float value);
};

class Double : public Operand <double>
{
	public:
		Double(double value);
};

#endif
#include "Ops.hpp"

Int8::Int8(int8_t value) : Operand<int8_t>(value, INT8) {}

Int16::Int16(int16_t value) : Operand<int16_t>(value, INT16) {}

Int32::Int32(int value) : Operand<int>(value, INT32) {}

Float::Float(float value) : Operand<float>(value, FLOAT) {}

Double::Double(double value) : Operand<double>(value, DOUBLE) {}
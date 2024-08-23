#include "ConvertedType.hpp"

ConvertedType::ConvertedType() : m_int(0), m_char(0), m_float(0), m_double(0) {}
ConvertedType::ConvertedType(ConvertedType const &src) : m_int(src.m_int), m_char(src.m_char), m_float(src.m_float), m_double(src.m_double) {}
ConvertedType::~ConvertedType() {}
ConvertedType &ConvertedType::operator=(ConvertedType const &src) {
	if (this != &src) {
		m_int = src.m_int;
		m_char = src.m_char;
		m_float = src.m_float;
		m_double = src.m_double;
	}
	return *this;
}

int ConvertedType::getInt() { return m_int; }
char ConvertedType::getChar() { return m_char; }
float ConvertedType::getFloat() { return m_float; }
double ConvertedType::getDouble() { return m_double; }

void ConvertedType::setInt(int i) { m_int = i; }
void ConvertedType::setChar(char c) { m_char = c; }
void ConvertedType::setFloat(float f) { m_float = f; }
void ConvertedType::setDouble(double d) { m_double = d; }
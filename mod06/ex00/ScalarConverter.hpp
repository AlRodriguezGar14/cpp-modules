#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include <cmath>
#include <limits>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const &src);

	template<typename T>
	static bool ft_isnan(T nbr);
	template<typename T>
	static bool ft_isinf(T nbr);

	template<typename T>
	static bool isChar(const T& t_input);
	template<typename T>
	static void printChar(const T& t_input);
	template<typename T>
	static void printInt(const T& t_input);
	template<typename T>
	static void printFloat(const T& t_input);
	template<typename T>
	static void printDouble(const T& t_input);

	// static bool isChar(const std::string& t_input);
	// static void printChar(const std::string& t_input);
	// static void printInt(const std::string& t_input);
	// static void printFloat(const std::string& t_input);
	// static void printDouble(const std::string& t_input);
public:

	static void convert(std::string const &input);
};


class ConvertedType {
public:
	ConvertedType(): m_int(0), m_char(0), m_float(0.0f), m_double(0.0) {}
	int getInt() const { return m_int; };
	char getChar() const { return m_char; };
	float getFloat() const { return m_float; };
	double getDouble() const { return m_double; };
	
	void setInt(int i) { m_int = i; };
	void setChar(char c) { m_char = c; };
	void setFloat(float f) { m_float = f; };
	void setDouble(double d) { m_double = d; };



private:
	int m_int;
	char m_char;
	float m_float;
	double m_double;
};

#endif

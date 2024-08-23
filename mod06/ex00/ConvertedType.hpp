#ifndef CONVERTED_TYPE_HPP
#define CONVERTED_TYPE_HPP

class ConvertedType {
public:
	ConvertedType();
	ConvertedType(ConvertedType const &src);
	~ConvertedType();
	ConvertedType &operator=(ConvertedType const &src);
	int getInt();
	char getChar();
	float getFloat();
	double getDouble();
	
	void setInt(int i);
	void setChar(char c);
	void setFloat(float f);
	void setDouble(double d);

private:
	int m_int;
	char m_char;
	float m_float;
	double m_double;
};
#endif

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
private:
	std::string m_data;
public:
	Data(std::string t_data);
	Data(const Data& t_data);
	Data& operator = (const Data& t_data);
	~Data();
	std::string getData();
};

#endif

#include "Data.hpp"

Data::Data(std::string t_data) : m_data(t_data) {}
Data::Data(const Data& t_data) : m_data(t_data.m_data) {}
Data& Data::operator = (const Data& t_data) {
	if (this != &t_data) {
		m_data = t_data.m_data;
	}
	return *this;
}
Data::~Data() {}

std::string Data::getData() {
	return m_data;
}

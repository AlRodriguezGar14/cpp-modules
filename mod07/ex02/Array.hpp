#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array {
private:
	T* m_data;
	unsigned int m_len;
public:
	Array() : m_data(NULL), m_len(0) {};
	Array(unsigned int t_n) : m_data(new T[t_n]), m_len(t_n) {
		for (unsigned int i = 0; i < m_len; ++i) {
			m_data[i] = T();
		}
	};
	Array(const Array<T>& t_arr) : m_data(new T[t_arr.m_len]), m_len(t_arr.m_len) {
		for (unsigned int i = 0; i < m_len; ++i) {
			m_data[i] = t_arr.m_data[i];
		}
	}
	Array operator = (const Array<T>& t_arr) {
		if (this == &t_arr) {
			return *this;
		}
		delete[] m_data;
		m_data = new T[t_arr.m_len];
		m_len = t_arr.m_len;
		for (unsigned int i = 0; i < m_len; ++i) {
			m_data[i] = t_arr.m_data[i];
		}
		return *this;
	}
	~Array() {
		delete[] m_data;
	};

	unsigned int size() const {
		return m_len;
	}

	T& operator [] (unsigned int t_i) {
		if (t_i >= m_len) {
			throw std::out_of_range("Index out of range");
		}
		return m_data[t_i];
	}
};

template<typename T>
std::ostream& operator << (std::ostream &os, Array<T> &t_arr) {

	unsigned int size = t_arr.size();
	os << "[";
	for (unsigned int i = 0; i < size; ++i) {
		if (i == size - 1) {
			os << t_arr[i];
			break;
		}
		os << t_arr[i] << ", ";
	}
	os << "]";
	return os;
}

#endif

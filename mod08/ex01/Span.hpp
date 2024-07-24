#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <exception>


class Span {
private:
	unsigned int m_size;
	std::vector<int> m_data;
public:
	Span(unsigned int t_size);
	Span(const Span& t_span);
	Span& operator=(const Span& t_span);
	~Span();

	void addNumber(int t_nbr);
	int shortestSpan();
	int longestSpan();
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif

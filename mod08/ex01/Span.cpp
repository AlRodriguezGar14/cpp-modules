#include "Span.hpp"

Span::Span(unsigned int t_size) : m_size(t_size) { m_data.reserve(m_size);};
Span::Span(const Span& t_span) : m_size(t_span.m_size), m_data(t_span.m_data) {};
Span& Span::operator=(const Span& t_span) {
	m_size = t_span.m_size;
	m_data = t_span.m_data;
	return *this;
}
Span::~Span() {};

void Span::addNumber(int t_nbr) {
	if (m_data.size() == m_size) {
		throw std::runtime_error("Can't store more values");
	}
	m_data.push_back(t_nbr);
}

int Span::longestSpan() {
	if (m_data.size() < 2)
		throw std::runtime_error("Not enough values to compare");

	std::vector<int> sorted = m_data;
	std::sort(sorted.begin(), sorted.end());
	return (sorted.back() - sorted.front());
}

int Span::shortestSpan() {
	if (m_data.size() < 2)
		throw std::runtime_error("Not enough values to compare");

	int threshold = std::numeric_limits<int>::max();
	std::vector<int> sorted = m_data;
	std::sort(sorted.begin(), sorted.end());
	for (size_t i = 0; i < sorted.size() - 1; ++i) {
		if (sorted.at(i + 1) - sorted.at(i) < threshold) {
			threshold = sorted.at(i + 1) - sorted.at(i);
		}
	}
	return threshold;
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) > static_cast<long>(m_size - m_data.size())) {
		throw std::runtime_error("Not enough space to copy");
	}
	m_data.insert(m_data.begin() + m_data.size(), begin, end);
}

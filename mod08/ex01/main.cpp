#include "Span.hpp"

#include <ctime>
#include <cstdlib>
#include <numeric>

int main() {
	try {
		Span sp = Span(5);
		sp.addNumber(11);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\nTest with the 10k numbers, all at once:" << std::endl;
	try {

		std::vector<int> vec(15000);
		std::iota(vec.begin(), vec.end(), 1);

		Span improved = Span(10000);
		improved.addNumber(vec.begin(), vec.end() - 5000);

		std::cout << "Improved span: shortest: " << improved.shortestSpan() << std::endl; 
		std::cout << "Improved span: longest: " << improved.longestSpan() << std::endl; 

	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nTest to display that the Span class works properly with the .insert copy" << std::endl;
		std::vector<int> vec;
		vec.push_back(11);
		vec.push_back(3);
		vec.push_back(6);
		vec.push_back(17);
		vec.push_back(9);
		Span spp = Span(6);
		spp.addNumber(42);
		spp.addNumber(vec.begin(), vec.end());
		std::cout << spp.shortestSpan() << std::endl;
		std::cout << spp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	std::cout << "\nTest with the 10k numbers, all at once, but now it crashes:" << std::endl;
	try {

		std::vector<int> vec(15000);
		std::iota(vec.begin(), vec.end(), 1);

		Span improved = Span(10000);
		improved.addNumber(vec.begin(), vec.end());

	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\nCrash: too many values" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(11);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(42);
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\nCrash: not enough values" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;

}
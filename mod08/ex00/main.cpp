#include "easyfind.hpp"
#include <vector>
#include <string>

int main() {

	std::vector<int> vec;

	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);

	try {
		std::cout << "found: " << easyfind(vec, 8) << std::endl;
		std::cout << "found: " << easyfind(vec, 10) << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

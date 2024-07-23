#include "iter.hpp"

int main(void) {

	char array[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "Before:" << std::endl;
	::iter(array, 5, ::printValue);
	::iter(array, 5, ::updateValue);
	std::cout << "After:" << std::endl;
	::iter(array, 5, ::printValue);
}

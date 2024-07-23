#include "Array.hpp"

int main() {
	Array<std::string> arr1(5);
	Array<std::string> arr2(5);
	Array<int> arr3(5);
	Array<int> arr;

	try {
		std::cout << arr.size() << std::endl;

		arr1[0] = "Hello";
		arr1[1] = "World";
		std::cout << arr1.size() << std::endl;
		arr2 = arr1;
		std::cout << arr2[0] << " " << arr1[1] << std::endl;
		arr2[0] = "Goodbye";
		std::cout << arr1 << std::endl;
		std::cout << arr2 << std::endl;
		std::cout << arr3 << std::endl;

		std::cout << arr[0] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
T updateValue(T operand) {
	return operand + 1;
}

template<typename T>
T printValue(T operand) {
	std::cout << operand << std::endl;
	return operand;
}

template<typename T>
void	iter(T *array, int len, T (*func)(T)) {
	for (int i = 0; i < len; ++i) {
		array[i] = func(array[i]);
	}
}

#endif

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>

template<typename T>
int easyfind(T &container, int find) {
	for (typename T::iterator it = std::begin(container); it != std::end(container); ++it) {
		if (*it == find)
			return *it;
	}
	throw::std::invalid_argument("The value is not in the container");
}


#endif

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>

// Won't work with strings due to the operator ==
// <template < template <typename> <typename T> <- is part of C++11 and over
// int easyfind (T<int> &container...)
template<typename T>
int easyfind(T &container, int find) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		if (*it == find)
			return *it;
	}
	throw::std::invalid_argument("The value is not in the container");
}


#endif

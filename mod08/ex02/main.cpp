#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "begin: " << *it << std::endl;
}
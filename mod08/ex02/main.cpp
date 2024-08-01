#include "MutantStack.hpp"
#include <iostream>
#include <cassert>
#include <vector>

int main() {

	// basic functionality
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    assert(mstack.top() == 3);
    std::cout << "Top element after 3 pushes: " << mstack.top() << std::endl;
    mstack.pop();
    assert(mstack.top() == 2);
    std::cout << "Top element after 1 pop: " << mstack.top() << std::endl;
    mstack.pop();
    assert(mstack.top() == 1);
    std::cout << "Top element after another pop: " << mstack.top() << std::endl;
    mstack.pop();
    assert(mstack.empty());
    std::cout << "Stack is empty after popping all elements." << std::endl;

    // iterator
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::vector<int> values;
    while (it != ite) {
        values.push_back(*it);
        ++it;
    }

    assert(values.size() == 3);
    assert(values[0] == 1);
    assert(values[1] == 2);
    assert(values[2] == 3);
    std::cout << "Values in stack using iterator: ";
	for (std::vector<int>::iterator it = values.begin(); it != values.end(); ++it) {
		std::cout << *it << " ";
	}
    std::cout << std::endl;

    // const iterator
    const MutantStack<int> constMstack(mstack);
    MutantStack<int>::const_iterator cit = constMstack.begin();
    MutantStack<int>::const_iterator cite = constMstack.end();

    values.clear();
    while (cit != cite) {
        values.push_back(*cit);
        ++cit;
    }

    assert(values.size() == 3);
    assert(values[0] == 1);
    assert(values[1] == 2);
    assert(values[2] == 3);
    std::cout << "Values in const stack using const iterator: ";
	for (std::vector<int>::iterator it = values.begin(); it != values.end(); ++it) {
		std::cout << *it << " ";
	}
    std::cout << std::endl;

    // edge cases
    MutantStack<int> emptyStack;

    assert(emptyStack.begin() == emptyStack.end());
    std::cout << "Empty stack begin() == end(): " << (emptyStack.begin() == emptyStack.end()) << std::endl;

    return 0;
}
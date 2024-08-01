#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() {};	
		MutantStack(MutantStack const& t_mutantStack) : std::stack<T>(t_mutantStack) {};
		MutantStack& operator=(MutantStack const& t_mutantStack) { 
			if (this != &t_mutantStack)
				this->m_stack = t_mutantStack.m_stack;
			return *this;
		 };
		~MutantStack() {};


		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return std::stack<T>::c.begin(); };
		iterator end() { return std::stack<T>::c.end(); };

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const { return std::stack<T>::c.begin(); };
		const_iterator end() const { return std::stack<T>::c.end(); };

};


#endif
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack {
	private:
		std::stack<T> m_stack;
	public:
		MutantStack() {};	
		MutantStack(MutantStack const& t_MutantStack) { *this = t_MutantStack; };
		MutantStack& operator=(MutantStack const& t_MutantStack) { m_stack = t_MutantStack.m_stack; return *this; };
		~MutantStack() {};

		void empty() { m_stack.empty(); };
		void pop(T t_value) { m_stack.pop(t_value); };
		void push(T t_value) { m_stack.push(t_value); };
		size_t size() { return m_stack.size(); };
		T& top() { return m_stack.top(); };



};


#endif
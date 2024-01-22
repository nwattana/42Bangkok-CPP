#pragma once
#include <stack>
#include <iostream>
#include <deque>
#include <iterator>

template<
    class T,
    class Container = std::deque<T>
>
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() : std::stack<T, Container>(){};
		MutantStack(const MutantStack &other) : std::stack<T, Container>()
		{
			*this = other;
		};
		~MutantStack(){};
		MutantStack& operator=(const MutantStack &other)
		{
			std::stack<T, Container>::operator=(other);
			return this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return (std::stack<T>::c.begin()); }
		iterator end() { return (std::stack<T>::c.end()); }
};
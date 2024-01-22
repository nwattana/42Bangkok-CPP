#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <deque>
#include "MutantStack.hpp"
// int main()
// {

// 	// push 5 to stack
// 	// push 17 to stack
// 	// print top stack
// 	// pop top stack
// 	// print size
// 	// push 3 to stack
// 	// push 5 to stack
// 	// push 7 to stack
// 	// create iterator start
// 	// create iterator end

// 	// เลื่อน iterator ไปที่ตำแหน่งที่ 1
// 	// ++it
// 	// เลื่อน iterator ไปที่ตำแหน่งที่ 0
// 	// --it

//  Loop print ทุกตัว ใน container

// 	// constructor copy to stack
// 	// std::stack<int> s(stack);

// 	return 0;
// }

void test_mutant(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack size = " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(7);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	MutantStack<int>::iterator it_temp;
	// MutantStack<int>::iterator ite = mstack.end();
	it_temp = it;
	++it;
	--it;
	if (*it_temp != *it)
	{
		std::cout << *it_temp << std::endl;
		std::cout << *it << std::endl;
		throw std::invalid_argument("Not Equal");
	}
	while (it != ite)
	{
		std::cout << *it << " " << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void test_mutant_string(void)
{
	MutantStack<std::string> mstack;
	mstack.push("5");
	mstack.push("17");
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack size = " << mstack.size() << std::endl;
	mstack.push("3");
	mstack.push("5");
	mstack.push("7");
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator ite = mstack.end();
	MutantStack<std::string>::iterator it_temp;
	// MutantStack<int>::iterator ite = mstack.end();
	it_temp = it;
	++it;
	--it;
	if (*it_temp != *it)
	{
		std::cout << *it_temp << std::endl;
		std::cout << *it << std::endl;
		throw std::invalid_argument("Not Equal");
	}
	while (it != ite)
	{
		std::cout << *it << " " << std::endl;
		++it;
	}
	std::stack<std::string> s(mstack);
}

void test_list(void)
{
	typedef typename std::list<int> list;
	list sl;

	sl.push_front(5);
	sl.push_front(17);
	std::cout << sl.front() << std::endl;
	sl.erase(sl.begin());
	std::cout << "List size = " << sl.size() << std::endl;
	sl.push_front(3);
	sl.push_front(5);
	sl.push_front(7);

	list::iterator it = sl.begin();
	list::iterator ite = sl.end();
	list::iterator it_temp = it;

	++it;
	--it;
	if (*it_temp != *it)
	{
		std::cout << *it_temp << std::endl;
		std::cout << *it << std::endl;
		throw std::invalid_argument("Iterator list not Equal");
	}
	while (it != ite)
	{
		std::cout << *it << " " << std::endl;
		++it;
	}
	// std::stack<int> s(sl); // stack not adapt from list
}

void test_vector(void)
{
	typedef typename std::vector<int> vec;
	vec v;
	v.push_back(5);
	v.push_back(17);
	std::cout << v.back() << std::endl;
	v.pop_back();
	std::cout << "vector size = " << v.size() << std::endl;
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	vec::iterator it = v.begin();
	vec::iterator ite = v.end();
	vec::iterator it_temp = it;

	++it;
	--it;
	if (*it_temp != *it)
	{
		std::cout << *it_temp << std::endl;
		std::cout << *it << std::endl;
		throw std::invalid_argument("Iterator vector not Equal");
	}
	while (it != ite)
	{
		std::cout << *it << " " << std::endl;
		++it;
	}
	// std::stack<int> s(v);
}

void test_deque(void)
{
	typedef typename std::deque<int> deq;
	deq dq;
	dq.push_back(5);
	dq.push_back(17);
	std::cout << dq.back() << std::endl;
	dq.pop_back();
	std::cout << "deque size = " << dq.size() << std::endl;
	dq.push_back(3);
	dq.push_back(5);
	dq.push_back(7);

	deq::iterator it = dq.begin();
	deq::iterator ite = dq.end();
	deq::iterator it_temp = it;

	++it;
	--it;
	if (*it_temp != *it)
	{
		std::cout << *it_temp << std::endl;
		std::cout << *it << std::endl;
		throw std::invalid_argument("Iterator deque not Equal");
	}
	while (it != ite)
	{
		std::cout << *it << " " << std::endl;
		++it;
	}
	std::stack<int> s(deq);
}

int main()
{
	std::cout << "=============Deque=============" << std::endl;
	test_deque();
	std::cout << "=============List============" << std::endl;
	test_list();
	std::cout << "=========Mutant<int>========" << std::endl;
	test_mutant();
	std::cout << "=========Mutant<str>========" << std::endl;
	test_mutant_string();
	std::cout << "==========Vector===========" << std::endl;
	test_vector();
	std::cout << "======================" << std::endl;
	return (0);
}

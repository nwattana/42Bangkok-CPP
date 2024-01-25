#pragma once

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <iterator> // std advance std::distance
#include <sys/time.h>
class PmergeMe
{
private:
	std::list<int> _list;
	std::vector<int> _vec;
	std::vector<int> _original;

	double time_vec;
	double time_list;

public:
	PmergeMe();
	~PmergeMe();

	void peek_front(int amount);
	void push_back(int i);
	void try_sort_list();

	void sorted(void);
	void report(int limit);
};

template <typename T>
bool isSorted(const T& container) {
    typename T::const_iterator next = container.begin();
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        ++next;
        if (next != container.end() && *it > *next) {
            return false;
        }
    }
    return true;
}
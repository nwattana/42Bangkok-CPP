#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::push_back(int i)
{
	_list.push_back(i);
	_vec.push_back(i);
}

void printVector(const std::vector<int> &vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << ",";
	}
}

void PmergeMe::peek_front(int amount)
{
	std::list<int>::iterator it = _list.begin();
	std::vector<int>::iterator it2 = _vec.begin();
	int i = 0;

	std::cout << "list <int> : ";
	while (it != _list.end() && i < amount)
	{
		std::cout << *it << "\t";
		it++;
		i++;
	}
	if (it != _list.end())
		std::cout << "[...]";
	std::cout << std::endl;
	std::cout << "vec <int>  : ";
	i = 0;
	while (it2 != _vec.end() && i < amount)
	{
		std::cout << *it2 << "\t";
		it2++;
		i++;
	}
	if (it2 != _vec.end())
		std::cout << "[...]";
	std::cout << std::endl;
}

void PmergeMe::try_sort_list()
{
	this->peek_front(1);
}

void insertionSortV(std::vector<int>::iterator a, std::vector<int>::iterator b)
{
	std::vector<int> arr(a, b);
	std::vector<int>::iterator it;

	for (std::vector<int>::iterator current = ++arr.begin(); current != arr.end(); ++current)
	{
		int key = *current;
		std::vector<int>::iterator previous = current;
		--previous;

		while (previous != arr.end() && *previous > key)
		{
			std::vector<int>::iterator next = previous;
			++next;
			*next = *previous;
			if (previous != arr.begin())
				--previous;
			else
				break;
		}
		std::vector<int>::iterator next = previous;
		if (previous == arr.begin() && *previous > key)
			*previous = key;
		else
			*++next = key;
	}
	it = arr.begin();
	// printVector(arr);
	while (a != b)
	{
		*a = *it;
		a++;
		it++;
	}
}

void insertionSortL(std::list<int> &arr)
{
	for (std::list<int>::iterator current = ++arr.begin(); current != arr.end(); ++current)
	{
		int key = *current;
		std::list<int>::iterator previous = current;
		--previous;

		while (previous != arr.end() && *previous > key)
		{
			std::list<int>::iterator next = previous;
			++next;
			*next = *previous;
			if (previous != arr.begin())
				--previous;
			else
				break;
		}
		std::list<int>::iterator next = previous;
		if (previous == arr.begin() && *previous > key)
			*previous = key;
		else
			*++next = key;
	}
}



void Merge(std::vector<int> &arr, int s, int c_mid, int l)
{
	std::vector<int>::iterator b1 = arr.begin() + s;
	std::vector<int>::iterator b1e = arr.begin() + c_mid;
	std::vector<int>::iterator b2 = arr.begin() + c_mid;
	std::vector<int>::iterator e = arr.begin() + l;
	std::vector<int> temp(b1, e);
	std::vector<int>::iterator temp_i = temp.begin();
	std::vector<int>::iterator d1 = arr.begin() + s;

	int cc = 0;
	if (l - s == 0)
		return;
	while (b1 != b1e && b2 != e)
	{
		if (*b2 < *b1)
		{
			*temp_i = *b2;
			b2++;
			temp_i++;
		}
		else
		{
			*temp_i = *b1;
			b1++;
			temp_i++;
		}
		cc++;
	}

	while (b1 != b1e && temp_i != temp.end())
	{
		*temp_i = *b1;
		b1++;
		temp_i++;
		cc++;
	}
	while (b2 != e && temp_i != temp.end())
	{
		*temp_i = *b2;
		b2++;
		temp_i++;
		cc++;
	}

	for (std::vector<int>::iterator ti = temp.begin(); ti < temp.end(); ti++)
	{
		*d1 = *ti;
		d1++;
	}
}

void MergeSort(std::vector<int> &arr, int s, int m, int l)
{
	int c_mid;
	c_mid = s + (l - s) / 2;
	std::vector<int>::iterator it = arr.begin() + s;
	std::vector<int>::iterator ite = arr.begin() + l;

	if ((l - s) <= 10)
	{
		insertionSortV(it, ite);
		return;
	}
	MergeSort(arr, s, c_mid, c_mid);
	MergeSort(arr, c_mid, c_mid, l);
	Merge(arr, s, c_mid, l);
}

void PmergeMe::sorted(void)
{
	// mergeSort(this->_vec, 0, this->_vec.size());
	// insertionSortV(this->_vec);
	// insertionSortL(this->_list);
	// mergeSort(this->_list);
	// insertionSortV(this->_vec);

	MergeSort(this->_vec, 0, this->_vec.size() / 2, this->_vec.size());
	if (isSorted(this->_vec))
	{
		std::cout << "\nSuccess " << std::endl;
	}
	else
	{
		std::cout << "\nfail" << std::endl;
	}
}
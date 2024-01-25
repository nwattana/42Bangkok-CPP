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
	_original.push_back(i);
}

void printVector(const std::vector<int> &vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << ",";
	}
	std::cout << std::endl;
}

void printList(const std::list<int> &lst)
{
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << ",";
	}
	std::cout << std::endl;
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

void MergeSort(std::vector<int> &arr, int s, int l)
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
	MergeSort(arr, s, c_mid);
	MergeSort(arr, c_mid, l);
	Merge(arr, s, c_mid, l);
}

void insertionSortL(std::list<int>::iterator a, std::list<int>::iterator b)
{
	std::list<int> arr(a, b);
	std::list<int>::iterator it;

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
	it = arr.begin();
	while (a != b)
	{
		*a = *it;
		a++;
		it++;
	}
}

void MergeL(std::list<int> &arr, int s, int c_mid, int l)
{
	std::list<int>::iterator b1 = arr.begin();
	std::advance(b1, s);
	std::list<int>::iterator b1e = arr.begin();
	std::advance(b1e, c_mid);
	std::list<int>::iterator b2 = b1e; // b1e(begin) + c_mid
	std::list<int>::iterator e = arr.begin();
	std::advance(e, l);
	std::list<int> temp(b1, e);
	std::list<int>::iterator temp_i = temp.begin();
	std::list<int>::iterator d1 = b1;

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
	}
	while (b1 != b1e && temp_i != temp.end())
	{
		*temp_i = *b1;
		b1++;
		temp_i++;
	}
	while (b2 != e && temp_i != temp.end())
	{
		*temp_i = *b2;
		b2++;
		temp_i++;
	}
	for (std::list<int>::iterator ti = temp.begin(); std::distance(ti, temp.end()) > 0; ti++)
	{
		*d1 = *ti;
		d1++;
	}
}

void MergeSortL(std::list<int> &arr, int s, int l)
{
	int c_mid;
	c_mid = s + (l - s) / 2;
	std::list<int>::iterator it = arr.begin();
	std::list<int>::iterator ite = arr.begin();
	std::advance(it, s);
	std::advance(ite, l);
	if ((l - s) <= 10)
	{
		insertionSortL(it, ite);
		return;
	}
	MergeSortL(arr, s, c_mid);
	MergeSortL(arr, c_mid, l);
	MergeL(arr, s, c_mid, l);
}

void PmergeMe::sorted(void)
{
	timeval t;
	timeval t2;
	timeval t3;
	timeval t4;

	gettimeofday(&t, NULL);
	MergeSort(this->_vec, 0, this->_vec.size());
	gettimeofday(&t2, NULL);
	this->time_vec = ((t2.tv_sec - t.tv_sec) * 10000000 + (t2.tv_usec - t.tv_usec));
	if (!isSorted(this->_vec))
	{
		std::cout << "LIST: Unexspected result" << std::endl;
	}
	gettimeofday(&t3, NULL);
	MergeSortL(this->_list, 0, this->_list.size());
	gettimeofday(&t4, NULL);
	this->time_list = ((t4.tv_sec - t3.tv_sec) * 10000000 + (t4.tv_usec - t3.tv_usec));
	if (!isSorted(this->_list))
	{
		std::cout << "LIST: Unexspected result" << std::endl;
	}
}

void PmergeMe::report(int limit_size)
{
	std::vector<int>::iterator it = this->_original.begin();
	int i = 0;
	std::cout << "Before: ";
	while (it != this->_original.end() && i < limit_size)
	{
		std::cout << *it << "\t";
		it++;
		i++;
	}
	if (it != this->_original.end())
	{
		std::cout << "[...]";
	}
	std::cout << std::endl;

	it = this->_vec.begin();
	i = 0;
	std::cout << "Affter: ";
	while (it != this->_vec.end() && i < limit_size)
	{
		std::cout << *it << "\t";
		it++;
		i++;
	}
	if (it != this->_vec.end())
	{
		std::cout << "[...]";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_vec.size() << " with std::vector<int> : " << this->time_vec << "us" << std::endl;
	std::cout << "Time to process a range of " << this->_vec.size() << " with std::list<int> : " << (this->time_list > 100000 ? this->time_list / 1000 : this->time_list) << (this->time_list > 100000 ? "ms" : "us") << std::endl;
}
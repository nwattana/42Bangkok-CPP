#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
	T *ptr;
	unsigned int size;

public:
	Array<T>(void);
	Array<T>(unsigned int s);
	Array<T>(int s);
	Array<T>(const Array<T> &other);
	~Array<T>(void);

	Array &operator=(const Array<T> &other);
	T &operator[](unsigned int i);

	unsigned int get_size(void) const;
};

#include "Array.tpp"
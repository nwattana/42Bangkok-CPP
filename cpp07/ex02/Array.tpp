template <typename T>
Array<T>::Array()
{
	ptr = NULL;
	size = 0;
}

template <typename T>
Array<T>::Array(unsigned int s)
{
	ptr = new T[s];
	size = s;
}

template <typename T>
Array<T>::Array(int s)
{
	if (s < 0)
		throw std::out_of_range("Size must not less than zero");
	ptr = new T[s];
	size = s;
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
	ptr = new T[other.get_size()];
	size = other.get_size();
	*this = other;
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Array deconstructor call " << std::endl;
	delete [] this->ptr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (other.get_size() != this->size)
		throw std::out_of_range("Invalid size");
	for (unsigned int i=0; i < this->size;i++)
	{
		this->ptr[i] = other.ptr[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->size)
		throw std::out_of_range("Error: index out of range");
	return (this->ptr[i]);
}

template <typename T>
unsigned int Array<T>::get_size(void) const
{
	return (this->size);
}

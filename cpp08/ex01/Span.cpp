#include "Span.hpp"

Span::Span() : v(new std::vector<int>())
{

}

Span::Span(int n)
{
	v = new std::vector<int>();
	v->push_back(n);
}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span()
{
	delete this->v;
}

Span &Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		this->v = rhs.v;
	}
	return *this;
}

void Span::addNumber(const int number)
{
	std::find(v->begin(), v->end(), number)	!= v->end() ? throw Span::DuplicateNumberException() : this->v->push_back(number);
}

int Span::shortestSpan(void)
{
	int shortest = std::numeric_limits<int>::max();
	int tmp;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	for (it = this->v->begin(); it != this->v->end(); it++)
	{
		for (it2 = this->v->begin(); it2 != this->v->end(); it2++)
		{
			if (it != it2)
			{
				tmp = abs(*it - *it2);
				if (tmp < shortest)
					shortest = tmp;
			}
		}
	}
	return shortest;
}

int Span::longestSpan(void)
{
	std::sort(this->v->begin(), this->v->end());
	return this->v->back() - this->v->front();
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	// chekc duplicate
	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		std::find(v->begin(), v->end(), *it)	!= v->end() ? throw Span::DuplicateNumberException() : this->v->push_back(*it);
	}
}
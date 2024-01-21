#pragma once
#include <vector>
#include <math.h>
#include <limits>
#include <algorithm>

class Span
{
	private:
		std::vector<int>* v;

	public:
		Span();
		Span(int n);
		Span(const Span &other);
		~Span();

		Span &operator=(const Span &other);
		void addNumber(const int number);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		int shortestSpan(void);
		int longestSpan(void);

		class DuplicateNumberException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Duplicate number");
				}
		};
};
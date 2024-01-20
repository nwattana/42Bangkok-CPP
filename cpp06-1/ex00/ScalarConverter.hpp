#pragma once

#include <iostream>
#include <string>
#include <math.h>

class ScalarConverter
{

	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &other);

		template <typename T>
		T convert(std::string value);

		class ImpossibleException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("impossible to convert");
				}
		};

};

std::ostream &operator<<(std::ostream &out, ScalarConverter const &value);
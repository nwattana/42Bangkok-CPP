#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <limits>

class ScalarConverter
{
	private:
		double _data;
		int _fract;

		void converter(void);
		ScalarConverter();
	public:
		ScalarConverter(const char *str);
		ScalarConverter(ScalarConverter const &other);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &other);

		void to_char(void);
		void to_int(void);
		void to_float(void);
		void to_double(void);
		int count_affter_dot(const char *str);
};
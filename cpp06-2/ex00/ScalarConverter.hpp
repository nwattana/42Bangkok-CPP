#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <limits>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	IMPOSSIBLE,
};


class ScarlarConverter
{
	private:
		std::string _input;
		char _char_form;
		int _int_form;
		float _float_form;
		double _double_form;

		ScarlarConverter();
	public:
		ScarlarConverter(std::string input);
		ScarlarConverter(ScarlarConverter const& copy);
		~ScarlarConverter();
		ScarlarConverter& operator=(ScarlarConverter const& copy);

		void convert();
		char to_char() const;
		int detectType();
};
#pragma once
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>

enum e_type
{
	IMPOSSIBLE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class ScalarConverter
{
	private:
		std::string _str;
		int _input_type;
		int _float_point;
		int _is_edge_case;


		ScalarConverter();

		std::string _validate_input(std::string str);
		void _print_impossible(void);
		int _detect_type(void);
	public:
		ScalarConverter(std::string str);
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter(void);
		ScalarConverter &operator=(const ScalarConverter &copy);

		void convertToChar(void);
		void convertToInt(void);
		void convertToFloat(void);
		void convertToDouble(void);

		// getters
		std::string getStr(void) const;
		int getInputType(void) const;
		int getFloatPoint(void) const;

};

std::ostream &operator<<(std::ostream &out, const ScalarConverter &sc);
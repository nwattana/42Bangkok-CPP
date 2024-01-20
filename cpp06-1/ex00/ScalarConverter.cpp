#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

// template char ScalarConverter::convert<char>(std::string value) const;
// template int ScalarConverter::convert<int>(std::string value) const;
// template float ScalarConverter::convert<float>(std::string value) const;
// template double ScalarConverter::convert<double>(std::string value) const;

// template<> char ScalarConverter::convert(std::string value) const
// {
// 	char result;
// 	try
// 	{
// 		result = static_cast<char>(value);
// 	}
// 	catch (std::exception &e)
// 	{
// 		throw ScalarConverter::ImpossibleException();
// 	}

// 	return (result);
// }

int to_int(char const *s)
{
	if (s == NULL || *s == '\0')
		throw std::invalid_argument("null or empty string argument");

	bool negate = (s[0] == '-');
	if (*s == '+' || *s == '-')
		++s;

	if (*s == '\0')
		throw std::invalid_argument("sign character only.");

	int result = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			throw std::invalid_argument("invalid input string");
		result = result * 10 - (*s - '0'); // assume negative number
		++s;
	}
	return negate ? result : -result; //-result is positive!
}

float to_float(char const *s)
{
	float result = 0;
	float float_part = 0;
	float point = 0;
	bool negate = (s[0] == '-');

	if (s == NULL || *s == '\0')
		throw std::invalid_argument("null or empty string argument");
	if (*s == '+' || *s == '-')
		++s;
	if (*s == '\0')
		throw std::invalid_argument("sign character only.");

	while (*s)
	{
		if (*s == '.')
			break;
		if (*s < '0' || *s > '9')
			throw std::invalid_argument("invalid input string");
		result = result * 10 - (*s - '0'); // assume negative number
		++s;
	}
	if (*s == '.')
	{
		++s;
		while (*s)
		{
			if (*s < '0' || *s > '9')
				throw std::invalid_argument("invalid input string");
			float_part = float_part * 10 - (*s - '0');
			++s;
			++point;
		}
		result = result + (float_part / pow(10, point));
	}
	return negate ? result : -result;
}

double to_double(const char *str)
{
	double result = 0;
	double float_part = 0;
	double point = 0;
	bool negate = (str[0] == '-');

	if (str == NULL || *str == '\0')
		throw std::invalid_argument("null or empty string argument");
	if (*str == '+' || *str == '-')
		++str;
	if (*str == '\0')
		throw std::invalid_argument("sign character only.");
	while (*str)
	{
		if (*str == '.')
			break;
		if (*str < '0' || *str > '9')
			throw std::invalid_argument("invalid input string");
		result = result * 10 - (*str - '0');
		++str;
	}
	if (*str == '.')
	{
		++str;
		while (*str)
		{
			if (*str < '0' || *str > '9')
				throw std::invalid_argument("invalid input string");
			float_part = float_part * 10 - (*str - '0');
			++str;
			++point;
		}
		result = result + (float_part / pow(10, point));
	}
	return negate ? result : -result;
}

template <>
int ScalarConverter::convert(std::string value)
{
	int result;
	try
	{
		result = to_int(value.c_str());
	}
	catch (std::exception &e)
	{
		throw ScalarConverter::ImpossibleException();
	}

	return (result);
}

template <>
float ScalarConverter::convert(std::string value)
{
	float result;
	try
	{
		result = to_float(value.c_str());
	}
	catch (std::exception &e)
	{
		throw ScalarConverter::ImpossibleException();
	}

	return (result);
}

template <>
double ScalarConverter::convert(std::string value)
{
	double result;
	try
	{
		result = to_double(value.c_str());
	}
	catch (std::exception &e)
	{
		throw ScalarConverter::ImpossibleException();
	}

	return (result);
}

template <>
char ScalarConverter::convert(std::string value)
{
	char result;
	try
	{
		result = static_cast<char>(to_int(value.c_str()));
	}
	catch (std::exception &e)
	{
		throw ScalarConverter::ImpossibleException();
	}

	return (result);
}
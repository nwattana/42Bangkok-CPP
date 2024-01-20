#include "ScalarConverter.hpp"
#include <stdio.h>
ScarlarConverter::ScarlarConverter()
{
}

ScarlarConverter::ScarlarConverter(std::string input)
{
	this->_input = input;
	this->convert();
}

ScarlarConverter::ScarlarConverter(ScarlarConverter const &copy)
{
	this->_input = copy._input;
}

ScarlarConverter::~ScarlarConverter()
{
}

ScarlarConverter &ScarlarConverter::operator=(ScarlarConverter const &copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

template <typename T>
T convert_str_to(std::string input)
{
	std::stringstream ss;
	T ret;

	if (input == "inf" || input == "inff" || input == "+inff" || input == "-inff")
	{
		ret = std::numeric_limits<double>::infinity();
	}
	else if (input == "nanf" || input == "nanf")
	{
		ret = std::numeric_limits<double>::quiet_NaN();
	}
	else
	{
		ss << input;
		ss >> ret;
	}
	return (ret);
}

template <typename T, typename U>
T convert_to_from(U input)
{
	T ret;
	try
	{
		ret = static_cast<T>(input);
	}
	catch (std::exception &e)
	{
		e.what();
	}
	return (ret);
}

template <typename T>
char convert_to_char(T input)
{
	char ret;
	int temp;

	temp = static_cast<int>(input);
	if (!isprint(temp))
	{
		std::cout << "char: unprintable" << std::endl;
		return (0);
	}
	ret = static_cast<char>(temp);
	std::cout << "char: " << ret << std::endl;
	return (ret);
}

int check_double(const char *str)
{
	int i = 0;
	int post_dot = 0;
	int sign = 0;
	int float_char = 0;
	char endwith;

	if (str[i] == '-' || str[i] == '+')
	{
		sign++;
		i++;
	}
	if (!isdigit(str[i]))
		return IMPOSSIBLE;
	while (str[i])
	{
		if (str[i] == '.')
			post_dot++;
		if (str[i] == 'f')
			float_char++;
		if (post_dot > 1)
			return (IMPOSSIBLE);
		if (float_char > 1)
			return (IMPOSSIBLE);
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return (IMPOSSIBLE);
		endwith = str[i];
		i++;
	}
	if (float_char == 1 && endwith == 'f')
		return (FLOAT);
	if (isdigit(endwith) && post_dot == 1)
		return (DOUBLE);
	return (IMPOSSIBLE);
}

void ScarlarConverter::convert()
{
	std::string type_name[5] = {"char", "int", "float", "double", "impossible"};

	int type = this->detectType();

	printf("input is %s\n", this->_input.c_str());
	switch (type)
	{
	case CHAR:
		std::cout << "char" << std::endl;
		this->_char_form = this->_input[0];
		this->_int_form = convert_to_from<int, char>(this->_char_form);
		this->_float_form = convert_to_from<float, char>(this->_char_form);
		this->_double_form = convert_to_from<double, char>(this->_char_form);
		break;
	case INT:
		this->_int_form = convert_str_to<int>(this->_input);
		this->_float_form = convert_to_from<float, int>(this->_int_form);
		this->_double_form = convert_to_from<double, int>(this->_int_form);
		break;
	case FLOAT:
		this->_float_form = convert_str_to<float>(this->_input);
		this->_int_form = convert_to_from<int, float>(this->_float_form);
		this->_double_form = convert_to_from<double, float>(this->_float_form);
		break;
	case DOUBLE:
		this->_double_form = convert_str_to<double>(this->_input);
		this->_int_form = convert_to_from<int, double>(this->_double_form);
		this->_float_form = convert_to_from<float, double>(this->_double_form);
		break;
	default:
		break;
	}

	std::cout << "type: " << type_name[type] << std::endl;
	// if (type == CHAR)
	// 	std::cout << "char: " << this->_char_form << std::endl;
	// else if (type == INT)
	// 	convert_to_char<int>(this->_int_form);
	// else if (type == FLOAT)
	// 	convert_to_char<float>(this->_float_form);
	// else if (type == DOUBLE)
	// 	convert_to_char<double>(this->_double_form);
	// else
	// 	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << this->_int_form << std::endl;
	std::cout << "float: " << this->_float_form << "f" << std::endl;
	std::cout << "double: " << this->_double_form << std::endl;
}

char ScarlarConverter::to_char() const
{
	std::stringstream ss;
	char ret;
	int temp;

	ss << this->_input;
	ss >> temp;

	ret = static_cast<char>(temp);
	return (ret);
}

bool strIsDigit(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int ScarlarConverter::detectType()
{
	std::stringstream ss;
	if (strIsDigit(this->_input.c_str()))
		return INT;
	if (this->_input.length() == 1)
		return CHAR;
	if (this->_input == "nan" \
	|| this->_input == "nanf" \
	|| this->_input == "inf" \
	|| this->_input == "inff" \
	|| this->_input == "+inf" \
	|| this->_input == "+inff" \
	|| this->_input == "-inf" \
	|| this->_input == "-inff")
		return DOUBLE;
	return check_double(this->_input.c_str());
}

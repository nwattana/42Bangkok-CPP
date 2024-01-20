#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter(std::string str): _str(str), _input_type(0), _float_point(1)
{
	// Exit if wrong input
	this->_str = _validate_input(str);
	if (this->_str == "")
		return ;
	this->_input_type = this->_detect_type();
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter(void)
{
}


ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	this->_str = copy._str;
	return (*this);
}

// getters
std::string ScalarConverter::getStr(void) const
{
	return (this->_str);
}

int ScalarConverter::getInputType(void) const
{
	return (this->_input_type);
}

int ScalarConverter::getFloatPoint(void) const
{
	return (this->_float_point);
}


// ####################

std::string get_e_type(int type)
{
	std::string e_type[5] = {"IMPOSSIBLE", "CHAR", "INT", "FLOAT", "DOUBLE"};

	if (type < 0 || type > 4)
		throw std::invalid_argument("Invalid type");
	return (e_type[type]);
}

int ScalarConverter::_detect_type(void)
{
	int size = this->_str.length();
	int dot = 0;
	int sign = 0;
	int digit = 0;
	int float_flag = 0;
	int float_point = 0;

	if (size == 1 && !isdigit(this->_str[0]))
		return (CHAR);
	for (int i = 0; i < size; i++)
	{
		if (this->_str[i] == '.')
			dot++;
		else if (this->_str[i] == '+' || this->_str[i] == '-')
			sign++;
		else if (isdigit(this->_str[i]))
		{
			digit++;
			if (dot == 1)
				float_point++;
		}
		else if (this->_str[i] == 'f')
			float_flag++;
		else
			return (IMPOSSIBLE);
	}
	if (this->_float_point < float_point)
		this->_float_point = float_point;
	if (dot == 1 && sign <= 1 && digit > 0)
	{
		if (this->_str[size - 1] == 'f' && float_flag == 1)
			return (FLOAT);
		if (float_flag == 0)
			return (DOUBLE);
	}
	if (sign <= 1 && digit > 0 && float_flag == 0)
		return (INT);
	return (IMPOSSIBLE);
}

std::string ScalarConverter::_validate_input(std::string str)
{
	int i = 0;
	int size = str.length();
	int space = 0;
	int count_char = 0;

	while (isspace(str[i]))
	{
		space++;
		i++;
	}
	while (!isspace(str[i]) && i < size)
	{
		count_char++;
		i++;
	}
	while (isspace(str[i]) && i < size)
	{
		space++;
		i++;
	}
	if (i != size)
	{
		this->_print_impossible();
		return "";
	}
	return (str.substr(space, count_char));
}

void ScalarConverter::_print_impossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

std::ostream &  operator<<(std::ostream & o, const ScalarConverter& i) {
    o << "str: " << i.getStr() << std::endl;
	o << "input_type: " << get_e_type(i.getInputType()) << std::endl;
    o << "float_point: " << i.getFloatPoint() << std::endl;
	return o;
}

// JUST for reminder how to use this
template <typename T, typename U>
static T convert_from_to(U input)
{
	T output;
	output = static_cast<T>(input);
	return (output);
}

long double convert_str_to_long_double(std::string str)
{
	long double output;
	std::stringstream ss(str);
	ss >> output;
	return (output);
}

template <typename T>
T convert_str_to(std::string str)
{
	T output;
	std::stringstream ss(str);
	ss >> output;
	return (output);
}

template <typename T>
std::string convert_to_char(T input)
{
	int output;
	output = static_cast<int>(input);
	if (output < std::numeric_limits<char>::min() || output > std::numeric_limits<char>::max())
		return ("impossible");
	else if (isprint(output) == 0)
		return ("Non displayable");
	else
		return (std::string(1, static_cast<char>(output)));
}

void ScalarConverter::convertToChar(void)
{
	if (this->_input_type == CHAR)
	{
		std::cout << "char: " << this->_str << std::endl;
	}
	if (this->_input_type == DOUBLE)
	{
		std::cout << "char: " << convert_to_char<double>(convert_str_to<int>(this->_str)) << std::endl;
	}
	if (this->_input_type == INT)
	{
		std::cout << "char: " << static_cast<char>(convert_str_to<int>(this->_str)) << std::endl;
	}
	if (this->_input_type == FLOAT)
	{
		std::cout << "char: " << convert_to_char<float>(convert_str_to<int>(this->_str)) << std::endl;
	}
}


void ScalarConverter::convertToDouble(void)
{
	// long double ld = convert_str_to_long_double(this->_str);
	if (this->_input_type == CHAR)
	{
		std::cout << "double: "   << std::fixed << std::setprecision(this->_float_point) << static_cast<double>(this->_str[0]) << std::endl;
	}
	if (this->_input_type == DOUBLE)
	{
		std::cout << "double: "   << std::fixed << std::setprecision(this->_float_point) << convert_str_to<double>(this->_str) << std::endl;
	}
	if (this->_input_type == INT)
	{
		std::cout << "double: "   << std::fixed << std::setprecision(this->_float_point) << static_cast<double>(convert_str_to<int>(this->_str)) << std::endl;
	}
	if (this->_input_type == FLOAT)
	{
		std::cout << "double: "   << std::fixed << std::setprecision(this->_float_point) << static_cast<double>(convert_str_to<float>(this->_str)) << std::endl;
	}
}

void ScalarConverter::convertToInt(void)
{
	if (this->_input_type == CHAR)
	{
		std::cout << "int: " << static_cast<int>(this->_str[0]) << std::endl;
	}
	if (this->_input_type == DOUBLE)
	{
		std::cout << "int: " << static_cast<int>(convert_str_to<double>(this->_str)) << std::endl;
	}
	if (this->_input_type == INT)
	{
		std::cout << "int: " << convert_str_to<int>(this->_str) << std::endl;
	}
	if (this->_input_type == FLOAT)
	{
		std::cout << "int: " << static_cast<int>(convert_str_to<float>(this->_str)) << std::endl;
	}
}

void ScalarConverter::convertToFloat(void)
{
	if (this->_input_type == CHAR)
	{
		std::cout << "float: " << std::fixed << std::setprecision(this->_float_point) << convert_str_to<float>(this->_str) << "f" << std::endl;
	}
	if (this->_input_type == DOUBLE)
	{
		std::cout << "float: " << std::fixed << std::setprecision(this->_float_point) << convert_str_to<float>(this->_str) << "f" << std::endl;
	}
	if (this->_input_type == INT)
	{
		std::cout << "float: " << std::fixed << std::setprecision(this->_float_point) << convert_str_to<float>(this->_str) << "f" << std::endl;
	}
	if (this->_input_type == FLOAT)
	{
		std::cout << "float: " << std::fixed << std::setprecision(this->_float_point) << convert_str_to<float>(this->_str) << "f" << std::endl;
	}
}
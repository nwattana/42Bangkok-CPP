#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(): _data(0)
{

}

ScalarConverter::ScalarConverter(const char *str)
{
	this->_fract = count_affter_dot(str);
	this->_data = atof(str);
}

ScalarConverter::ScalarConverter(const  ScalarConverter &other)
{
	*this = other;
}

ScalarConverter::~ScalarConverter(void)
{

}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &base)
{
	this->_data = base._data;
	return (*this);
}


void ScalarConverter::to_int(void)
{
	int result;

	if (this->_data != this->_data)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}

	try
	{
		result = static_cast<int>(this->_data);
		std::cout << "int: " << result << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::to_char(void)
{
	char result;

	if (this->_data > std::numeric_limits<char>::max() || this->_data < std::numeric_limits<char>::min())
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	try
	{
		result = static_cast<char>(this->_data);
		if (isprint(result))
		{
			std::cout << "char: \'" << result << "\'" <<std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "char: impossible" << std::endl;
	}
}

void ScalarConverter::to_float(void)
{
	float res;

	if (this->_data > std::numeric_limits<float>::max())
	{
		std::cout << "float: +inff" << std::endl;
		return ;
	}
	if (this->_data < std::numeric_limits<float>::min())
	{
		std::cout << "float : -inff" << std::endl;
		return ;
	}
	try
	{
		res = static_cast<float>(this->_data);
		// Check NaN wtf...
		if (this->_data != this->_data)
		{
			std::cout << "float: " << res << "f" << std::endl;
		}
		else
		{
			std::cout << std::fixed << std::setprecision(this->_fract) << "float : " << res << "f" <<  std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "float : impposible" << std::endl;
		return ;
	}
}

void ScalarConverter::to_double(void)
{
	double res;

	try
	{
		res = static_cast<double>(this->_data);
		std::cout << "double : " << res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "double : impposible" << std::endl;
		return ;
	}
}

int ScalarConverter::count_affter_dot(const char *str)
{
	int fract = 0;
	int ret_fract = 1;
	int i = 0;

	while(str[i] != '.' && str[i])
	{
		i++;
	}
	if (str[i] == '\0')
	{
		return 1;
	}
	else
	{
		i++;
		while (isdigit(str[i]))
		{
			i++;
			fract++;
		}
	}
	return fract > ret_fract ? fract : ret_fract;
}

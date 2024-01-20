#include "ScalarConverter.hpp"

int main(void)
{
	ScalarConverter converter;
	float a = 10.112341f;
	double b = 10.112341;
 	double pi = 3.142857142857;

	std::cout << "char: ";
	std::cout << converter.convert<char>("0") << std::endl;
	std::cout << converter.convert<char>("2147483648") << std::endl;
	std::cout << converter.convert<char>("-2") << std::endl;


	std::cout << "int: ";
	std::cout << converter.convert<int>("0") << std::endl;
	std::cout << converter.convert<int>("2147483648") << std::endl;
	std::cout << converter.convert<int>("-2") << std::endl;

	std::cout << "float: ";
	std::cout << converter.convert<float>("10.112341") << std::endl;
	std::cout << a << std::endl;

	std::cout << "double: ";
	std::cout << converter.convert<double>("10.112341") << std::endl;
	std::cout << b << std::endl;
	std::cout << converter.convert<double>("3.142857142857") << std::endl;
	std::cout << pi << std::endl;
	std::cout << ((pi == converter.convert<double>("3.142857142857")) ? "YES" : "NO") << std::endl;

	return (0);
}
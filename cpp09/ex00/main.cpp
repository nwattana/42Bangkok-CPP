// #include "BitcoinExchange.hpp"
// #include "Data.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include "DateConvertor.hpp"
#include "BitcoinExchange.hpp"

int test_digit(const char *s)
{
	int i = 0;
	int dot = 0;

	if (s[i] == '.')
		return (0);
	while (s[i])
	{
		if (isdigit(s[i]) == 0 && s[i] != '.')
			return (0);
		if (s[i] == '.')
			dot++;
		i++;
	}
	if (s[i] == '.')
		return (0);
	if (dot > 1)
		return (0);
	return (1);
}

void process_line(std::string line, BitcoinExchange &bec)
{
	std::basic_stringstream<char> ss;
	std::string date, sep, amount_str;
	std::string validator_sep = "|";
	std::string header = "date | value";
	double amount = 0;
	double prices = 0;
	DateConvertor dc("-");

	ss << line;
	if (line == "")
		return;
	if (line == header)
		return;
	ss >> date >> sep >> amount_str;
	if (ss.fail())
	{
		std::cout << "Invalid line [" << line << "]" << std::endl;
		return;
	}
	if (dc.check_date_format(date) == false)
	{
		std::cout << "Invalid date format" << std::endl;
		return;
	}
	if (sep != validator_sep)
	{
		std::cout << "Invalid separator" << std::endl;
		return;
	}
	if (test_digit(amount_str.c_str()) == false)
	{
		std::cout << "Invalid amount [" << amount_str << "]" << std::endl;
		return;
	}
	ss << amount_str;
	amount = atof(amount_str.c_str());
	try
	{

		if (amount < 0)
			throw std::invalid_argument("amount is Non positive number");
		if (amount > 1000)
			throw std::invalid_argument("Too Rich It's over 1000, amount must less than 1000");
		if (!dc.check_date_format(date))
			throw std::invalid_argument("Invalid date format");
		prices = bec.get_price(date);
		if (prices == -1)
			return;
		std::cout << date << " => " << amount << "*" << prices << " = " << amount * prices << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
}

int main(int ac, char *av[])
{

	try
	{
		BitcoinExchange bce;
		std::ifstream input_file;
		DateConvertor dc("-");
		std::string line;
		if (ac != 2)
		{
			std::cout << "Invalid argument ./btc [./path_to_input_file]" << std::endl;
			return (1);
		}
		input_file.open(av[1], std::ifstream::in);
		if (!input_file.is_open())
		{
			std::cout << "File Not Open !" << std::endl;
			return (1);
		}
		while (getline(input_file, line))
		{
			process_line(line, bce);
		}
		input_file.close();

	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	return (0);
}

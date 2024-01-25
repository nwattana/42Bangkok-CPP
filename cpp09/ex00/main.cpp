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


void process_line(std::string line, BitcoinExchange &bec)
{
	std::basic_stringstream<char> ss(line);
	char date[11];
	char sep[4] = "|";
	std::string validator_sep = "|";
	std::string header="date | value";
	double amount;
	double prices;

	for (int i = 0; i < 11; i++)
		date[i] = '\0';

	try
	{
		if (line.empty())
			return ;
		if (!line.compare(header))
			return ;
		ss >> date >> sep >> amount;
		if (std::string(sep).compare(validator_sep))
			throw std::invalid_argument("in valid seperator");
		if (amount < 0)
			throw std::invalid_argument("amount is Non positive number");
		if (amount > 1000)
			throw std::invalid_argument("Too Rich It's over 1000");
		prices = bec.get_price(date);
		std::cout << date << " => " << amount << "*" <<  prices  << " = " << amount * prices << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : "<< e.what() << std::endl;
	}
}


int main(int ac, char *av[])
{
	BitcoinExchange bce;
	std::ifstream input_file;
	DateConvertor dc("-");
	std::string line;

	
	if (ac != 2)
	{
		std::cerr << "Invalid argument ./btc [./path_to_input_file]" << std::endl;
		return (1);
	}
	input_file.open(av[1], std::ifstream::in);
	if (!input_file.is_open())
	{
		std::cerr << "File Not Open !" << std::endl;
		return (1);
	}
	while (getline(input_file, line))
		process_line(line, bce);
	return (0);
}

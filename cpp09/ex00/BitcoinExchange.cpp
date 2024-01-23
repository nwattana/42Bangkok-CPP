#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string input) : _data_file_path("./data.csv")
{
	std::ifstream myfile(_data_file_path.c_str());
	std::ifstream myfile2(input.c_str());
	std::string line;

}


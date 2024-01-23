#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Date.hpp"

class BitcoinExchange
{
	private:
		const std::string _data_file_path;
		const std::map<unsigned long, unsigned int> _data_base;

	public:
		BitcoinExchange(std::string input);
		~BitcoinExchange();
};


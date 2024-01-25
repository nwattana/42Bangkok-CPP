#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include "DateConvertor.hpp"

class BitcoinExchange
{
	private:
		const std::string _data_file_path;
		std::map<int, double> _data_base;
		int min_key;
		int max_key;

		double get_close_iter(int key);
	public:
		BitcoinExchange();
		// BitcoinExchange(std::string input);
		// BitcoinExchange(const char *input, const char *data_file_path);
		// ~BitcoinExchange();

		void add_data(std::string s);
		void show_map(int i);

		float get_price(std::string date);
};


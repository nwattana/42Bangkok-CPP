#include "BitcoinExchange.hpp"
#include <iomanip>

BitcoinExchange::BitcoinExchange() : _data_file_path("./data.csv"), min_key(std::numeric_limits<int>::max()), max_key(std::numeric_limits<int>::min())
{
	std::ifstream data_file(_data_file_path.c_str());
	std::string line;

	if (!data_file.is_open())
		throw std::invalid_argument("File Database Can't open");
	std::getline(data_file, line);
	while (std::getline(data_file, line))
	{
		add_data(line);
	}
}

void BitcoinExchange::add_data(std::string s)
{
	DateConvertor dc("-");
	std::string sep(",");
	std::string token;
	int start, end = -1;
	int i = 0;
	int key;
	double value;

	std::pair<int, float> p;
	do
	{
		start = end + sep.size();
		end = s.find(sep, start);
		token = s.substr(start, end - start);
		if (i > 1 && token.empty())
		{
			throw std::invalid_argument("invalid arg");
		}
		if (i == 0)
			key = dc.get_day_int(token);
		else
		{
			value = atof(token.c_str());
		}
		i++;
	} while (end != -1);
	if (key < this->min_key)
		this->min_key = key;
	if (key > this->max_key)
		this->max_key = key;
	p = std::make_pair(key, value);
	this->_data_base.insert(p);
}

void BitcoinExchange::show_map(int i)
{
	DateConvertor dc("-");
	int a = 0;

	for (std::map<int, double>::iterator it = this->_data_base.begin(); it != this->_data_base.end(); ++it)
	{
		std::cout << "Key: " << it->first << " " << dc.day_to_date(it->first) << std::endl;
		std::cout << "Value: " << it->second << std::endl;
		a++;
		if (i < a)
			break;
	}
}

float BitcoinExchange::get_price(std::string str)
{
	DateConvertor dc("-");
	int key;
	float ret;

	if (str.empty())
		throw std::invalid_argument("Get price recieved empty string");
	key = dc.get_day_int(str);
	if (key < min_key)
		throw std::invalid_argument("You get date to early Bitcoin Not exist yet");
	if (key > max_key)
		return (this->_data_base.end())->second;
	if (this->_data_base.find(key) == this->_data_base.end())
	{
		try
		{
			ret = get_close_iter(key);
		}
		catch (std::exception &e)
		{
			throw std::out_of_range(" Key not found \"" + str + "\"");
		}
	}
	else
		ret = (this->_data_base.find(key))->second;
	return (ret);
}

double BitcoinExchange::get_close_iter(int key)
{
	std::map<int, double>::iterator it = this->_data_base.begin();
	std::map<int, double>::iterator ite = this->_data_base.end();
	std::map<int, double>::iterator itp;

	while (it != ite)
	{
		if (it->first > key)
		{
			itp = it;
			it++;
			if (key - itp->first < it->first - key)
			{
				return itp->second;
			}
			else
			{
				return it->second;
			}
		}
		it++;
	}
	return (-1);
}
#include "DateConvertor.hpp"

DateConvertor::DateConvertor() : _separator("-"), start_day(1), start_month(1), start_year(1)
{
}

DateConvertor::DateConvertor(std::string separator) : _separator(separator), start_day(1), start_month(1), start_year(1)
{
}

DateConvertor::DateConvertor(DateConvertor const &other)
{
	*this = other;
}

DateConvertor::~DateConvertor()
{
}

DateConvertor &DateConvertor::operator=(DateConvertor const &other)
{
	this->_separator = other._separator;
	this->start_day = other.start_day;
	this->start_month = other.start_month;
	this->start_year = other.start_year;
	return (*this);
}

int DateConvertor::is_leap_year(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return (1);
	if (year % 400 == 0)
		return (1);
	return (0);
}

int DateConvertor::days_in_month(int month, int year)
{
	int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month < 1 || month > 12)
	{
		std::cout << " Month : " << month << std::endl;
		throw std::invalid_argument("Invalid month");
	}
	if (is_leap_year(year))
		month_days[1] = 29;
	return (month_days[month - 1]);
}

int DateConvertor::day_in_year(int year)
{
	if (year < 0)
		throw std::invalid_argument("Invalid year");
	if (is_leap_year(year))
		return (366);
	return (365);
}

int DateConvertor::is_real_day(int year, int month, int day)
{
	if (day < 1 || day > this->days_in_month(month, year))
		throw std::invalid_argument("Invalid day");
	return (1);
}

int DateConvertor::check_date_format(std::string s)
{
	long unsigned int i = 0;
	int count = 0;
	if (s.empty())
		return (1);
	while (i < s.size() && s[i])
	{
		if (this->_separator.find(s[i]) != std::string::npos)
			count++;
		if ((this->_separator.find(s[i]) == std::string::npos) && !isdigit(s[i]))
		{
			return (0);
		}
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int DateConvertor::day_from_start(int year, int month, int day)
{
	int i = 1;
	int smount = 1;
	int syear = 1;
	int total_days = 0;

	for (i = syear; i < year; i++)
	{
		total_days += this->day_in_year(i);
	}
	for (i = smount; i < month; i++)
	{
		total_days += this->days_in_month(i, year);
	}
	if (day < 1 || day > this->days_in_month(month, year))
		throw std::invalid_argument("Invalid day");
	return (total_days + day);
}

int DateConvertor::get_day_int(std::string s)
{
	int date[3] = {0, 0, 0};
	int start, end = -1 * this->_separator.size();
	int i = 0;
	std::string token;

	if (s.empty())
		throw std::invalid_argument("Invalid date format empty string");
	if (!check_date_format(s))
	{
		throw std::invalid_argument("Invalid date format not valid date format string");
	}
	do
	{
		start = end + this->_separator.size();
		end = s.find(this->_separator, start);
		token = s.substr(start, end - start);
		if (token.empty())
			throw std::invalid_argument("Invalid date format empty string");
		date[i] = atoi(token.c_str());
		i++;
	} while (end != -1 && i < 3);
	for (i = 0; i < 3; i++)
	{
		if (date[i] <= 0)
			throw std::invalid_argument("Invalid date format less than 0");
	}
	if (!this->is_real_day(date[0], date[1], date[2]))
		throw std::invalid_argument("Invalid date format");
	return (this->day_from_start(date[0], date[1], date[2]));
}

std::string int_to_day(int y, int m, int d)
{
	std::string s;
	std::stringstream ss;
	ss << y << "-" << (m < 10 ? "0" : "") << m << "-" << d;
	ss >> s;
	return (s);
}

std::string DateConvertor::day_to_date(int day)
{
	// intput day and return date in format "YYYY{sep}MM{sep}DD"
	// where {sep} is the separator string
	int year = 1;
	int month = 1;
	int days = 0;

	if (day > 100000000)
	{
		throw std::invalid_argument("Sorry I'm Not Support Day more than 100000000");
	}
	if (day < 1)
		throw std::invalid_argument("Invalid day");

	while (day > 365)
	{
		if (this->is_leap_year(year))
		{
			if (day > 366)
			{
				day -= 366;
				year++;
			}
		}
		else
		{
			if (day > 365)
			{
				day -= 365;
				year++;
			}
		}
	}
	while (day > this->days_in_month(month, year))
	{
		day -= this->days_in_month(month, year);
		month++;
	}
	days = day;

	return (int_to_day(year, month, days));
}

void test_date_convertor(std::string s)
{
	int a;
	DateConvertor d("/");
	try
	{
		a = d.get_day_int(s);
	}
	catch (const std::exception &e)
	{
		std::cout << "\"" << s << "\" : " << e.what() << std::endl;
		return;
	}
	std::cout << "\"" << s << "\" : Date is valid int val = " << a << std::endl;
}

void test_date_convertor_dash(std::string s)
{
	int a;
	DateConvertor d("-");
	try
	{
		a = d.get_day_int(s);
	}
	catch (const std::exception &e)
	{
		std::cout << "\"" << s << "\" : " << e.what() << std::endl;
		return;
	}
	std::cout << "\"" << s << "\" : Date is valid int val = " << a << std::endl;
}

void test_day(void)
{
	std::string s;
	test_date_convertor("1/1/1");
	test_date_convertor("1/1/2");
	test_date_convertor("1/1/3");
	test_date_convertor("1/2/29");
	test_date_convertor("1/3/1");
	test_date_convertor("");
	try
	{
		test_date_convertor(NULL);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	test_date_convertor("1/1/0");
	test_date_convertor("1/1/-1");
	test_date_convertor("1/1/200000000");

	test_date_convertor_dash("1-1-1");
	test_date_convertor_dash("1-1-2");
	test_date_convertor_dash("1-1-3");
	test_date_convertor_dash("1-2-29");
	test_date_convertor_dash("1-3-1");
	test_date_convertor_dash("");
	try
	{
		test_date_convertor_dash(NULL);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	test_date_convertor_dash("1-1-0");
	test_date_convertor_dash("1-1--1");
	test_date_convertor_dash("1-1-200000000");

	DateConvertor dc("/");

	std::cout << "---------------------" << std::endl;
	std::cout << "1 day from 1/1/1 = " << dc.day_to_date(1) << std::endl;
	std::cout << "2 day from 1/1/1 = " << dc.day_to_date(2) << std::endl;
	std::cout << "3 day from 1/1/1 = " << dc.day_to_date(3) << std::endl;
	std::cout << "365 day from 1/1/1 = " << dc.day_to_date(365) << std::endl;
	std::cout << "728565 day from 1/1/1 = " << dc.day_to_date(728565) << std::endl;
	std::cout << "100000000 day from 1/1/1 = " << dc.day_to_date(100000000) << std::endl;
	try
	{
		std::cout << "1000000000 day from 1/1/1 = " << dc.day_to_date(1000000000) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
}
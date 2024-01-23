// #include "BitcoinExchange.hpp"
// #include "Data.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>

void tokenize(std::string s, std::string del);
int check_date_format(std::string s);
int isleapyear(int year);
int days_in_month(int month, int year);
int day_from_start(int day, int month, int year);
int day_in_year(int year);
int is_real_day(int day, int month, int year);

void tokenize(std::string s, std::string del = " ")
{
	int date[3]={0, 0, 0};
    int start, end = -1*del.size();
	int i= 0;
	std::string token;

	if (s.empty())
		throw std::invalid_argument("Invalid date format empty string");
	if (check_date_format(s))
		throw std::invalid_argument("Invalid date format not valid date format string");
    do {
        start = end + del.size();
        end = s.find(del, start);
		token = s.substr(start, end - start);
		date[i] = atoi(token.c_str());
		i++;
    } while (end != -1);


	for (i=0; i<3; i++)
	{
		if (date[i] <= 0)
			throw std::invalid_argument("Invalid date format less than 0");
	}
	if (!is_real_day(date[0], date[1], date[2]))
		throw std::invalid_argument("Invalid date format");
	// std::cout << "total days: " << day_from_start(date[0], date[1], date[2]) << std::endl;
}

int check_date_format(std::string s)
{
	int i = 0;
	int count = 0;
	while (s[i])
	{
		if (s[i] == '/')
			count++;
		if (s[i] != '/' && !isdigit(s[i]))
			return (1);
		i++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int isleapyear(int year)
{
	if (year < 0)
		throw std::invalid_argument("Invalid year");
	if (year % 4 == 0 && year % 100 != 0)
		return (1);
	else if (year % 400 == 0)
		return (1);
	return (0);
}

int days_in_month(int month, int year)
{
	if (month < 1 || month > 12)
		throw std::invalid_argument("Invalid month");
	if (month == 2)
	{
		if (isleapyear(year))
			return (29);
		return (28);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (30);
	return (31);
}

int day_from_start(int year, int month, int day)
{
	int i = 1;
	int smount = 1;
	int syear = 1;
	int total_days = 0;

	for (i = syear; i < year; i++)
	{
		total_days += day_in_year(i);
	}
	for (i = smount; i < month; i++)
	{
		total_days += days_in_month(i, year);
	}
	total_days += day;

	return (total_days);
}

int day_in_year(int year)
{
	if (year < 0)
		throw std::invalid_argument("Is not a real day");
	if (isleapyear(year))
		return (366);
	return (365);
}

int is_real_day(int year, int month, int day)
{
	if (day < 1 || day > days_in_month(month, year))
		return (0);
	return (1);
}


void test_date_convertor(std::string s)
{
	try
	{
		tokenize(s, "/");
	}
	catch(const std::exception& e)
	{
		std::cerr << "\""<< s <<"\" : "<< e.what() << std::endl;
		return ;
	}
	std::cout << "\""<< s << "\" : Date is valid" << std::endl;
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
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	test_date_convertor("1/1/0");
	test_date_convertor("1/1/-1");
	test_date_convertor("1/1/200000000");
}

int main(int ac, char *av[])
{
	(void)av;
	if (ac == -1)
		return (1);
	test_day();	
	return (0);
}

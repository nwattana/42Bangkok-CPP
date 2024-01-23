#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <limits>

class DateConvertor
{
	private:
		std::string _separator;
		int start_day;
		int start_month;
		int start_year;

	public:
		DateConvertor();
		DateConvertor(std::string separator);
		DateConvertor(DateConvertor const &other);
		~DateConvertor();
		DateConvertor &operator=(DateConvertor const &other);

		int get_day_int(std::string s);
		int check_date_format(std::string s);
		int is_leap_year(int year);
		int days_in_month(int month, int year);
		int day_from_start(int y, int m, int d);
		int day_in_year(int year);
		int is_real_day(int day, int month, int year);
		std::string day_to_date(int day);

};

void test_day(void);
void test_date_convertor_dash(std::string s);
void test_date_convertor(std::string s);
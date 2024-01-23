// #include "Date.hpp"


// Date::Date(std::string d)
// {
// 	this->value = date_str_to_int(d);
// }

// // Date::Date(Date const &other)
// // {
// // 	*this = other;
// // }

// Date::~Date()
// {

// }


// int Date::isleapYear(int y)
// {
// 	if (y < 0)
// 		throw Date::InvalidDateException();
// 	if (y % 4 == 0 && y % 100 != 0)
// 		return (1);
// 	else if (y % 400 == 0)
// 		return (1);
// 	return (0);
// }

// int isValidYear(std::string y)
// {
// 	int year = atoi(y.c_str());
// 	if (year < 0)
// 		throw Date::InvalidDateException();
// 	if (year > 3000 && year < 10000)
// 	{
// 		std::cout << "Are you a time traveler?" << std::endl;
// 		return (1);
// 	}
// 	else if (year > 9999)
// 	{
// 		throw Date::NotSupportedDateException();
// 	}
// 	return (1);
// }

// int is_onlydigit(const char *s, size_t len)
// {
// 	size_t i = 0;
// 	while (i < len && s != NULL)
// 	{
// 		if (!isdigit(s[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }


// int Date::get_day_of_month(int m, int y)
// {
// 	int days_in_month= 0;

// 	if (m< 1 || m > 12)
// 		throw Date::InvalidDateException();
// 	if (m == 2)
// 	{
// 		if (isleapYear(y))
// 			days_in_month = 29;
// 		else
// 			days_in_month = 28;
// 	}
// 	else if (m == 4 || m == 6 || m == 9 || m == 11)
// 	{
// 		days_in_month = 30;
// 	}
// 	else
// 		days_in_month = 31;
// 	return (days_in_month);
// }

// int Date::validate_date_number(int d, int m, int y)
// {
// 	if (d < 1 || d > 31)
// 		throw Date::InvalidDateException();
// 	if (m < 1 || m > 12)
// 		throw Date::InvalidDateException();
// 	if (y < 0)
// 		throw Date::InvalidDateException();
// 	if (m == 2)
// 	{
// 		if (isleapYear(y))
// 		{
// 			if (d > 29)
// 				throw Date::InvalidDateException();
// 		}
// 		else
// 		{
// 			if (d > 28)
// 				throw Date::InvalidDateException();
// 		}
// 	}
// 	else if (m == 4 || m == 6 || m == 9 || m == 11)
// 	{
// 		if (d > 30)
// 			throw Date::InvalidDateException();
// 	}
// 	return (1);
// }

// // int date_str_to_int(char* d)
// // {
// // 	char *p = strtok(d, "/");
// // 	while (p != NULL)
// // 	{
// // 		if (!is_onlydigit(p, strlen(p)))
// // 			throw Date::InvalidDateException();
// // 		std::cout << p << std::endl;
// // 		p = strtok(NULL, "/");
// // 	}
// // 	return (1);
// // }


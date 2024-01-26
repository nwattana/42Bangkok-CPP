#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <exception>

class RPN
{
	private:
		std::stack<double> s;
		std::string sign;
		int space;

	public:
		RPN();
		RPN(const RPN &rpn);
		~RPN();
		RPN &operator=(const RPN &rpn);

		double eval(char input);
		double getval(void);
};
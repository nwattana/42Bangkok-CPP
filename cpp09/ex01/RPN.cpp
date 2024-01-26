#include "RPN.hpp"

RPN::RPN():sign("+-*/"), space(1)
{
}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &rpn)
{
	if (this == &rpn)
		return (*this);
	this->s = rpn.s;
	this->sign = rpn.sign;
	this->space = rpn.space;
	return (*this);
}

double RPN::eval(char input)
{
	std::basic_stringstream<char> convert;
	double temp;

	if (input >= '0' && input <= '9' && this->space == 1)
	{
		convert << input;
		convert >> temp;
		this->s.push(temp);
	}
	else if (this->sign.find(input) != std::string::npos)
	{
		if (this->s.size() < 2)
			throw std::invalid_argument("Not enough operands");
		double a = this->s.top();
		this->s.pop();
		double b = this->s.top();
		this->s.pop();
		switch (input)
		{
			case '+':
				temp = a + b;
				break;
			case '-':
				temp = a - b;
				break;
			case '*':
				temp = a * b;
				break;
			case '/':
				if (b == 0)
					throw std::invalid_argument("Division by zero");
				temp = a / b;
				break;
		}
		this->s.push(temp);
		return (temp);
	}
	return (0);
}

double RPN::getval(void)
{
	if (this->s.size() != 1)
		throw std::invalid_argument("Invalid input not enough operators");
	return (this->s.top());
}
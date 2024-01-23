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
		this->space = 0;
	}
	else if (this->sign.find(input) != std::string::npos  && this->space == 1)
	{
		if (this->s.size() < 2)
			throw std::invalid_argument("Not enough operands");
		double a = this->s.front();
		this->s.pop();
		double b = this->s.front();
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
				temp = a / b;
				break;
		}
		this->space = 0;
		this->s.push(temp);
		return (temp);
	}
	else if (input != ' ')
	{
		if (this->space == 1)
			throw std::invalid_argument("Invalid input");
		else
			throw std::invalid_argument("support only one char per element");
	}
	else {
		this->space = 1;
	}
	return (0);
}

double RPN::getval(void)
{
	if (this->s.size() != 1)
		throw std::invalid_argument("Invalid input");
	return (this->s.front());
}
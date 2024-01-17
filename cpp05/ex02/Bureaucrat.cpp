#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150), _name("Steave")
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const int grade, const std::string name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	this->_name = name;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	if (src.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (src.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		if (rhs.getGrade() < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (rhs.getGrade() > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade = rhs.getGrade();
		this->_name = rhs.getName();
	}
	return *this;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
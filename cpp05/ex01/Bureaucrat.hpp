#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	int _grade;
	std::string _name;

public:
	Bureaucrat();
	Bureaucrat(const int grade, const std::string name);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	virtual ~Bureaucrat();

	int getGrade(void) const;
	std::string getName(void) const;
	void incrementGrade(void);
	void decrementGrade(void);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Grade too high";
		};
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Grade too low";
		};
	};

	void signForm(Form & form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif

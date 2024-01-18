#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		virtual ~Intern();

		Intern &operator=(Intern const &other);

		AForm *makeForm(std::string const &formName, std::string const &target) const;

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("Form not found");};
		};
};
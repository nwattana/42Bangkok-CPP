#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : AForm
{
	private:
		std::string const * target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const * target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
		virtual ~ShrubberyCreationForm();

};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &ShrubberyCreationForm);
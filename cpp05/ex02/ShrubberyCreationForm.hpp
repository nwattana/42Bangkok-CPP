#pragma once

# include <iostream>
# include <string>
# include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/// @brief to sign grade 145, to execute grade 137
class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	~ShrubberyCreationForm();

	std::string const getTarget(void) const;
	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &ShrubberyCreationForm);
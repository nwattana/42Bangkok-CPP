#pragma once
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/// @brief to sign grade 25, to execute grade 5
class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

		void execute(Bureaucrat const &executor) const;
};
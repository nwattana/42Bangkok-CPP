
#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	std::string formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formList[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			switch (i)
			{
			case 0:
				return (new ShrubberyCreationForm(target));
			case 1:
				return (new RobotomyRequestForm(target));
			case 2:
				return (new PresidentialPardonForm(target));
			default:
				break;
			}
		}
	}
	throw FormNotFoundException();
	return (NULL);
}
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int test_ShrubberyCreationForm_create_sign_execute(void)
{
	Bureaucrat *b = new Bureaucrat(1, "timmy");
	AForm *sform = new ShrubberyCreationForm("Shrub");

	sform->beSigned(*b);
	std::cout << *sform << std::endl;
	std::cout << sform->getIsSigned() << std::endl;
	sform->execute(*b);

	delete sform;
	delete b;
	return (0);
}

int test_RobotomyRequestForm_create_sign_execute(void)
{
	Bureaucrat *b = new Bureaucrat(1, "timmy");
	AForm *rform = new RobotomyRequestForm("RoBot");

	rform->beSigned(*b);
	std::cout << *rform << std::endl;
	std::cout << rform->getIsSigned() << std::endl;
	rform->execute(*b);

	delete rform;
	delete b;
	return (0);
}

int test_PresidentialPardonForm_create_sign_execute(void)
{
	Bureaucrat *b = new Bureaucrat(1, "timmy");
	AForm *pform = new PresidentialPardonForm("Pres");

	pform->beSigned(*b);
	std::cout << *pform << std::endl;
	std::cout << pform->getIsSigned() << std::endl;
	pform->execute(*b);

	delete pform;
	delete b;
	return (0);
}

// Test Exception
int test_ShrubberyCreationForm_sign_error__TooLow(void)
{
	Bureaucrat *b = new Bureaucrat(150, "timmy");
	AForm *sform = new ShrubberyCreationForm("Shrub");

	std::cout << *sform << std::endl;
	try{
		sform->beSigned(*b);
		sform->execute(*b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete sform;
	delete b;
	return (0);
}

int test_ShrubberryCreationForm_execute_error__NotSign(void)
{
	Bureaucrat *b = new Bureaucrat(100, "timmy");
	AForm *sform = new ShrubberyCreationForm("Shrub");

	std::cout << *sform << std::endl;
	std::cout << sform->getIsSigned() << std::endl;
	try{
		sform->execute(*b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete sform;
	delete b;
	return (0);
}

int test_ShrubberryCreationForm_execute_error__TooLow(void)
{
	Bureaucrat *b = new Bureaucrat(150, "timmy");
	AForm *sform = new ShrubberyCreationForm("Shrub");

	std::cout << *sform << std::endl;
	try{
		sform->execute(*b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete sform;
	delete b;
	return (0);
}

int test_RoboTomyRequestForm_sign_error_TooLow(void)
{
	Bureaucrat *b = new Bureaucrat(150, "timmy");
	AForm *rform = new RobotomyRequestForm("RoBot");

	std::cout << *rform << std::endl;
	try{
		rform->execute(*b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete rform;
	delete b;
	return (0);
}

int test_RobotomyRequestForm_execute_error__NotSign(void)
{
	Bureaucrat *b = new Bureaucrat(100, "timmy");
	AForm *rform = new RobotomyRequestForm("RoBot");

	std::cout << *rform << std::endl;
	std::cout << rform->getIsSigned() << std::endl;
	try{
		rform->execute(*b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete rform;
	delete b;
	return (0);
}

int test_RobotomyRequestForm_execute_error__TooLow(void)
{
	Bureaucrat *b = new Bureaucrat(150, "timmy");
	AForm *rform = new RobotomyRequestForm("RoBot");

	std::cout << *rform << std::endl;
	try{
		rform->execute(*b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete rform;
	delete b;
	return (0);
}

int test_PresidentialPardonForm_sign_error__TooLow(void)
{
	Bureaucrat *b = new Bureaucrat(150, "timmy");
	AForm *pform = new PresidentialPardonForm("Pres");

	std::cout << *pform << std::endl;
	try{
		pform->execute(*b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete pform;
	delete b;
	return (0);
}

int test_PresidentialPardonForm_execute_error__TooLow(void)
{
	Bureaucrat *b = new Bureaucrat(150, "timmy");
	AForm *pform = new PresidentialPardonForm("Pres");

	std::cout << *pform << std::endl;
	try{
		pform->execute(*b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete pform;
	delete b;
	return (0);
}

int test_PresidentialPardonForm_execute_error__NotSIGN(void)
{
	Bureaucrat *b = new Bureaucrat(100, "timmy");
	AForm *pform = new PresidentialPardonForm("Pres");

	std::cout << *pform << std::endl;
	std::cout << pform->getIsSigned() << std::endl;
	try{
		pform->execute(*b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete pform;
	delete b;
	return (0);
}




int main(void)
{
	test_RobotomyRequestForm_create_sign_execute();
	// test_ShrubberyCreationForm_create_sign_execute();
	// test_PresidentialPardonForm_create_sign_execute();

	// test_ShrubberyCreationForm_sign_error__TooLow();
	// test_ShrubberryCreationForm_execute_error__NotSign();
	// test_ShrubberryCreationForm_execute_error__TooLow();

	// test_RoboTomyRequestForm_sign_error_TooLow();
	// test_RobotomyRequestForm_execute_error__NotSign();
	// test_RobotomyRequestForm_execute_error__TooLow();
	
	// test_PresidentialPardonForm_sign_error__TooLow();
	// test_PresidentialPardonForm_execute_error__TooLow();
	// test_PresidentialPardonForm_execute_error__NotSIGN();

	return (0);
}
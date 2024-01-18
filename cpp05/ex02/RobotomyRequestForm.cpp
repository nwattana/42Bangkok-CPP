#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	AForm::operator=(other);
	this->target = other.target;
	return (*this);
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static int i = 0;
	if (this->getIsSigned() == false)
		throw AForm::AFormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "* drilling noises *" << std::endl;
	if (i % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "It's a failure" << std::endl;
	i++;
}

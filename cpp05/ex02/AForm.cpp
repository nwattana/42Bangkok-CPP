#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

// Const หมด ยกเว้น isSigned
AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		this->isSigned = rhs.getIsSigned();
	}
	return *this;
}

AForm::~AForm()
{
}

std::string const AForm::getName(void) const
{
	return this->name;
}

int AForm::getGradeToSign(void) const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return this->gradeToExecute;
}

bool AForm::getIsSigned(void) const
{
	return this->isSigned;
}

void AForm::setSigned(bool const isSigned)
{
	this->isSigned = isSigned;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else if (this->isSigned)
		throw AForm::AFormHasAlreadyBeenSignedException();
	else
		this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << "AForm name: " << AForm.getName() << std::endl;
	out << "AForm is signed: " << AForm.getIsSigned() << std::endl;
	out << "AForm grade to sign: " << AForm.getGradeToSign() << std::endl;
	out << "AForm grade to execute: " << AForm.getGradeToExecute() << std::endl;
	return out;
}
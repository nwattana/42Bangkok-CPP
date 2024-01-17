#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

// Const หมด ยกเว้น isSigned
Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->isSigned = rhs.getIsSigned();
	}
	return *this;
}

Form::~Form()
{
}

std::string const Form::getName(void) const
{
	return this->name;
}

int Form::getGradeToSign(void) const
{
	return this->gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return this->gradeToExecute;
}

bool Form::getIsSigned(void) const
{
	return this->isSigned;
}

void Form::setSigned(bool const isSigned)
{
	this->isSigned = isSigned;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else if (this->isSigned)
		throw Form::FormHasAlreadyBeenSignedException();
	else
		this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form name: " << form.getName() << std::endl;
	out << "Form is signed: " << form.getIsSigned() << std::endl;
	out << "Form grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Form grade to execute: " << form.getGradeToExecute() << std::endl;
	return out;
}
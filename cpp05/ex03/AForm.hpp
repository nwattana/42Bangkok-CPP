#ifndef AForm_HPP
# define AForm_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const name;
		bool isSigned;
		int const gradeToSign;
		int const gradeToExecute;
	
	public:
		AForm();
		AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
		AForm(AForm const &src);
		AForm &operator=(AForm const &rhs);
		virtual ~AForm();

		std::string const getName(void) const;
	
		virtual int getGradeToSign(void) const;
		virtual int getGradeToExecute(void) const;
	
		virtual bool getIsSigned(void) const;
		virtual void setSigned(bool const isSigned);
		virtual void beSigned(Bureaucrat const &bureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;

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

		class AFormHasAlreadyBeenSignedException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return "AForm has already been signed";
			};
		};

		class AFormIsNotSignedException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return "AForm is not signed";
			};
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif
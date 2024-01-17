#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const name;
		bool isSigned;
		int const gradeToSign;
		int const gradeToExecute;
	
	public:
		Form();
		Form(std::string const name, int const gradeToSign, int const gradeToExecute);
		Form(Form const &src);
		Form &operator=(Form const &rhs);
		virtual ~Form();

		std::string const getName(void) const;
	
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
	
		bool getIsSigned(void) const;
		void setSigned(bool const isSigned);

		void beSigned(Bureaucrat const &bureaucrat);

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

		class FormHasAlreadyBeenSignedException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return "Form has already been signed";
			};
		};

};

std::ostream &operator<<(std::ostream &out, const Form &form);


#endif
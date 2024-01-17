#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
class Bureaucrat {
	private:
		int		_grade;
		std::string _name;

	public:
		Bureaucrat();
		Bureaucrat(const int grade, const std::string name);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		int getGrade(void) const;
		std::string getName(void) const;


};

#endif

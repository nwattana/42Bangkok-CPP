#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150), _name("Steave") {
	std::cout << "Default Constructor called" << std::endl;
	}

Bureaucrat::Bureaucrat(const int grade, const std::string name) {
	this->_grade = grade;
	this->_name = name;
	std::cout << "Bureaucrat Defualt constructor Called" << std::endl;
	}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	std::cout << "Bureaucrate Copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrate desstructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::cout << "Bureaucrat Assign operator called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs.getGrade();
		this->_name = rhs.getName();
	return *this;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
	}

std::string Bureaucrat::getName() const {
	return this->_name;
}

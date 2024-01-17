#include <iostream>
#include "Bureaucrat.hpp"
int main(void)
{
	Bureaucrat a(1, "Temp");
	Bureaucrat b(150, "Perm");

	try {
		b.decrementGrade();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		a.incrementGrade();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

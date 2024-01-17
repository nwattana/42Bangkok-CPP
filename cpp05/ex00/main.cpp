#include <iostream>
#include "Bureaucrat.hpp"
int main(void)
{
	Bureaucrat a;
	Bureaucrat b(12, "Perm");
	Bureaucrat c(b);

	a = c;
	std::cout << "Hello World" << std::endl;
}

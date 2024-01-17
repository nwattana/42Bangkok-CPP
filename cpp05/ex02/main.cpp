#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"


int main(void){
	AForm form("Form", 1, 1);
	AForm form2("Form2", 100, 100);
	Bureaucrat bureaucrat(1,"steve");
	Bureaucrat bureaucrat2(150,"Roger");

	bureaucrat.signForm(form);

	// Can't sign form because Form is already signed
	bureaucrat.signForm(form);

	// Can't sign form2 because bureaucrat2's grade is too low
	bureaucrat2.signForm(form2);

	// Grade too high
	try
	{
		AForm form3("Form3", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Grade too low
	try
	{
		AForm form4("Form4", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
#include "Base.hpp"

// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
Base *generate(void)
{
	int i;

	i = rand() % 3;
	if (i == 0)
	{
		std::cout << "Generate A " << std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "Generate B " << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Generate C " << std::endl;
		return new C;
	}
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// void identify(Base* p);
void identify(Base *p)
{
	try
	{
		if (p == dynamic_cast<A *>(p))
			std::cout << "Poiter Method base = A " << std::endl;
		if (p == dynamic_cast<B *>(p))
			std::cout << "Poiter Method base = B " << std::endl;
		if (p == dynamic_cast<C *>(p))
			std::cout << "Poiter Method base = C " << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden.
// void identify(Base& p);
void identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "Val method Base = A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "Val method Base = B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "Val method Base = C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

int main(void)
{
	for (int i=0; i < 10; i++)
	{
		Base *cool_random_ptr = generate();
		identify(cool_random_ptr);
		identify(*cool_random_ptr);
		std::cout << std::endl;
		delete cool_random_ptr;
	}
	return (0);
}
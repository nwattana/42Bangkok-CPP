#include <iostream>
#include <string>

// class ClassName
class SampleClass
{

// Access Specifier
public:
	// Data Member
	std::string classdataname;
	// Member Functions();
	void printname() {
		std::cout << "This Class name is: " << classdataname;
	}
};

int main()
{
	// Declare an obj of class geeks
	SampleClass obj1;

	// acessing data member
	obj1.classdataname = "Tent Narin";

	// acessing memberfunction
	obj1.printname();

	return 0;
}
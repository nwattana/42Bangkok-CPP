#include <iostream>
using namespace std;


int main(){

	int *ptr = new int; // allocate new memory address in heap,
	// lifetime  = untill deallocate by programer 

	int local_num = 10;
	int *ptr_local  = &local_num;

	int *ptr_array_allocate = new int[4];

	for (int i = 0; i < 4; i++){
		ptr_array_allocate[i] = i; // no have asterisk naja *
	}

	delete ptr_array_allocate; 

	*ptr = 10;

	cout << "address ptr pointed to= " << ptr << endl;
	cout << "deref ptr : = " << *ptr << endl;
	cout << "address of ptr " << &ptr << endl;
	// local stotage
	cout << "address of localnum " << &local_num << endl;
	cout << "address ptr_local pointed to" << ptr_local << endl;
	cout << "address ptr_local " << &ptr_local << endl;



	delete ptr;
	return 0;
}

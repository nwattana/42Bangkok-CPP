#include <iostream>
using namespace std;

int main(void){
	
	int num = 10;
	int *ptr_num = &num;
	int* ptr_num2 = &num;
	int &ref_num = num;
	int& ref_num2 = num;
	int fake_ref_num = num; // same value but not same ref

	// int ref_num;
	// int ref_num = NULL; kaputtt
	cout << num << endl;
	cout << ptr_num << " " << *ptr_num << endl;
	cout << &ref_num << " " << ref_num << endl;
	cout << "fake ref " << fake_ref_num << endl;
	ref_num = 5;
	cout << num << endl;
	cout << ref_num2 << endl;
	cout << ptr_num2 << " " << *ptr_num2 << endl;
	cout << "fake ref " << fake_ref_num << endl;
}

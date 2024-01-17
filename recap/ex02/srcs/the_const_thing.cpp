#include <iostream>
#include <string>

class SampleConst {
	private:
		int _foo;
		int doo;

	public:
		int changeMe;
		SampleConst();
		SampleConst(const SampleConst &src);
		virtual ~SampleConst();
		SampleConst& operator=(const SampleConst& rhs);

		int getFoo(void) const;
};

// Default Constructor 
SampleConst::SampleConst() : _foo(0), doo(0), changeMe(0) {
	std::cout << "Default Constructor called" << std::endl;
}

// Copy Constructor
SampleConst::SampleConst(const SampleConst &src) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

// Destructor
SampleConst::~SampleConst() {
	std::cout << "Destructor called" << std::endl;
}

SampleConst& SampleConst::operator=(const SampleConst& rhs) {

	rhs.getFoo();
	// changeMe เปลี่ยนไม่ได้ใน Function นี้เพราะเป็น const
	// rhs.changeMe = 42;

	std::cout << "Assign operator called" << std::endl;
	if (this != &rhs)
	{
		this->_foo = rhs.getFoo();
		this->doo = rhs.doo;
		this->changeMe = rhs.changeMe;
	}
	return *this;
}

int SampleConst::getFoo(void) const {
	// Function นี้จะไม่มีกการ แก้ค่าของตัวแปรใดๆ ทั้งสิ้น
	// this->_foo = 42;
	// this->doo = 42;
	return this->_foo;
}

int main(void)
{
	SampleConst instance;

	SampleConst const instance2(instance);
	const SampleConst instance3(instance);
	// Compile Error เพราะ instance2 เป็น const ไม่สามารถเปลี่ยนค่าได้
	// instance2.changeMe = 42;
	// instance3 เป็น const ไม่สามารถเปลี่ยนค่าได้
	// instance3.changeMe = 42;

	std::cout << instance.getFoo() << std::endl;
	return 0;
}
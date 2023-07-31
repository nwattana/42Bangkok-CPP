#include <iostream>

class Student
{
    private:
        std::string _name;
    public:
        Student() : _name("John")
        {
            std::cout << "Student " << this->_name << " is born." << std::endl;
        }

        ~Student(void)
        {
            std::cout << "Student " << this->_name << " is dead." << std::endl;
        }

        void announce(void)
        {
            std::cout << "I am " << this->_name << std::endl;
        }
        void setName(std::string name)
        {
            this->_name = name;
        }
};

int main(void)
{
    Student john = Student();
    Student* bob = new Student();
    Student* students = new Student[5];

    john.announce(); // stack
    bob->announce(); // heap

    delete[] students;
    delete bob;
    return (0);
}
#include <iostream>

int add(int a, int b) {
  return a + b;
}

class Calculator {
    public:
        int multiply(int a, int b) {
            return a * b;
        }
};

int main() {
    int x = 5;
    int y = 7;

    // using standalone function 'add'
    int sum = add(x, y);
    std::cout << "sum: " << sum << std::endl;

    // using class member function 'multiply'
    Calculator calc;
    int product = calc.multiply(x, y);
    std::cout << "product: " << product << std::endl;

    return 0;
}
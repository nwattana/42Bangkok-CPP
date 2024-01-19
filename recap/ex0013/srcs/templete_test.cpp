#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>


template <typename T, typename U>
T myMax(T a, T b) {
	return (a > b) ? a : b;
}

class ConversionScalar{
	public:
		template <typename T, typename U>
		U convert(T value) {
			return static_cast<U>(value);
		}
};

int main(void)
{
	ConversionScalar cs;

	std::cout << cs.convert<float, int>(10.1) << std::endl;
	std::cout << cs.convert<char, float>('a') << std::endl;
	std::cout << cs.convert<int, char>(65) << std::endl;
	std::cout << cs.convert<double, int>(10.1) << std::endl;
	std::cout << cs.convert<int, double>(10) << std::endl;
}
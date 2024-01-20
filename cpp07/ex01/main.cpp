#include "iter.hpp"

template <typename T>
void print_by_line(T str)
{
	std::cout << str << std::endl;
}


int main(void)
{
	char str[6] = {'h','e','l','l','o',};
	int str2[6] = {'h','e','l','l','o',};
	float str3[6] = {0.1, 0.2, 3.2, 4.2, 4.3};

	iter(str, 6, print_by_line<char>);
	iter(str2, 6, print_by_line<int>);
	iter(str3, 6, print_by_line<float>);
}
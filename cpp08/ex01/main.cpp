#include "Span.hpp"
#include <iostream>
#include <stdlib.h>

// int main(void)
// {
// 	Span sp = Span(1);
// 	try
// 	{
// 		sp.addNumber(5);
// 		sp.addNumber(5);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

///// TEST 2 /////
// #define V_SIZE 10000
// int main(void)
// {
// 	Span sp;
// 	srand(time(NULL));
// 	for (int i = 0; i < V_SIZE; i++)
// 	{
// 		try
// 		{
// 			sp.addNumber(rand());
// 		}
// 		catch (const std::exception &e)
// 		{
// 		}
// 	}

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

///// TEST 3 /////
int main(void)
{
	Span sp;
	int arr[] = { 0, 1, 2, 3 ,4 ,5 ,6 ,7 ,8 ,9 ,10};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	sp.addNumbers(v.begin(), v.end() - 1);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
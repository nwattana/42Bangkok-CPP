// set::find
#include "easyfind.hpp"
#include <algorithm>
#include <list>
#include <vector>
#include <iostream>

int main( int ac, char ** av )
{
    int                 arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if ( ac != 2 )
	{
		std::cout << "./easy_find [number 1 - 10]" << std::endl;
        return EXIT_FAILURE;
	}

    std::vector< int >      vect( arr, arr + sizeof( arr ) / sizeof( int ) );
    std::list< int >        list( arr, arr + sizeof( arr ) / sizeof( int ) );
	std::list< int >::iterator it_list;
	std::vector< int >::iterator it_vec;


    it_vec = easyfind( vect, std::atoi( av[1] ));
	if (it_vec != vect.end())
		std::cout << "Found val = " << *it_vec << std::endl;
	else
		std::cout << "find return empty" << std::endl;
	
    it_list = easyfind( list, std::atoi( av[1] ));
	if (it_list != list.end())
		std::cout << "Found val = " << *it_list << std::endl;
	else
		std::cout << "find return empty" << std::endl;
	


    return EXIT_SUCCESS;
}
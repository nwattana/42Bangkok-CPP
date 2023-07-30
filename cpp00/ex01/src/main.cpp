/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:31:21 by nwattana          #+#    #+#             */
/*   Updated: 2023/07/30 12:02:10 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
#include "../include/main.hpp"
#include <string>
int main()
{
	std::string input;
	PhoneBook ph;

	while (1)
	{
		std::cout << "MyAwesomePhoneBook (" << std::cin.eof() << ")>>";
		std::getline (std::cin, input);
		if (std::cin.eof() == 1)
		{
			std::cout << "\nMyAwesomePhoneBook (" << std::cin.eof() << ")>>";
			std::cout << ":Ai bra:EOF was sent Good Bye!" << std::endl;
			break ;
		}
		if (input.compare("ADD") == 0)
		{
			std::cout << "\nCREATE CONTATC----------------" << std::endl;
			ph.create_contact();
			std::cout << "----------------------------\n" << std::endl;
		}
		if (input.compare("SEARCH") == 0)
		{
			std::cout << "SEARCH prompt show" << std::endl;
			ph.d_table();
		}
		if (input.compare("EXIT") == 0)
		{
			std::cout << "Good Bye!" << std::endl;
			break;
		}
	}
	return 0;
}

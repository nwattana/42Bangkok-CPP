/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:31:21 by nwattana          #+#    #+#             */
/*   Updated: 2023/06/04 17:39:51 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "../include/PhoneBook.hpp"
// # include "../include/Contact.hpp"
# include <string.h>
# include <iostream>

int main()
{
	std::string input;
	while(1)
	{
		std::cout << "Prompt> ";
		std::cin >> input;
		std::cout << input;
		if (input == "EXIT")
			break ;
	}
	return 0;
}
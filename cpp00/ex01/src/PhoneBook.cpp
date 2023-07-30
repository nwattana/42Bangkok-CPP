/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 06:18:23 by nwattana          #+#    #+#             */
/*   Updated: 2023/07/30 15:15:25 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_current_contact = 0;
	this->is_start = 0;
	this->max_contact = 9;
}

PhoneBook::~PhoneBook()
{
	std::cout << "";
}


void PhoneBook::create_contact()
{
	this->is_start = 1;

	std::string input="";
	this->contacts[8].set_index(this->_current_contact + 1);

	std::cout << "first name\t:\t";
	std::getline (std::cin, input);
	this->contacts[8].set_fname(input);

	std::cout << "last name\t:\t";
	std::getline (std::cin, input);
	this->contacts[8].set_lname(input);
	
	std::cout << "nick name\t:\t";
	std::getline (std::cin, input);
	this->contacts[8].set_nname(input);

	std::cout << "Phone number\t:\t";
	std::getline (std::cin, input);
	this->contacts[8].set_phonenumber(input);

	std::cout << "Dark Secret\t:\t";
	std::getline (std::cin, input);
	this->contacts[8].set_dark_secret(input);
	this->contacts[8].set_dark_secret(input);

	if (this->validate_contact() != 1)
	{
		std::cout << "Some field is in valid!" << std::endl;
		return ;
	}

	if (this->_current_contact == 8)
		this->_current_contact = 0;
	this->contacts[this->_current_contact] = this->contacts[8];
	this->contacts[this->_current_contact].set_index(this->_current_contact + 1);
	this->contacts[this->_current_contact].set_active();
	this->_current_contact++;
}

void PhoneBook::throw_contact(int current_contact)
{
	std::cout << this->contacts[current_contact - 1].get_contact();
}

std::string PhoneBook::_tolong(std::string str)
{
	std::string ret;
	str.size() > 10 ? ret = str.substr(0, 9) + "." : ret = str;
	return ret;
}

void PhoneBook::show_header()
{
	std::cout << "o-------------------------------------------o\n";
	std::cout << "|     index|first name| last name| nick name|\n";
	std::cout << "=============================================\n";
}

int PhoneBook::validate_contact()
{
	int res = 1;

	this->contacts[8].get_fname().compare("") == 0 ? res = 0 : res = 1;
	this->contacts[8].get_lname().compare("") == 0 ? res = 0 : res = 1;
	this->contacts[8].get_nname().compare("") == 0 ? res = 0 : res = 1;
	this->contacts[8].get_phonenumber().compare("") == 0 ? res = 0 : res = 1;
	this->contacts[8].get_dark_secret().compare("") == 0 ? res = 0 : res = 1;

	return (res);
}

void PhoneBook::show_encloser()
{
	std::cout << "|          |          |          |          |\n";
	std::cout << "o-------------------------------------------o\n";
}

std::string PhoneBook::fill_cell(std::string str)
{
	std::string ret;
	int space_count = 10 - str.size();
	ret = str.insert(0, space_count, ' ');
	return ret;
}

void PhoneBook::contact_row(int index)
{
	std::cout << "|" << this->\
	fill_cell(this->_tolong(contacts[index].get_index()));
	std::cout << "|" << this->\
	fill_cell(this->_tolong(contacts[index].get_fname()));
	std::cout << "|" << this->\
	fill_cell(this->_tolong(contacts[index].get_lname()));
	std::cout << "|" << this->\
	fill_cell(this->_tolong(contacts[index].get_nname()))\
	<<"|"<<std::endl;
}


void PhoneBook::d_table()
{
	int i = 0;

	this->show_header();
	while (this->contacts[i]._is_active)
	{
		this->contact_row(i);
		i++;
	}
	this->show_encloser();
}

int PhoneBook::validate_index(int index)
{
	int i = 0;

	while (this->contacts[i]._is_active)
		i++;
	if (index < 1 || index > i)
	{
		return (0);
	}
	return (1);
}


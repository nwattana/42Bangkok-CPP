/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 06:18:23 by nwattana          #+#    #+#             */
/*   Updated: 2023/07/30 12:02:12 by nwattana         ###   ########.fr       */
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
	std::cout << "DEBUG:: PhoneBook Decon" << std::endl;
}

void PhoneBook::create_contact()
{
	this->is_start = 1;

	std::string input="";
	if (this->_current_contact >= 8)
		this->_current_contact = 0;
	this->contacts[this->_current_contact].set_index(this->_current_contact + 1);

	std::cout << "first name\t:\t";
	std::getline (std::cin, input);
	this->contacts[this->_current_contact].set_fname(input);

	std::cout << "last name\t:\t";
	std::getline (std::cin, input);
	this->contacts[this->_current_contact].set_lname(input);
	
	std::cout << "nick name\t:\t";
	std::getline (std::cin, input);
	this->contacts[this->_current_contact].set_nname(input);

	std::cout << "Phone number\t:\t";
	std::getline (std::cin, input);
	this->contacts[this->_current_contact].set_phonenumber(input);

	std::cout << "Dark Secret\t:\t";
	std::getline (std::cin, input);
	this->contacts[this->_current_contact].set_dark_secret(input);

	this->_current_contact++;
}

void PhoneBook::throw_contact(int current_contact)
{
	std::cout << this->contacts[current_contact].get_contact();
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
	this->show_header();
	if (this->is_start == 1){
		for (int i = 0; i <= this->_current_contact - 1; i++){
//		std::cout << "index = " << i << std::endl;
			this->contact_row(i);
		}
	}
	this->show_encloser();
}

//TODO Circular ADDING
//TODO Validate PHONENUMBER
//TODO Empty handle

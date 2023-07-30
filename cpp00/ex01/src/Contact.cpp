/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 05:23:11 by nwattana          #+#    #+#             */
/*   Updated: 2023/07/30 15:14:19 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact(){
	this->_index = "1";
	this->_is_active = 0;
	this->_fname = "";
	this->_lname = "";
	this->_nname = "";
	this->_phonenumber = "";
	this->_dark_secret = "";
}

Contact::~Contact(){
	std::cout << "";
}

Contact& Contact::operator=(const Contact& other)
{
	this->_is_active = 1;
	this->_fname = other._fname;
	this->_lname = other._lname;
	this->_nname = other._nname;
	this->_phonenumber = other._phonenumber;
	this->_dark_secret = other._dark_secret;

	return *this;
}

void Contact::set_index(int num){
	this->_index = std::to_string(num);
}

void Contact::set_fname(std::string fname){
	this->_fname = fname;
}

void Contact::set_lname(std::string lname){
	this->_lname = lname;
}

void Contact::set_nname(std::string nname){
	this->_nname = nname;
}

void Contact::set_phonenumber(std::string phonenumber){
	this->_phonenumber = phonenumber;
}

void Contact::set_dark_secret(std::string dark_secret){
	this->_dark_secret = dark_secret;
}

std::string Contact::get_index(){
	return this->_index;
}

std::string Contact::get_fname(){
	return this->_fname;
}

std::string Contact::get_lname(){
	return this->_lname;
}

std::string Contact::get_nname(){
	return this->_nname;
}

std::string Contact::get_phonenumber(){
	return this->_phonenumber;
}

std::string Contact::get_dark_secret(){
	return this->_dark_secret;
}

std::string Contact::get_contact(){
	return "first name\t" + this->_fname +\
			"\nlast name:\t" + this->_lname +\
			"\nnick name:\t" + this->_nname +\
			"\nPhone nubmer\t" + this->_phonenumber +\
			"\nDark Secret\t" + this->_dark_secret + "\n";
}

void Contact::set_active()
{
	this->_is_active = 1;
}

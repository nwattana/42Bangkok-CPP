/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:58:28 by nwattana          #+#    #+#             */
/*   Updated: 2023/07/30 14:37:45 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact{
	private:
		std::string _index;
		std::string _fname;
		std::string _nname;
		std::string _lname;
		std::string _phonenumber;
		std::string _dark_secret;


	public:
		Contact();
		~Contact();

		Contact& operator=(const Contact& other);
		
		int _is_active;
		void set_active();
		void set_index(int num);
		void set_fname(std::string fname);
		void set_lname(std::string lname);
		void set_nname(std::string nname);
		void set_phonenumber(std::string str);
		void set_dark_secret(std::string str);

		std::string get_contact();
		
		std::string get_index();
		std::string get_fname();
		std::string get_nname();
		std::string get_lname();
		std::string get_phonenumber();
		std::string get_dark_secret();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:02:26 by nwattana          #+#    #+#             */
/*   Updated: 2023/07/30 15:15:48 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Contact.hpp"

#include <iostream>
class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		int			max_contact;
		int			is_start;
		void		create_contact();
		void		throw_contact(int contact_index);
		void		show_header();
		void		show_encloser();
		void		contact_row(int index);
		std::string	fill_cell(std::string str);
		void		d_table();
		int			validate_contact();
		int			validate_index(int i);

	private:
		int			_current_contact;
		std::string _tolong(std::string str);
		Contact 	contacts[9];
};

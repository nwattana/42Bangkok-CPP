/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:58:28 by nwattana          #+#    #+#             */
/*   Updated: 2023/06/04 17:29:45 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
class Contact{
	private:
		std::string dark_secret;
	public:
		int id;
		std::string name;
		std::string nickname;
		std::string lastname;
		std::string phonenumber;
};
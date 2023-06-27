/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:30:44 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/27 15:22:13 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		void		addContact(int i, std::string fn, std::string ln, 
			std::string nn, std::string pn, std::string ds);
		Contact 	getContact(int i);
		std::string getFirstName(int i) const;
		std::string getLastName(int i) const;
		std::string getNickName(int i) const;
		std::string getPhoneNumber(int i) const;
		std::string getDarkestSecret(int i) const;

	private:
		Contact	phonebook[8];
};

#endif
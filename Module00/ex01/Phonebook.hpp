/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:30:44 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 11:30:50 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		begin(void) const;
		int			readIndex(void) const;
		void		displayPhonebook(void) const;
		void		displayContact(int index) const;
		void		addContact(std::string fn, std::string ln, 
			std::string nn, std::string pn, std::string ds);

	private:
		Contact	phonebook[8];
};

#endif
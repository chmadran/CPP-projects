/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:50:31 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/20 16:46:17 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"
# include <iomanip>

class PhoneBook {
public:
	Contact			phonebook[8];
	int				countContacts;

	PhoneBook();
	~PhoneBook();

	void	setPhonebookContact(const Contact& contact);
};

#endif
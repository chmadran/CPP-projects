/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:10:32 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/20 17:26:04 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Phonebook.class.hpp"

PhoneBook::PhoneBook ( void ) {
	return;
}

PhoneBook::~PhoneBook( void ) {
	return;
}

void PhoneBook::setPhonebookContact(const Contact& contact) {
	if (this->countContacts < 8)
	{
		this->phonebook[this->countContacts] = contact;
		this->countContacts++;
		std::cout << "Adding contact to phonebook" << std::endl;
	}
	else {
		this->phonebook[0] = contact;
		std::cout << "Phonebook is full. First contact replaced" << std::endl;
	}
}
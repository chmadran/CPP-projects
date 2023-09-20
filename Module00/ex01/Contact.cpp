/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:05 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 11:27:55 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

void	Contact::setContact(std::string fn, std::string ln, std::string nn, 
			std::string pn, std::string ds) {
	_firstName = fn;
	_lastName = ln;
	_nickName = nn;
	_phoneNumber = pn;
	_darkestSecret = ds;
}

std::string Contact::printLen(std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return (str);
}

void	Contact::displayContact(int index) const {
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << printLen(_firstName) << std::flush;
	std::cout << "|" << std::setw(10) << printLen(_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << printLen(_nickName) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::viewContact(int index) const {
	std::cout << std::endl;
	std::cout << "CONTACT #" << index << std::endl;
	std::cout << "First Name:\t" << _firstName << std::endl;
	std::cout << "Last Name:\t" << _lastName << std::endl;
	std::cout << "Nickname:\t" << _nickName << std::endl;
	std::cout << "Phone Number:\t" << _phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t" << _darkestSecret << std::endl;
	std::cout << std::endl;
}
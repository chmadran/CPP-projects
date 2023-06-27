/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:05:37 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/20 16:59:07 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.class.hpp"

Contact::Contact ( void ) {
	return;
}

Contact::~Contact( void ) {
	return;
}

void Contact::setContact(std::string _f, std::string _l,
			std::string _n, std::string _pn, std::string _ds) { 
	_firstName = _f;
	_lastName = _l;
	_nickName = _n;
	_phoneNumber = _pn;
	_darkestSecret = _ds;
}

void Contact::printContact(void) { 
	std::cout << "[First Name] : " << this->_firstName << std::endl;
	std::cout << "[Last Name] : " << this->_lastName << std::endl;
	std::cout << "[Nick Name] : " << this->_nickName << std::endl;
	std::cout << "[Phone Number] : " << this->_phoneNumber << std::endl;
	std::cout << "[Darkest Secret] : " << this->_darkestSecret << std::endl;
}

void Contact::printTableContact(int index) {
    std::cout << std::setw(10) << std::right << index << " | ";
    std::cout << std::setw(12) << std::left << (_firstName.length() > 10 ? _firstName.substr(0, 9) + "." : _firstName) << " | ";
    std::cout << std::setw(12) << std::left << (_lastName.length() > 10 ? _lastName.substr(0, 9) + "." : _lastName) << " | ";
    std::cout << std::setw(12) << std::left << (_nickName.length() > 10 ? _nickName.substr(0, 9) + "." : _nickName) << std::endl;
}
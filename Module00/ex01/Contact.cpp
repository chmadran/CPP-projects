/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:05 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/27 17:07:09 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	//std::cout << "Contact default constructor" << std::endl;
}

Contact::~Contact(){
	//sstd::cout << "Contact default destructor" << std::endl;
}

void	Contact::setContact(std::string fn, std::string ln, std::string nn, 
			std::string pn, std::string ds) {
	_firstName = fn;
	_lastName = ln;
	_nickName = nn;
	_phoneNumber = pn;
	_darkestSecret = ds;
}

void	Contact::printContact() const {
	std::cout << "[FIRST NAME] : " << _firstName << std::endl;
	std::cout << "[LAST NAME] : " << _lastName << std::endl;
	std::cout << "[NICK NAME] : " << _nickName << std::endl;
	std::cout << "[PHONE NUMBER] : " << _phoneNumber << std::endl;
	std::cout << "[DARKEST SECRET] : " << _darkestSecret << std::endl;
}

std::string Contact::getFirstName() const {
	return _firstName;
}
std::string Contact::getLastName() const {
	return _lastName;
}
std::string Contact::getNickName() const {
	return _nickName;
}
std::string Contact::getPhoneNumber() const {
	return _phoneNumber;
}
std::string Contact::getDarkestSecret() const {
	return _darkestSecret;
}
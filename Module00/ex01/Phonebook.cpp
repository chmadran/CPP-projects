/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:32:01 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/27 17:47:38 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook(){
	//std::cout << "PhoneBook default constructor" << std::endl;
}

PhoneBook::~PhoneBook(){
	//std::cout << "PhoneBook default destructor" << std::endl;
}

void	PhoneBook::addContact(int i, std::string fn, std::string ln, std::string nn, 
			std::string pn, std::string ds) {
	phonebook[i].setContact(fn, ln, nn, pn, ds);
}

Contact	PhoneBook::getContact(int i){
	return phonebook[i];
}

std::string PhoneBook::getFirstName(int i) const {
	return phonebook[i].getFirstName();
}
std::string PhoneBook::getLastName(int i) const {
	return phonebook[i].getLastName();
}
std::string PhoneBook::getNickName(int i) const {
	return phonebook[i].getNickName();
}

std::string PhoneBook::getPhoneNumber(int i) const {
	return phonebook[i].getPhoneNumber();
}

std::string PhoneBook::getDarkestSecret(int i) const {
	return phonebook[i].getDarkestSecret();
}
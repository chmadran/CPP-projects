/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:32:01 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 14:01:15 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook(void){
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::begin(void) const {
	std::cout << std::endl;
	std::cout << "📞 Welcome to Your PhoneBook 📖" << std::endl;
	std::cout << std::endl;
	std::cout << "--------------USAGE---------------" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::addContact(std::string fn, std::string ln, std::string nn, 
			std::string pn, std::string ds)
{
	static int	i;
	phonebook[i % 8].setContact(fn, ln, nn, pn, ds);
	i++;
}

int	PhoneBook::readIndex(void) const {
	int		input = -1;
	bool	valid = false;

	while (!valid)
	{
		std::cout << "Please enter the contact index: " << std::flush;
		if (!(std::cin >> input))
			return (-1);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
		}
		else if (input < 0 || input > 7)
			std::cout << "Invalid index; please re-enter." << std::endl;
		else
			valid = true;
	}
	return (input);
}

void	PhoneBook::displayPhonebook(void) const {
	for (int i = 0; i <= 7; i++)
		phonebook[i].displayContact(i);
}

void	PhoneBook::displayContact(int index) const {
	phonebook[index].viewContact(index);
}
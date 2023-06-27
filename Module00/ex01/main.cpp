/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:22:38 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/20 17:04:17 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Phonebook.class.hpp"
#include "Contact.class.hpp"

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_addPhonebook(PhoneBook *phonebook)
{
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
	Contact		newContact;

	std::cout << "[First Name] : ";
	std::getline(std::cin, _firstName);
	std::cout << "[Last Name] : ";
	std::getline(std::cin, _lastName);
	std::cout << "[Nick Name] : ";
	std::getline(std::cin, _nickName);
	std::cout << "[Phone Number] : ";
	std::getline(std::cin, _phoneNumber);
	std::cout << "[Darkest Secret] : ";
	std::getline(std::cin, _darkestSecret);
	newContact.setContact(_firstName, _lastName, _nickName,_phoneNumber, _darkestSecret);
	(*phonebook).setPhonebookContact(newContact);
}

/*Display the saved contacts as a list of 4 columns: index, first name, last
name and nickname. */

void	displayPhonebook(PhoneBook& phonebook)
{
	std::cout << std::setw(10) << std::right << "#" << " | ";
	std::cout << std::setw(10) << std::right << "[First Name]" << " | ";
	std::cout << std::setw(10) << std::right << "[Last Name]" << " | ";
	std::cout << std::setw(10) << std::right << "[Nick Name]" << std::endl;
	for (int i = 0; i < phonebook.countContacts; i++)
	{
		phonebook.phonebook[i].printTableContact(i);
	}
}

void	ft_searchPhonebook(PhoneBook phonebook)
{
	std::string	index;
	int			contactIndex;

	displayPhonebook(phonebook);
	std::cout << "Enter contact index :";
	std::getline(std::cin, index);
	contactIndex = atoi(index.c_str());
	if (contactIndex < 8) {
		phonebook.phonebook[contactIndex].printContact();
	}
	else {
		std::cout << "Index out of range."; }
}

int	main(int argc, char **argv)  {
	
	std::string	user_command;
	Contact		firstContact;
	PhoneBook	Phonebook;

	(void)argc;
	(void)argv;

	std::cout << "Please enter a command (SEARCH / ADD / EXIT)\n> ";
	std::getline(std::cin, user_command);
	while (!std::cin.eof())
	{
		if (user_command == "ADD") {
			ft_addPhonebook(&Phonebook); }
		else if (user_command == "SEARCH") {
			ft_searchPhonebook(Phonebook); }
		else if (user_command == "EXIT") {
			return (0); }
		else if (!std::cin.eof()) {
			std::cout << "Only ADD, SEARCH and EXIT commands are accepted\n"; }
		std::cout << std::endl;
		std::cout << "Please enter a command (SEARCH / ADD / EXIT)\n> ";
		std::getline(std::cin, user_command);
	}	
}

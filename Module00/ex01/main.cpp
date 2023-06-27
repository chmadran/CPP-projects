/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:16:29 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/27 17:47:49 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iomanip>

void	ft_add(PhoneBook *phonebook, int i)
{
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

	std::cout << "FIRST NAME : ";
	std::cin >> _firstName;
	std::cout << "LAST NAME : ";
	std::cin  >>  _lastName;
	std::cout << "NICK NAME : ";
	std::cin  >>  _nickName;
	std::cout << "PHONE NUMBER : ";
	std::cin  >>  _phoneNumber;
	std::cout << "DARKEST SECRET : ";
	std::cin  >>  _darkestSecret;
	
	(*phonebook).addContact(i, _firstName, _lastName, _nickName,_phoneNumber, _darkestSecret);
}

std::string	ft_display_line(std::string input) {
	if (input.length() >= 10)
	{
		input.resize(9);
		input.resize(10, '.');
	}
	return input;
}

void	ft_display_contact(PhoneBook *phonebook, int indexSearched)
{
	(*phonebook).getContact(indexSearched).printContact();
}

int	ft_display_phonebook(PhoneBook *phonebook, int size) {
	
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;

	// HEADER
	std::cout << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl << std::endl;

	for (int i = 0; i < size; i++) {
		_firstName = ft_display_line((*phonebook).getFirstName(i));
		_lastName = ft_display_line((*phonebook).getLastName(i));
		_nickName = ft_display_line((*phonebook).getNickName(i));
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << _firstName << "|";
		std::cout << std::setw(10) << _lastName << "|";
		std::cout << std::setw(10) << _nickName<< "|" << std::endl;
	}
	return (1);
}

void	ft_search(PhoneBook *phonebook, int i) {
		int	indexSearched;

		if (ft_display_phonebook(phonebook, i)) {
			std::cout << std::endl << "Enter the INDEX of the user you're looking for :" << std::endl;
			std::cin >> indexSearched;
			std::cout << std::endl;
			if (indexSearched >= 0 && indexSearched <= i)
				ft_display_contact(phonebook, indexSearched);
			else
				std::cout << "Incorrect Index. Retry.";
		}
}

int main(void){
	
	int				i = 0;
	PhoneBook		phonebook;
	std::string 	user_input;

	while (1)
	{
		std::cout << "ENTER VALID ARGUMENT(ADD, SEARCH, EXIT) : ";
		std::cin >> user_input;
		if (user_input == "ADD")
		{
			if (i >= 7) {
				std::cout << "Cannot add more than 8 contacts. Oldest one will be replaced." << std::endl;
				i = 0;
			}
			ft_add(&phonebook, i);
			i++;
		}
		else if (user_input == "SEARCH")
			ft_search(&phonebook, i);
		else if (user_input == "EXIT")
			return 0;
		else 
			std::cout << "Invalid argument. Enter new one.";
		std::cout << std::endl;
	}
}
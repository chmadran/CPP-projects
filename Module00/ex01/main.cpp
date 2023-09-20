/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:16:29 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 14:02:27 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iomanip>

void	ft_add(PhoneBook *phonebook)
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
	(*phonebook).addContact(_firstName, _lastName, _nickName,_phoneNumber, _darkestSecret);
}

void	ft_search(PhoneBook phonebook)
{
		int	indexSearched;

		phonebook.displayPhonebook();
		indexSearched = phonebook.readIndex();
		if (indexSearched == -1)
			return ;
		phonebook.displayContact(indexSearched);
}

int main(void)
{
	PhoneBook		phonebook;
	std::string 	userInput = "";

	phonebook.begin();
	while(userInput.compare("EXIT"))
	{
		if (userInput.compare("ADD") == 0)
			ft_add(&phonebook);
		else if (userInput.compare("SEARCH") == 0)
			ft_search(phonebook);
		std::cout << "> " << std::flush;
		if (!(std::cin >> userInput))
			return (1);
	}
	return (0);
}
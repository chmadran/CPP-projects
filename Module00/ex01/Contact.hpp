/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:30:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/27 15:25:35 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact {
	public:
		Contact();
		~Contact();

		void	setContact(std::string fn, std::string ln, std::string nn, 
			std::string pn, std::string ds);
		
		void		printContact() const;
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_phoneNumber;
		std::string	_nickName;
		std::string	_darkestSecret;
};

#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:30:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 11:28:01 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>

class Contact {
	public:
		Contact(void);
		~Contact(void);

		void		setContact(std::string fn, std::string ln, std::string nn, 
			std::string pn, std::string ds);
		void		displayContact(int index) const;
		void		viewContact(int index) const;
		std::string	printLen(std::string str) const;
		
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_phoneNumber;
		std::string	_nickName;
		std::string	_darkestSecret;
};

#endif


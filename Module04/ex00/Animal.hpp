/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:43:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:13:32 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &original);
		virtual ~Animal(void);

		Animal& operator=(const Animal &original);

		virtual std::string	getType(void) const;
		virtual void makeSound(void) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:00:52 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:23:14 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>
# include <string>

class WrongAnimal {
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &original);
		virtual ~WrongAnimal(void);

		WrongAnimal& operator=(const WrongAnimal &original);

		std::string	getType(void) const;
		void makeSound(void) const;
};

#endif
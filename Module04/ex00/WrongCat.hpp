/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:59:31 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/26 14:03:57 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	private:
		std::string type;
	public:
		WrongCat();
		WrongCat(const WrongCat& rhs);
		WrongCat& operator=(const WrongCat& rhs);
		~WrongCat();
		
		void	makeSound() const;
		std::string	getType() const;
};

#endif
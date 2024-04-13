/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:59:31 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:32:44 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat &original);
		virtual ~WrongCat(void);

		WrongCat& operator=(const WrongCat &original);
		
		virtual void	makeSound(void) const;
};

#endif
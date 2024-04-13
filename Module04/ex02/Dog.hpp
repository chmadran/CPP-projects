/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:54:27 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:53:51 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	public:
		Dog(void);
		Dog(const Dog &original);
		~Dog(void);

		Dog& operator=(const Dog &original);
		
		virtual	void	makeSound(void) const;
		virtual	Brain	*getBrain(void) const;

	private:
		Brain*	_brain;
};

#endif
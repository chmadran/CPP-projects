/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:43:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 18:28:02 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>
# include <string>
# include "Brain.hpp"

class AAnimal {
	protected:
		std::string	_type;

	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal &original);
		virtual ~AAnimal(void);

		AAnimal& operator=(const AAnimal &original);

		std::string		getType() const;
		virtual	Brain*	getBrain(void) const = 0;
		virtual void	makeSound() const;
};

#endif
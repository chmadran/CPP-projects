/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:43:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/26 14:55:35 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>
# include <string>

class AAnimal {
	protected:
		std::string	type;

	public:
		AAnimal();
		AAnimal(const AAnimal& rhs);
		AAnimal& operator=(const AAnimal& rhs);
		virtual ~AAnimal();

		virtual std::string	getType() const;
		virtual void makeSound() const;
};

#endif
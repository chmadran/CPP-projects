/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:54:27 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:53:56 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"


class Cat : virtual public AAnimal {
	public:
		Cat(void);
		Cat(const Cat &original);
		Cat& operator=(const Cat &original);
		~Cat(void);
		
		virtual void	makeSound() const;
		virtual Brain	*getBrain( void ) const ;
	
	private:
		Brain *_brain;
};

#endif
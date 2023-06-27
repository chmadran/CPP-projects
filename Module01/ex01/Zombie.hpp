/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:55:22 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 17:18:15 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H 
# define ZOMBIE_H

# include <iostream>
# include <iomanip>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(const std::string& name = "");
		~Zombie();
	
	void	annouce();
};

Zombie* zombieHorde( int N, std::string name );

#endif
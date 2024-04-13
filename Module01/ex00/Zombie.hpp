/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:43:36 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 14:05:57 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <iostream>
# include <iomanip>

class Zombie {
	public:
		Zombie(const std::string& name);
		~Zombie(void);
		
		void	announce(void);
	private: 
		std::string		_name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
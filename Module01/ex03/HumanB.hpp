/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:27:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 16:59:08 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {
	private:
		Weapon* 	_weapon;
		std::string _name;

	public:
		HumanB(std::string name);
		~HumanB();

		void	setWeapon(Weapon& weapon);
		void	attack( void );
};

#endif
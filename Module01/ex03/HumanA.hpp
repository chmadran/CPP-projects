/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:26:59 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 16:58:12 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void	attack(void);

	private:
		std::string		_name;
		Weapon&			_weapon;
};

#endif
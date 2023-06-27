/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:26:59 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 12:12:25 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA {
public:
	std::string		name;
	Weapon			weapon;

	HumanA(std::string name, Weapon weapon);
	~HumanA();

	void	attack( void );
};

#endif
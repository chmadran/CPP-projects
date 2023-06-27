/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:52:45 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/23 10:22:12 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap {
protected:
	ClapTrap();
	
	std::string		name;
	int				hitPoints;
	int				energyPoints;
	int				attackDamage;

public:
	ClapTrap(std::string input);
	ClapTrap(ClapTrap const & rhs);
	ClapTrap &	operator=(ClapTrap const & nbr);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
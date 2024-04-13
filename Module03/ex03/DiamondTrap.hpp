/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:35:20 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 13:28:11 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap {
private:
	std::string _name;

public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &original);
	~DiamondTrap(void);

	DiamondTrap& operator=(const DiamondTrap &original);

	void	whoAmI(void);
	void	attack(const std::string &target);
};

#endif
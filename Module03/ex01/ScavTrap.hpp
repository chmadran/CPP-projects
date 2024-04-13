/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:54:37 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 11:03:02 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

# define SCAV_HP 100
# define SCAV_EP 50
# define SCAV_DAM 20

class ScavTrap : public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &original);
	~ScavTrap(void);

	ScavTrap& operator=(const ScavTrap &original);
	
	void	attack(const std::string& target);
	void	guardGate(void);
};

#endif
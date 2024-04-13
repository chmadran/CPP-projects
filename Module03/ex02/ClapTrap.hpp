/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:52:45 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 13:44:53 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

# define HPMAX 10
# define EPMAX 10
# define ADAMAGE 0

class ClapTrap {

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &original);
	~ClapTrap(void);

	ClapTrap&	operator=(ClapTrap const &original);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	int		getDamage( void ) const;
	
protected:
	std::string		_name;
	int				_hitPoints;
	int				_energyPoints;
	int				_attackDamage;

};

#endif
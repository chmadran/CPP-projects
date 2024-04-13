/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:53:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 13:55:04 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << std::endl;
	std::cout << "=================CLAP===================" << std::endl;
	// Create an instance of ClapTrap
	ClapTrap clapTrap("Clappy");

	// Test attack, takeDamage, and beRepaired member functions of ClapTrap
	clapTrap.attack("Enemy");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	
	std::cout << std::endl;
	std::cout << "=================SCAV===================" << std::endl;
	// Create an instance of ScavTrap
	ScavTrap scavTrap("Scavvy");
	// Test attack, takeDamage, and beRepaired member functions of ScavTrap
	scavTrap.attack("Enemy");
	scavTrap.takeDamage(7);
	scavTrap.beRepaired(2);
	std::cout << std::endl;
	std::cout << "=================THE END=================" << std::endl;
}
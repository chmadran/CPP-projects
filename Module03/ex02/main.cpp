/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:53:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 13:52:05 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	std::cout << std::endl;
	std::cout << "===========CLAP CONSTRUCTION================" << std::endl;
	ClapTrap	claptrap("Clappy");
	std::cout << std::endl;
	std::cout << "===========SCAV CONSTRUCTION================" << std::endl;
	ScavTrap	scavtrap("Scavy");
	std::cout << std::endl;
	std::cout << "===========FRAG CONSTRUCTION================" << std::endl;
	FragTrap	fragtrap("Fraggy");
	std::cout << std::endl;

	std::cout << std::endl;
	claptrap.attack("Scavy");
	scavtrap.takeDamage(scavtrap.getDamage());
	std::cout << std::endl;
	scavtrap.attack("Fraggy");
	fragtrap.takeDamage(fragtrap.getDamage());
	std::cout << std::endl;
	fragtrap.attack("Clappy");
	claptrap.takeDamage(claptrap.getDamage());
	std::cout << "===========================" << std::endl;
	std::cout << std::endl;
	scavtrap.guardGate();
	fragtrap.highFivesGuys();
	std::cout << std::endl;
	std::cout << "=============THE END============" << std::endl;

	return (0);
}
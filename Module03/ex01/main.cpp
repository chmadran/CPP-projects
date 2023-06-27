/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:53:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/22 18:17:59 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Create an instance of ClapTrap
    ClapTrap clapTrap("Clappy");

    // Test attack, takeDamage, and beRepaired member functions of ClapTrap
    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);

    // Create an instance of ScavTrap
    ScavTrap scavTrap("Scavvy");

    // Test attack, takeDamage, and beRepaired member functions of ScavTrap
    scavTrap.attack("Enemy");
    scavTrap.takeDamage(7);
    scavTrap.beRepaired(2);

    return 0;
}
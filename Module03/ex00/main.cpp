/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:53:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/22 17:48:03 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    // Create two instances of ClapTrap
    ClapTrap clapTrap1("ClapTrap1");
    ClapTrap clapTrap2("ClapTrap2");

    // Test 1: Perform an attack
    clapTrap1.attack("Target"); // ClapTrap1 attacks Target causing 5 points of damage

    // Test 2: Take damage
    clapTrap2.takeDamage(3); // ClapTrap2 gets attacked losing 3 points of damage

    // Test 3: Attempt to attack when out of energy
    clapTrap1.attack("Target"); // ClapTrap1 is out of energy and cannot attack

    // Test 4: Be repaired
    clapTrap1.beRepaired(4); // ClapTrap1 repairs itself and gets 4 hit points back

    // Test 5: Attempt to be repaired when out of energy
    clapTrap2.beRepaired(2); // ClapTrap2 is out of energy and cannot be repaired

    // Test 6: Perform additional attacks
    clapTrap1.attack("Target"); // ClapTrap1 attacks Target causing 5 points of damage
    clapTrap2.attack("Target"); // ClapTrap2 attacks Target causing 5 points of damage

    return 0;
}
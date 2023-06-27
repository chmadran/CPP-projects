/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:53:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/23 09:40:06 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // Create an instance of ClapTrap
    ClapTrap clapTrap("Clappy");

    // Test attack, takeDamage, and beRepaired member functions of ClapTrap
    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);

    // Create an instance of ScavTrap
    FragTrap fragTrap("Fraggy");

    // Test attack, takeDamage, and beRepaired member functions of fragTrap
    fragTrap.attack("Enemy");
    fragTrap.takeDamage(7);
    fragTrap.beRepaired(2);

    return 0;
}
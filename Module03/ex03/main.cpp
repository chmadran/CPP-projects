/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:53:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 14:14:05 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void){
	DiamondTrap		diamond("Diamond");

	std::cout << "===========================" << std::endl;
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
	std::cout << "===========================" << std::endl;

	return (0);
}
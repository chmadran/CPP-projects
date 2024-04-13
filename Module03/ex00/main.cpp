/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:53:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 13:58:26 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void){

	std::cout << std::endl;
	std::cout << "=========================================" << std::endl;
	ClapTrap	claptrap1("claptrap1");
	std::cout << "=========================================" << std::endl;
	ClapTrap	claptrap2("claptrap2");
	std::cout << "=========================================" << std::endl;
	
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		claptrap1.attack("claptrap2");
		claptrap2.takeDamage(0);
		claptrap2.beRepaired(0);
		std::cout << std::endl;
		std::cout << "=========================================" << std::endl;
	}
}
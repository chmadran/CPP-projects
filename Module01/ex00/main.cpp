/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:49:22 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 16:17:42 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Zombie.hpp"

int main()
{
	std::string name;

	std::cout << "zombie on the stack, give it a name : ";
	if (!(std::cin >> name))
		return (1);
	Zombie zonzon1(name);
	zonzon1.announce();

	std::cout << "zombie on the heap, give it a name : ";
	if (!(std::cin >> name))
		return (1);
	Zombie *zonzon2 = newZombie(name);
	delete zonzon2;

	std::cout << "random zombie generator, on the stack, give it a name : ";
	if (!(std::cin >> name))
		return (1);
	randomChump(name);
}
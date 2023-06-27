/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:49:22 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 17:29:22 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Zombie.hpp"

int main(){
	std::string name;
	
	std::cout << "zombie on the stack, give it a name : " << std::endl;
	std::cin >> name;
	Zombie zonzon1(name);
	zonzon1.announce();

	std::cout << "zombie on the heap, give it a name : "<< std::endl;
	std::cin >> name;
	Zombie *zonzon2 = newZombie(name);
	delete zonzon2;

	std::cout << "random zombie generator, on the stack, give it a name : " << std::endl;
	std::cin >> name;
	randomChump(name);
}
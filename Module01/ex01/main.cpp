/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:05:25 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 17:18:47 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int		N;
	std::cout << "Enter the number of zombies in the hord, please: ";
	std::cin >> N;
	
	Zombie	*zombies = zombieHorde(N, "zombi");
	for (int i = 0; i < N; i++) {
		zombies[i].annouce();
	}

	delete [] zombies;
	return 0;
}
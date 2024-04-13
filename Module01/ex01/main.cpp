/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:05:25 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/22 13:55:44 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
	int		N;
	Zombie	*zombies;
	
	N = 5; 
	if (N <= 0)
		return (1);
	zombies = zombieHorde(N, "zombi");
	for (int i = 0; i < N; i++) {
		zombies[i].announce();
	}
	delete [] zombies;
	return (0);
}
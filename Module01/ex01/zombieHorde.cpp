/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:58:40 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/22 13:54:49 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie *newZombie = new (std::nothrow) Zombie[N]; // Allocate an array of N Zombie objects
    
   	if (!newZombie)
		return (NULL);
	for (int i = 0; i < N; i++) {
        newZombie[i] = Zombie(name); // Initialize each Zombie object with the given name
    }
    
    return newZombie;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:41:09 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/09 14:53:40 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define CR std::cout << std::endl;

int	main(int ac, char **av)
{
	PmergeMe	pmm;

	if (ac > 1)
	{
		try {
			pmm.validArray(ac, av);
		}
		catch(const std::exception& e)
			{
			std::cerr << "Error : " << e.what() << '\n';
			return (EXIT_FAILURE);
		}
		
		pmm.launchVector(ac, av);
		CR;
		pmm.launchDeque(ac, av);
		return (EXIT_SUCCESS);
	}
	else
		std::cout << "Error: Wrong amount of arguments." << std::endl;
	return (EXIT_FAILURE);
}
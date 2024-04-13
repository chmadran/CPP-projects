/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:29:50 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/09 14:33:51 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Error, wrong number of arguments." << std::endl;
	else
	{
		try {
			RPN	rpn(av[1]);	
		}
		catch(const std::exception& e)
		{
		std::cerr << "Error : " << e.what() << '\n';
		return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
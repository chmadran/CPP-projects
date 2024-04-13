/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:36:51 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 12:10:39 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CR std::cout << std::endl;

#include <ctime>
#include "Base.hpp"


int main()
{
	std::srand(time(NULL)); 
	Base	*base1 = generate();
	Base	*base2 = generate();
	Base	*base3 = generate();

	CR;
	identify(base1);
	identify(base2);
	identify(base3);
	CR;
	std::cout << "=================" << std::endl;
	CR;
	identify(*base1);
	identify(*base2);
	identify(*base3);
	CR;

	delete base1;
	delete base2;
	delete base3;
}
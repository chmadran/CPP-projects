/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:26:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 11:36:19 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base	*generate(void)
{
	switch (std::rand() % 3) 
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (nullptr);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object is Type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object is Type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object is Type C" << std::endl;
	else
		std::cerr << "Object is from unknowned type" << std::endl;
}

void	identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "Object is Type A" << std::endl;
		return ;
	}
	catch (std::bad_cast& e){
		(void)e;
	}
	try {
		dynamic_cast<B&>(p);
		std::cout << "Object is Type B" << std::endl;
		return ;
	}
		catch (std::bad_cast& e){
		(void)e;
	}
	try {
		dynamic_cast<C&>(p);
		std::cout << "Object is Type C" << std::endl;
		return ;
	}
		catch (std::bad_cast& e){
		(void)e;
	}
	std::cerr << "Object is from unknowned type" << std::endl;
}

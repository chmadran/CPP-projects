/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:48 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/28 12:41:58 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CR std::cout << std::endl;
#define HEADER(msg) std::cout << "------------- " << msg << " ------------- " << std::endl;

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bureaucrat1("John", 149);
	std::cout << "Hello world, my name is ";
	std::cout << bureaucrat1.getName() << std::endl;
	
	CR;
	HEADER("TEST <<");

	Bureaucrat bureaucrat2("Liam", 140);
	std::cout << bureaucrat2;

	CR;
	HEADER("GRADE TOO HIGH");

	Bureaucrat bureaucrat3("Noah", -1);
	std::cout << bureaucrat3;

	CR;
	HEADER("GRADE TOO LOW");

	Bureaucrat bureaucrat4("Oliver", 160);
	std::cout << bureaucrat4;

	CR;
	HEADER("INCREMENTING");

	Bureaucrat bureaucrat5("Elijah", 10);
	bureaucrat5.incrementGrade();
	std::cout << bureaucrat5;

	CR;
	HEADER("DECREMENTING");

	Bureaucrat bureaucrat6("James", 10);
	bureaucrat6.decrementGrade();
	std::cout << bureaucrat6;

	CR;
	HEADER("END OF PROGRAMME");	
}
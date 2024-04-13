/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:51:15 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/29 09:46:03 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define CR std::cout << std::endl;
#define HEADER(msg) std::cout << "------------- " << msg << " ------------- " << std::endl;

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	CR;
	HEADER("👨‍💼 CREATION OF A BUREAUCRAT 👨‍💼");
	CR;
	Bureaucrat bureaucrat1("John", 27);
	std::cout << "Hello world, my name is ";
	std::cout << bureaucrat1.getName() << std::endl;
	std::cout << "I'm the first bureaucrat out here." << std::endl;
	
	CR;
	HEADER("TEST <<");
	CR;
	std::cout << "The bureaucrat's informations are as follows : " << std::endl;
	std::cout << bureaucrat1;

	CR;
	HEADER("📝 CREATION OF 3 FORMS 📝");
	CR;
	ShrubberyCreationForm shrubberyForm("ex02");
	std::cout << shrubberyForm;

	CR;
	RobotomyRequestForm robotomyForm("Liam");
	std::cout << robotomyForm;

	CR;
	PresidentialPardonForm presidentialForm("Vincent");
	std::cout << presidentialForm;

	CR;
	HEADER("📝 SIGNING OF 3 FORMS 📝");
	CR;
	try
	{
		bureaucrat1.signForm(presidentialForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	CR;
	try
	{
		bureaucrat1.signForm(robotomyForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	CR;
	try
	{
		bureaucrat1.signForm(shrubberyForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	CR;

	
	HEADER("👩‍🔧 EXECUTION OF 3 FORMS 👩‍🔧");
	CR;
	try
	{
		presidentialForm.execute(bureaucrat1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	CR;
	try
	{
		robotomyForm.execute(bureaucrat1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	CR;
	try
	{
		shrubberyForm.execute(bureaucrat1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	CR;
	HEADER("END OF THE PROGRAMME");
}
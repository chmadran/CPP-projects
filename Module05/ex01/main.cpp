/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:48 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/28 14:51:25 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CR std::cout << std::endl;
#define HEADER(msg) std::cout << "------------- " << msg << " ------------- " << std::endl;

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	CR;
	HEADER("👨‍💼 CREATION OF A BUREAUCRAT 👨‍💼");
	Bureaucrat bureaucrat1("John", 74);
	std::cout << "Hello world, my name is ";
	std::cout << bureaucrat1.getName() << std::endl;
	std::cout << "I'm the first bureaucrat out here." << std::endl;

	CR;
	HEADER("📝 CREATION OF A FORM 📝");
	Form form1("Information Form", false, 75, 75);
	
	CR;
	HEADER("TEST <<");
	std::cout << "The bureaucrat's informations are as follows : " << std::endl;
	std::cout << bureaucrat1;
	CR;
	std::cout << "The form's informations are as follows : " << std::endl;
	std::cout << form1;
	
	CR;
	HEADER("TEST CAN SIGN");
	bureaucrat1.signForm(form1);

	CR;
	HEADER("TEST CANT SIGN");
	Bureaucrat bureaucrat2("Emile", 76);
	Form form2("Another Form", false, 75, 100);
	bureaucrat2.signForm(form2);

	CR;
	HEADER("END OF PROGRAMME");	
}
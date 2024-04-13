/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:51:15 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/29 10:27:03 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define CR std::cout << std::endl;
#define HEADER(msg) std::cout << "------------- " << msg << " ------------- " << std::endl;

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat	Emilie("Emilie", 4);
	Intern		Julien;
	AForm		*form = NULL;
	std::string	nameForm[4] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation",
		"404"
	};

	std::cout << "===========================" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		try {
			form = Julien.makeForm(nameForm[i], "Random Target");
			Emilie.signForm(*form);
			Emilie.executeForm(*form);
			delete form;
			std::cout << "===========================" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		CR;
	}
}
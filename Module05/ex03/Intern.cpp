/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:48:37 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/29 10:16:16 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/************************************************************
 *				CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

Intern::Intern(void)
{
	//std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	(void)src;
	//std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
	//std::cout << "Intern default destructor called" << std::endl;
}

/************************************************************
 *						OTHER	 						*
 ************************************************************/

Intern	&Intern::operator=(Intern const &src)
{
	(void)src;
	return (*this);
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm *newForm = NULL;
	
	const char* formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm* forms[3] = {
		new PresidentialPardonForm(target),
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target)
	};

	for (int i = 0; i < 3; ++i)
	{
		if (name == formNames[i])
			newForm = forms[i];
		else
			delete forms[i];
	}	
	if (!newForm)
		throw Intern::FormNotFound();
	std::cout << "Intern creates a " << name << " form." << std::endl; 
	return (newForm);
}

/************************************************************
 *						EXCEPTION	 						*
 ************************************************************/

const char * Intern::FormNotFound::what() const throw()
{
	return("Form cannot be found.");
}
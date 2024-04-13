/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:12:53 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/29 09:37:17 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/************************************************************
 *				CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

PresidentialPardonForm::PresidentialPardonForm(void) 
: AForm("PresidentialPardonForm", false, 25, 5), _target("Default Target"){
	//std::cout << "PresidentialPardonForm default constructor is called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("Presidential Form", false, 25, 5), _target(target) 
{
	//std::cout << "PresidentialPardonForm string constructor is called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src)
:  AForm(src.getName(), src.getState(), src.getSignGrade(), src.getExecGrade()), _target(src.getName())
{
	//std::cout << "PresidentialPardonForm copy constructor is called." << std::endl;
};

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm & src){
	if (this != &src)
		_target = src._target;
	return (*this);
};

PresidentialPardonForm::~PresidentialPardonForm(void){
	std::cout << "PresidentialPardonForm default destructor is called." << std::endl;
}

/************************************************************
 *						EXECUTION							*
 ************************************************************/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getState() && executor.getGrade() <= this->getExecGrade())
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else if (!this->getState())
		throw AForm::FormNotSigned();
	else
		throw AForm::GradeTooLowException();
}
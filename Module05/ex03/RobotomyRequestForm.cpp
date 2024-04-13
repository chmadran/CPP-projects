/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:07:30 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/29 10:22:22 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/************************************************************
 *				CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

RobotomyRequestForm::RobotomyRequestForm(void) 
: AForm("RobotomyRequestForm", false, 72, 45), _target("Default target") {
	//std::cout << "RobotomyRequestForm default contructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("Robotomy Request Form", false, 72, 45), _target(target) 
{
	//std::cout << "RobotomyRequestForm string contructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
:  AForm(src.getName(), src.getState(), src.getSignGrade(), src.getExecGrade()), _target(src.getName())
{ 
	//std::cout << "RobotomyRequestForm copy contructor called." << std::endl;
};

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src){
	if (this != &src)
		_target = src._target;
	return (*this);
};

RobotomyRequestForm::~RobotomyRequestForm(void) {
	//std::cout << "RobotomyRequestForm default destructor called." << std::endl;
}

/************************************************************
 *						EXECUTION							*
 ************************************************************/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getState() && executor.getGrade() <= this->getExecGrade())
	{
		std::cout << "👷🏼 [DRILLING NOISES] 👷🏼" << std::endl;
		std::srand(time(NULL)); 
		if ((std::rand()) % 2 == 0)
			std::cout << _target << " has been robotomized " << std::endl;
		else
			std::cout << "Robotomy has failed." << std::endl;
	}
	else if (!this->getState())
		throw AForm::FormNotSigned();
	else
		throw AForm::GradeTooLowException();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:03:09 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/29 10:22:27 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/************************************************************
 *				CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(void) : 
 AForm("Shrubbery Creation Form", false, 145, 137), _target("Default Target")
{
	//std::cout << "SchrubberyCreationForm default contructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: AForm("Shrubbery Creation Form", false, 147, 137), _target(target) 
{
	//std::cout << "ShrubberyCreationForm string contructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
:  AForm(src.getName(), src.getState(), src.getSignGrade(), src.getExecGrade()), _target(src.getName())
{
	//std::cout << "ShrubberyCreationForm copy contructor called." << std::endl;
};

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src){
	if (this != &src)
		_target = src._target;
	return (*this);
};

ShrubberyCreationForm::~ShrubberyCreationForm(void){
	//std::cout << "SchrubberyCreationForm default destructor called." << std::endl;
}

/************************************************************
 *						EXECUTION							*
 ************************************************************/

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getState() && executor.getGrade() <= this->getExecGrade())
	{
		std::cout << "📂 [CREATING A FILE] 📂" << std::endl;
		std::ofstream	outfile;
		outfile.open((_target + "_shrubbery").c_str());
		if (outfile.is_open())
		{
			outfile << "ASCII TREE 1\n";
			outfile << "   /\\\n";
			outfile << "  /__\\\n";
			outfile << " /\\  /\\ \n";

			outfile << "\nASCII TREE 2\n";
			outfile << "   ||\n";
			outfile << "   ||\n";
			outfile << "   ||\n";

			outfile.close();
			std::cout << "🌲 ASCII trees written to " << (_target + "_shrubbery") << " 🌲" << std::endl;
		}
		else
		{
			std::cerr << "Error: Unable to open file " << (_target + "_shrubbery") << std::endl;
		}
	}
	else if (!this->getState())
		throw AForm::FormNotSigned();
	else
		throw AForm::GradeTooLowException();
}

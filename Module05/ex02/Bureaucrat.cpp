/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:46:09 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/28 17:24:47 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/************************************************************
 *				CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

Bureaucrat::Bureaucrat(void) : _name("Nom par defaut"), _grade(0) {
	//std::cout << "Bureaucrat default constructor called." << std::endl;
};

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	try
	{
		if (grade < 1) {
			throw GradeTooHighException();
		}
		else if (grade > 150) {
			throw GradeTooLowException();
		}
		else {
			_grade = grade;
		}
	}
	catch (GradeTooHighException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (GradeTooLowException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	//std::cout << "Bureaucrat string constructor called." << std::endl;
};

Bureaucrat::Bureaucrat(Bureaucrat const &original) : _name(original._name)
{
	//std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = original;
};

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat default destructor called." << std::endl;
};


/************************************************************
 *						GETTERS/OTHERS	 						*
 ************************************************************/

int					Bureaucrat::getGrade(void) const
{
	return (_grade);
};

std::string const	Bureaucrat::getName(void) const 
{
	return (_name);
};

void				Bureaucrat::incrementGrade(void) 
{
	if (_grade == 1)
		throw(GradeTooHighException());
	else
		_grade--;	
};

void				Bureaucrat::decrementGrade(void) 
{
	if (_grade == 150)
		throw(GradeTooLowException());
	else
		_grade++;
};

void				Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed the " << form.getName() << "." << std::endl;
	}
	catch (std::exception &e ){
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const &form)
{
	try 
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " could not execute " << form.getName()
			<< " due to " << e.what() << std::endl;
	}
}

/************************************************************
 *						EXCEPTIONS	 						*
 ************************************************************/

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high !");
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low !");
};

/************************************************************
 *						OPERATORS	 						*
 ************************************************************/

Bureaucrat		&Bureaucrat::operator=(Bureaucrat const &original)
{
	//std::cout << "Bureaucrat assignation constructor called." << std::endl;
	if (this != &original)
		_grade = original._grade;
	return (*this);
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat const &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat, grade ";
	o << bureaucrat.getGrade() << "." << std::endl;
	return (o);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:48:59 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/29 09:05:58 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/************************************************************
 *				CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

Form::Form() : _name("DEFAULT FORM NAME"), _signed(false), _signGrade(0), _execGrade(0) {
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(std::string const name, bool sign, int const signGrade, int const execGrade) : 
	_name(name), _signed(sign), _signGrade(signGrade), _execGrade(execGrade) 
{
	if (_signGrade > 150)
		throw Form::GradeTooLowException();
	else if (_signGrade < 1)
		throw Form::GradeTooHighException();
	if (_execGrade > 150)
		throw Form::GradeTooLowException();
	else if (_execGrade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form string constructor called." << std::endl;
}

Form::Form (Form const &original) :
	_name(original._name), _signed(original._signed), _signGrade(original._signGrade), _execGrade(original._execGrade)
{
	std::cout << "Copy constructor called." << std::endl;
}

Form::~Form() {
	std::cout << "Form default destructor called." << std::endl;
}

/************************************************************
 *						GETTERS	 						*
 ************************************************************/

std::string const	Form::getName(void) const {
	return (_name);
}

bool				Form::getState(void) const {
	return (_signed);
}

int const			Form::getSignGrade(void) const {
	return (_signGrade);
}

int const			Form::getExecGrade(void) const {
	return (_execGrade);
}

/************************************************************
 *						OTHER	 						*
 ************************************************************/

void				Form::beSigned(Bureaucrat signatory) {
	if (signatory.getGrade() <= _signGrade)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

/************************************************************
 *						EXCEPTIONS	 						*
 ************************************************************/

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

/************************************************************
 *						OPERATORS	 						*
 ************************************************************/

Form			&Form::operator=(Form const &form)
{
	if (this != &form)
	{
		_signed = form.getState();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Form const &form)
{
	o << "[FORM NAME] : " << form.getName() << std::endl;
	o << "[FORM STATE] : " << (form.getState() ? "signed" : "not signed") << std::endl;
	o << "[SIGN GRADE] : " << form.getSignGrade() << std::endl;
	o << "[EXEC GRADE] : " << form.getExecGrade() << std::endl;
	return (o);
}
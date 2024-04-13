/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:48:59 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/29 09:40:45 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/************************************************************
 *				CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

AForm::AForm() : _name("DEFAULT AFORM NAME"), _signed(false), _signGrade(0), _execGrade(0) {
	//std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm(std::string const name, bool sign, int const signGrade, int const execGrade) : 
	_name(name), _signed(sign), _signGrade(signGrade), _execGrade(execGrade) 
{
	if (_signGrade > 150)
		throw AForm::GradeTooLowException();
	else if (_signGrade < 1)
		throw AForm::GradeTooHighException();
	if (_execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (_execGrade < 1)
		throw AForm::GradeTooHighException();
	//std::cout << "AForm string constructor called." << std::endl;
}

AForm::AForm (AForm const &original) :
	_name(original._name), _signed(original._signed), _signGrade(original._signGrade), _execGrade(original._execGrade)
{
	//std::cout << "Copy constructor called." << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm default destructor called." << std::endl;
}

/************************************************************
 *						GETTERS	 						*
 ************************************************************/

std::string const	AForm::getName(void) const {
	return (_name);
}

bool				AForm::getState(void) const {
	return (_signed);
}

int const			AForm::getSignGrade(void) const {
	return (_signGrade);
}

int const			AForm::getExecGrade(void) const {
	return (_execGrade);
}

/************************************************************
 *						OTHER	 						*
 ************************************************************/

void				AForm::beSigned(Bureaucrat signatory) {
	if (signatory.getGrade() <= _signGrade)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

/************************************************************
 *						EXCEPTIONS	 						*
 ************************************************************/

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

const char*	AForm::FormNotSigned::what() const throw() {
	return ("Form has not been signed, bureaucrat's grade is not high enough.");
}

/************************************************************
 *						OPERATORS	 						*
 ************************************************************/

AForm			&AForm::operator=(AForm const &form)
{
	if (this != &form)
		_signed = form.getState();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, AForm const &form)
{
	o << "[FORM NAME] : " << form.getName() << std::endl;
	o << "[FORM STATE] : " << (form.getState() ? "signed" : "not signed") << std::endl;
	o << "[SIGN GRADE] : " << form.getSignGrade() << std::endl;
	o << "[EXEC GRADE] : " << form.getExecGrade() << std::endl;
	return (o);
}
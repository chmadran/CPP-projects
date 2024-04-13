/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:45:49 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/29 09:36:09 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(std::string const _name, bool sign, int const signGrade, int const execGrade);
		AForm (AForm const &original);
		virtual ~AForm();

		std::string const	getName(void) const;
		bool				getState(void) const;
		int const			getSignGrade(void) const;
		int const			getExecGrade(void) const;
		void				beSigned(Bureaucrat signatory);
		virtual void		execute(Bureaucrat const &executor) const = 0;

		AForm &operator=(AForm const &original);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSigned: public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
};

std::ostream	&operator<<(std::ostream &o, AForm const &form);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:45:49 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/28 14:20:46 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form();
		Form(std::string const _name, bool sign, int const signGrade, int const execGrade);
		Form (Form const &original);
		~Form();

		std::string const	getName(void) const;
		bool				getState(void) const;
		int const			getSignGrade(void) const;
		int const			getExecGrade(void) const;
		void				beSigned(Bureaucrat signatory);

		Form &operator=(Form const &original);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
};

std::ostream	&operator<<(std::ostream &o, Form const &form);

#endif
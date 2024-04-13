/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:46:06 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/28 14:19:41 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &original);
		~Bureaucrat();
		
		int					getGrade(void) const;
		std::string	const 	getName(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form &form);

		Bureaucrat &operator=(Bureaucrat const &original);
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif
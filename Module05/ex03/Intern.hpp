/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:48:40 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/29 10:00:11 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern {
	public: 
		Intern(void);
		Intern(const Intern &src);
		~Intern(void);

		Intern &operator=(Intern const &src);

		bool	checkFormName(std::string name);
		AForm	*makeForm(std::string name, std::string target);

		class FormNotFound : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:11:10 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/28 16:24:50 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &src);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

#endif
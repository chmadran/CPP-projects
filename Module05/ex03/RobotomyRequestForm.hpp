/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:07:36 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/28 16:27:15 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const & executor) const;

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &src);

	private:
		std::string	_target;
};

#endif
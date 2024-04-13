/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:03:12 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/28 16:31:49 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class Aform;

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const & executor) const;

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &src);

	private:
		std::string	_target;
};

#endif

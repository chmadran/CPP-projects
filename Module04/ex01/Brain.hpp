/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:12:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/26 14:30:13 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
# include <string>

class Brain {
	private:
		std::string	*ideas;
	public:
		Brain();
		Brain(Brain& rhs);
		Brain operator=(const Brain &rhs);
		~Brain();
		std::string *getIdeas();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:12:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:44:09 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
# include <string>

class Brain {
	private:
		std::string	_ideas[100];
		int			_nbIdeas;
		
	public:
		Brain(void);
		Brain(const Brain &original);
		~Brain(void);
		
		Brain operator=(const Brain &original);
		
		void	addIdea(std::string idea);
		void	printIdea(void) const;
		int		getnbIdeas(void) const;
};

#endif
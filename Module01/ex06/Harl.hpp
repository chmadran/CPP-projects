/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:25:46 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 15:03:47 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <string>

class Harl {

public:	
	Harl();
	~Harl();

	void	complain( std::string level );

private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};

#endif
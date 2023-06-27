/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:27:11 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 13:07:06 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

class Weapon {

private:
	std::string	_type;

public:
	Weapon(std::string	_type);
	~Weapon();

	const std::string& getType( void ) const;
	void	setType(std::string newType);
	void	printType();
};

#endif
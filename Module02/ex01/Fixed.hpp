/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:12 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/22 12:39:31 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>

class Fixed {
public:
	Fixed();
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed( Fixed const & src);
	~Fixed();

	Fixed & operator=(Fixed const & nbr);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	
private:
	int					_fixedValue;
	static const int	_nBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

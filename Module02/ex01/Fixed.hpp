/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:12 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/25 10:27:05 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cmath>

class Fixed {
public:
	Fixed(void);
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed &operator=(const Fixed &nbr);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	
private:
	int					_fixedValue;
	static const int	_nBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

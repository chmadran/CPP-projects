/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:12 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/25 11:22:08 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>

class Fixed {
public:
	Fixed(void);
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(const Fixed &fixed);
	~Fixed(void);

	Fixed&	operator=(Fixed const &nbr);
	
	Fixed	operator++(int);
	Fixed	operator--(int);
	
	Fixed&	operator++(void);
	Fixed&	operator--(void);
	
	Fixed	operator+(const Fixed& fixed) const;
	Fixed	operator-(const Fixed& fixed) const;
	Fixed	operator*(const Fixed& fixed) const;
	Fixed	operator/(const Fixed& fixed) const;
	bool	operator>(const Fixed &fixed) const;
	bool	operator<(const Fixed &fixed) const;
	bool	operator>=(const Fixed &fixed) const;
	bool	operator<=(const Fixed &fixed) const;
	bool	operator==(const Fixed &fixed) const;
	bool	operator!=(const Fixed &fixed) const;

	static	Fixed& min(Fixed& a, Fixed& b);
	static	Fixed& max(Fixed& a, Fixed& b);

	static const	Fixed& min(const Fixed& a, const Fixed& b);
	static const	Fixed& max(const Fixed& a, const Fixed& b);
	
	int		getRawBits(void) const;
	int		toInt(void) const;
	float	toFloat(void) const;
	void	setRawBits(int const raw);
	
private:
	int					_fixedValue;
	static const int	_nBits = 8;
};

std::ostream& operator<<(std::ostream& os, Fixed const &fixed);

#endif

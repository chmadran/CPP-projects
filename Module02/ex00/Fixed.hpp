/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:12 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/25 11:24:43 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>

class Fixed {
public:
	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed& operator=(Fixed const &nbr);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	
private:
	int					_fixedValue;
	static const int	_nBits = 8;
};

#endif
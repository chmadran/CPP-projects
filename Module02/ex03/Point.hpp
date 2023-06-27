/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:11:54 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/22 16:20:49 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include <cmath>
# include "Fixed.hpp"

class Point {
	public:
		Point();
		~Point();
		Point(float xValue, float yValue);
		Point(Point const & src);

		Point& operator=(const Point& other);
		float getX() const;
		float getY() const;

	private:
		mutable Fixed		x;
		mutable Fixed		y;
};

#endif
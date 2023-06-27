/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:12:24 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/22 16:33:50 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(float xValue, float yValue) : x(xValue), y(yValue) {
   //std::cout << "Float constructor called" << std::endl;
}

Point::~Point() {
	//std::cout << "Destructor called" << std::endl;
}

Point::Point(Point const & other) : x(other.x),  y(other.y) {
	//std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
		}
		return *this;
	}

float	Point::getX() const {
	return x.toFloat();
}

float	Point::getY() const {
	return y.toFloat();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:43:36 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/22 16:19:19 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate the barycentric coordinates of the point with respect to the triangle ABC
    Fixed alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) /
                  ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));

    Fixed beta = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) /
                 ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));

    Fixed gamma = Fixed(1) - alpha - beta;

    // Check if the point is inside the triangle
    return alpha >= Fixed(0) && beta >= Fixed(0) && gamma >= Fixed(0);
}
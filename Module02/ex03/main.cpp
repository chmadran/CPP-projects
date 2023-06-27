/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:49:47 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/22 16:32:47 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);


int main() {
    // Test Case 1: Point inside the triangle
    Point a(1.0, 1.0);
    Point b(4.0, 1.0);
    Point c(2.5, 4.0);
    Point point1(3.0, 2.0);

    if (bsp(a, b, c, point1)) {
        std::cout << "Point 1 is inside the triangle." << std::endl;
    } else {
        std::cout << "Point 1 is outside the triangle." << std::endl;
    }

    // Test Case 2: Point outside the triangle
    Point point2(5.0, 3.0);

    if (bsp(a, b, c, point2)) {
        std::cout << "Point 2 is inside the triangle." << std::endl;
    } else {
        std::cout << "Point 2 is outside the triangle." << std::endl;
    }

    // Test Case 3: Point on the edge of the triangle
    Point point3(2.75, 1.0);

    if (bsp(a, b, c, point3)) {
        std::cout << "Point 3 is inside the triangle." << std::endl;
    } else {
        std::cout << "Point 3 is outside the triangle." << std::endl;
    }

    // Test Case 4: Point coincides with a vertex of the triangle
    Point point4(1.0, 1.0);

    if (bsp(a, b, c, point4)) {
        std::cout << "Point 4 is inside the triangle." << std::endl;
    } else {
        std::cout << "Point 4 is outside the triangle." << std::endl;
    }

    return 0;
}
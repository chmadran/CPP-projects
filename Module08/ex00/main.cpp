/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:41:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/04 13:39:09 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CR std::cout << std::endl;
#define HEADER(msg) std::cout << "-----------" << msg << "-----------" << std::endl;

#include "easyfind.hpp"

int main() {
	std::vector<int> vec = {1, 2, 3, 4, 5};
	std::list<int> lst = {10, 20, 30, 40, 50};

	int target = 20;

	try {

		std::vector<int>::iterator vecResult = easyfind(vec, target);
		if (vecResult != vec.end())
			std::cout << "Found " << target << " in the vector at position " << std::distance(vec.begin(), vecResult) << std::endl;
	}

	catch (ValueNotFound& e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		
		std::list<int>::iterator lstResult = easyfind(lst, target);
		if (lstResult != lst.end())
			std::cout << "Found " << target << " in the list." << std::endl;
	}

	catch (ValueNotFound& e)
	{
		std::cout << e.what() << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:17:40 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 14:00:12 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
#include <cstring>

int main(int argc, char **argv)
{
	std::string	current = "*LOUD AND UNBEARABLE FEEDBACK NOISE*";

	if (argc == 1)
	{
		std::cout << current << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		current = argv[i];
		int len = current.length();
		for(int j = 0 ; j < len ; j++)
			std::cout << (char)toupper(current[j]);
	}
	std::cout << std::endl;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:54:40 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/04 13:40:00 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

class ValueNotFound : public std::exception {
	public:
		virtual const char *what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	
	typename T::iterator res;
	res = find(container.begin(), container.end(), value);
	if (res == container.end())
		throw ValueNotFound();
	else
		return (res);
};

const char	*ValueNotFound::what() const throw()
{
	return ("Value not fond.");
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:58:57 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 14:29:27 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template < typename T, typename F >
void	iter(T *array, size_t len, F func) {
	if (!array)
	{
		std::cerr << "Array is a pointer null" << std::endl;
		return ;
	}
	for(size_t i = 0; i < len; ++i)
		func(array[i]);
}

template < typename T>
void	printArray(T data)
{
	std::cout << data << std::endl;
}
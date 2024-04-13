/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:57:57 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 15:34:02 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array {
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array();
		Array(Array const &src);
		Array(unsigned int n);
		~Array();

		Array	&operator=(Array const &src);
		T		&operator[](unsigned int index);
		
		unsigned int getSize() const;

		class indexOutOfRange : public std::exception {
			virtual const char* what() const throw();
		};
};

#include "Array.tpp"
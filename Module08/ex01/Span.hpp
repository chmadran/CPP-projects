/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:16:05 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/04 10:05:50 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

class Span {
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		Span	&operator=(const Span &rhs);

		void	addNumber(int nb);
		void	addNumber(std::vector<int> tabInt);
		int		shortestSpan();
		int		longestSpan();

		class NoSpan : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class ContainerFull : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class ContainerTooSmall : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::vector<int>	_intContainer;
		unsigned int		_lenContainer;

};
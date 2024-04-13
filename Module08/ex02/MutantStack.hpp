/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:18:44 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/04 13:56:38 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <vector>
#include <list>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> { // inherits all the member functions and features of std::stack

	public:
		MutantStack();
		MutantStack(const MutantStack &src);
		~MutantStack();
		
		MutantStack	&operator=(const MutantStack &rhs);
		
		typedef typename std::stack<T>::container_type::iterator	iterator;
		
		iterator begin();
		iterator end();
	
};

#include "MutantStack.tpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:23:25 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/04 14:07:33 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/************************************************************
 *					CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

template < typename T >
MutantStack<T>::MutantStack(): std::stack<T>() {};

template < typename T >
MutantStack<T>::MutantStack(const MutantStack &src) { (void)src; };

template < typename T >
MutantStack<T>::~MutantStack(){};

template < typename T >
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &src) {
	if (this != src)
	{
		this = std::stack<T>::operator=(src);
	}
	return (*this);
};

/************************************************************
 *						ITERATORS							*
 ************************************************************/

// c member represents the underlying container

template < typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
};

template < typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:58:57 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 14:02:21 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template < typename T>
void	swap(T& x, T& y) {
	T	tmp;
	tmp = x;
	x = y;
	y = tmp;
}
template < typename T >
T		min(const T &x, const T &y) 
{
	return (x < y ? x : y);
}

template < typename T >
T		max(const T &x, const T &y)
{
	return (x > y ? x : y);
}
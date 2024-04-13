/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:20:50 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 11:31:52 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <iostream>

class Base {
	public:
	virtual ~Base(){};
};

class A : virtual public Base {};
class B : virtual public Base {};
class C : virtual public Base {};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base& p);
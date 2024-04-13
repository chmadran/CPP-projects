/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:07:32 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 11:13:26 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/************************************************************
 *				CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &src){ *this = src; }

Serializer::~Serializer() {}

Serializer	&Serializer::operator=(Serializer const &src) { (void)src; return *this; }


/************************************************************
 *						SERIALIZER							*
 ************************************************************/

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
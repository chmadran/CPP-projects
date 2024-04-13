/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:06:54 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 11:15:46 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdlib>

struct Data
{
	int			i;
	char		c;
	std::string	s;
};


class Serializer
{
	public:
		Serializer();
		Serializer(Serializer const &toCopy);
		~Serializer();
		Serializer	&operator=(Serializer const &toAssign);

		static uintptr_t	serialize(Data *ptr);
		static Data	*deserialize(uintptr_t raw);
};

#endif
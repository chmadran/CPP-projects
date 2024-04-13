/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:06:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 12:09:12 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *data = new Data();

	uintptr_t ptr = Serializer::serialize(data);
	Data *data_reserialized = Serializer::deserialize(ptr);

	std::cout << "data : " << data << std::endl;
	std::cout << "serialized : " << ptr << std::endl;
	std::cout << "derialized : " << data_reserialized << std::endl;
	delete (data);
}
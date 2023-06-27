/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:00:24 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/27 11:31:32 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "AMateria parameter constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
    std::cout << "AMateria copy constructor called." << std::endl;
}
		
// AMateria& AMateria::operator=(const AMateria& rhs){
//     std::cout << "AMateria assignement constructor called." << std::endl;
//     // if (this != &rhs) {
//     //     // Perform the assignment here
//     // }
//     return *this;
// }

AMateria::~AMateria(){
    std::cout << "AMateria default destructor called." << std::endl;
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria abstractly used on " << target.getName() << std::endl;
}
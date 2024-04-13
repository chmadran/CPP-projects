/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:41:54 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 18:20:40 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "================CONSTRUCTOR======================" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;	
	std::cout << "==================METHODES======================" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;	
	std::cout << "================DESTRUCTOR===================" << std::endl;
	
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;	
	std::cout << "================CONSTRUCTOR======================" << std::endl;
	const WrongAnimal* wA = new WrongAnimal();
	const WrongAnimal* wC = new WrongCat();
	std::cout << std::endl;	
	std::cout << "==================METHODES======================" << std::endl;
	wA->makeSound();
	wC->makeSound();
	std::cout << std::endl;	
	std::cout << "================DESTRUCTOR===================" << std::endl;
	delete wA;
	delete wC;
	
	return 0;
}

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	delete meta;
// 	delete j;
// 	delete i;
// 	return 0;
// }
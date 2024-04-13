/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:41:54 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 18:28:45 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	std::cout << std::endl << "=============CONSTRUCTOR PART I=============" << std::endl;
	int				nbAnimal = 5;
	const Animal	**listAnimal = new const Animal*[nbAnimal];
	std::string		input;
	
	for (int i = 0; i < nbAnimal; i++)
	{
		if (i % 2)
			listAnimal[i] = new Dog();
		else
			listAnimal[i] = new Cat();
	}
	std::cout << std::endl << "===============SOUND=================" << std::endl;
	for (int i = 0; i < nbAnimal; i++)
		listAnimal[i]->makeSound();
	std::cout << std::endl << "================DESTRUCTOR PART I====================" << std::endl;
	for (int i = 0; i < nbAnimal; i++)
		delete listAnimal[i];
	delete[]	listAnimal;
	std::cout << std::endl << "=============CONSTRUCTOR COPY PROFONDE=============" << std::endl;
	Cat		*chat = new Cat();
	chat->getBrain()->addIdea("Je suis une idee.");
	Cat		chat2 = *chat;
	std::cout << std::endl << "=============DESTRUCTOR CAT PART I==============" << std::endl;
	delete	chat;
	std::cout << std::endl << "=================PRINT IDEAS===============" << std::endl;
	chat2.getBrain()->printIdea();
	std::cout << std::endl << "===================DESTRUCTOR CAT PART II==============" << std::endl;
	return 0;
}


// #include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;
// 	return 0;
// }
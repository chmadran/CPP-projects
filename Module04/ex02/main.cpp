/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:41:54 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 18:26:19 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

# define NBANIMAL 6

int main(void)
{
	// const AAnimal animal("impossible");//Error
	std::cout << std::endl << "=============CONSTRUCTOR PART I=============" << std::endl;
	const AAnimal	**listAnimal = new const AAnimal*[NBANIMAL];
	std::string		input;
	
	for (int i = 0; i < NBANIMAL; i++)
	{
		if (i % 2)
			listAnimal[i] = new Dog();
		else
			listAnimal[i] = new Cat();
	}
	std::cout << std::endl << "===============Print Ideas=================" << std::endl;
	for (int i = 0; i < NBANIMAL; i++)
	{
		listAnimal[i]->getBrain()->printIdea();
		listAnimal[i]->makeSound();
	}
	std::cout << std::endl << "================DESTRUCTOR PART I====================" << std::endl;
	for (int i = 0; i < NBANIMAL; i++)
		delete listAnimal[i];
	delete[]	listAnimal;
	std::cout << std::endl << "=============CONSTRUCTOR COPY PROFONDE=============" << std::endl;
	Cat		*chat = new Cat();
	chat->getBrain()->addIdea("Je suis un chat");
	Cat		chat2 = *chat;
	std::cout << std::endl << "=============DESTRUCTOR CAT PART I==============" << std::endl;
	delete	chat;
	std::cout << std::endl << "=================PRINT IDEAS===============" << std::endl;
	chat2.getBrain()->printIdea();
	std::cout << std::endl << "===================DESTRUCTOR CAT PART II==============" << std::endl;
	return 0;
}
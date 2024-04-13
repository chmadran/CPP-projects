/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:17:12 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/04 14:19:52 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CR std::cout << std::endl;
#define HEADER(msg) std::cout << "--------" << msg << "--------" << std::endl;

#include "MutantStack.hpp"

void	trySimpleTests()
{
	MutantStack<std::string> mutantStack;
	std::cout << "__Before push__" << std::endl;
	std::cout << "Size of stack = " << mutantStack.size() << std::endl;;
	std::cout << "Is it empty ? -> 1 is yes, 0 is no" << std::endl;
	std::cout << "[EMPTY] : " << mutantStack.empty() << std::endl;
	mutantStack.push("How");
	mutantStack.push("Are");
	mutantStack.push("You ?");
	
	CR;
	std::cout << "__After push__" << std::endl;
	std::cout << "Size of stack = "  << mutantStack.size() << std::endl;
	std::cout << "Is it empty ? -> 1 is yes, 0 is no" << std::endl;
	std::cout << "[EMPTY] : " << mutantStack.empty() << std::endl;
	CR;
	for (MutantStack<std::string>::iterator it = mutantStack.begin(); it != mutantStack.end(); it++)
		std::cout << "with iterator: " << *it << std::endl;
}

void tryMutant()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "[STACK TOP] : " << mstack.top() << std::endl;
	std::cout << "[STACK SIZE] : " << mstack.size() << std::endl;
	
	CR;
	std::cout << "...STACK POP TOP..." << std::endl;
	mstack.pop();
	CR;

	std::cout << "[STACK TOP] : " << mstack.top() << std::endl;
	std::cout << "[STACK SIZE] : " << mstack.size() << std::endl;
	CR;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << "with iterator: " << *it << std::endl;
}

void tryList()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "[STACK TOP] : " << mstack.back() << std::endl;
	std::cout << "[STACK SIZE] : " << mstack.size() << std::endl;
	
	CR;
	std::cout << "...STACK POP TOP..." << std::endl;
	mstack.pop_back();
	CR;

	std::cout << "[STACK TOP] : " << mstack.back() << std::endl;
	std::cout << "[STACK SIZE] : " << mstack.size() << std::endl;
	CR;
	
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	
	for (std::list<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << "with iterator: " << *it << std::endl;
}

int main(void)
{
	HEADER("SIMPLE TESTS");
	CR;
	trySimpleTests();
	CR;

	HEADER("SUBJECT, WITH MUTANT");
	CR;
	tryMutant();
	CR;

	HEADER("SUBJECT, WITH LIST");
	CR;
	tryList();
	CR;
}

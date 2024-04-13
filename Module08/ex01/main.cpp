/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:15:34 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/04 10:11:37 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CR std::cout << std::endl;
#define HEADER(msg) std::cout << "--------" << msg << "--------" << std::endl;

#include "Span.hpp"

void	tryOverloadSpan()
{
	try {
		Span	span(3);
		for (int i = 0; i < 4; ++i)
		{
			span.addNumber(i);
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	tryEmptySpan()
{
	try{
		Span	span;
		span.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	tryFillVector()
{
	try {
		Span				span1(10000);
		std::vector<int>	vecInt(10000);
		
		for (int i = 1; i <= 10000; ++i) {
			vecInt[i-1] = i;
		}
		
		span1.addNumber(vecInt);
		std::cout << "[Shortest Span] : " << span1.shortestSpan() << std::endl;
		std::cout << "[Longest Span] : " <<  span1.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	trySubjectMain()
{
	try {
		Span sp = Span(5);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(5);
		std::cout << "[Shortest Span] : " << sp.shortestSpan() << std::endl;
		std::cout << "[Longest Span] : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	CR;
	HEADER("CREATE SPAN, FIND LONGEST & SHORTEST")
	trySubjectMain();
	CR;

	CR;
	HEADER("TRY FILL SPAN WITH RANGE")
	tryFillVector();
	CR;
	
	CR;
	HEADER("TRY TO CREATE AN EMPTY SPAN")
	tryEmptySpan();
	CR;

	CR;
	HEADER("TRY TO OVERLOAD THE SPAN")
	tryOverloadSpan();
	CR;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:34:47 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/09 16:31:59 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define CR std::cout << std::endl;
#define OUTPUT_LINE(msg) std::cout << msg;
#define OUTPUT_NB(nbElements) std::cout << "[NUMBER OF ELEMENTS] : " << nbElements << std::endl;
#define OUTPUT_TYPE(typeContainer) std::cout << "[TYPE CONTAINER] : " << typeContainer << std::endl;
#define OUTPUT_TIME(timeTaken) std::cout << "[TIME TAKEN] : " << timeTaken << " us" << std::endl;

/************************************************************
 *					CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &src) {
	if (this != &src)
		*this = src;
	return (*this);
}

PmergeMe::~PmergeMe() {}

/************************************************************
 *						PARSING								*
 ************************************************************/


int		PmergeMe::validArray(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		if (!validArg("0123456789", av[i])) {
			throw std::runtime_error("Error: invalid input, not a valid digit.");
		}
	}
	return (EXIT_SUCCESS);
}

bool	PmergeMe::validArg(const char *allowed, char *str)
{
	if (str == NULL)
		return (false);
	while (*str)
	{
		if (strchr(allowed, *str) == NULL) 
			return (false);
		str++;
	}
	return (true);
}

/************************************************************
 *						SORT, VECTOR						*
 ************************************************************/

void	PmergeMe::launchVector(int ac, char **av)
{
	std::vector<int> _vector;
	
	OUTPUT_LINE("[BEFORE] : ");
	for (int i = 1; i < ac; i++)
	{
		OUTPUT_LINE(av[i]);
		if (i < ac - 1)
			OUTPUT_LINE(" ");
		_vector.push_back(atoi(av[i]));	
	}
	CR;

	OUTPUT_LINE("[AFTER] : ");
	auto vecStartTime = std::chrono::high_resolution_clock::now();
	sortVector(_vector);
	auto vecEndTime = std::chrono::high_resolution_clock::now();
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		OUTPUT_LINE(*it);
		OUTPUT_LINE(" ");
	}
	CR;

	OUTPUT_TYPE("std::vector");
	OUTPUT_NB(_vector.size());
	auto duration = std::chrono::duration<double, std::micro>(vecEndTime - vecStartTime).count();
	OUTPUT_TIME(duration);
}

void	PmergeMe::sortVector(std::vector<int> &_vector)
{
	int	n = _vector.size();
	int threshold = 16;
	if (n <= 1)
		return ;
	if (n <= threshold)
		insertVector(_vector);
	else
	{
		int					mid = n / 2;
		std::vector<int>	left(_vector.begin(), _vector.begin() + mid);
		std::vector<int>	right(_vector.begin() + mid, _vector.end());
		
		sortVector(left);
		sortVector(right);
		mergeVector(_vector, left, right);
	}
}

void	PmergeMe::mergeVector(std::vector<int> &vec, std::vector<int> &left, std::vector<int> &right)
{
	int	sizeLeft = left.size();
	int	sizeRight = right.size();
	int i = 0, j = 0, k = 0;

	while (j < sizeLeft && k < sizeRight)
	{
		if (left[j] < right[k])
			vec[i++] = left[j++];
		else
			vec[i++] = right[k++];
	}

	while (j < sizeLeft)
		vec[i++] = left[j++];

	while (k < sizeRight)
		vec[i++] = right[k++];	
}

void	PmergeMe::insertVector(std::vector<int> &vec)
{
	int	size = vec.size();
	for (int i = 1; i < size; i++)
	{
		int	x = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > x)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = x;
	}
}

/************************************************************
 *						SORT, DEQUE								*
 ************************************************************/

void	PmergeMe::launchDeque(int ac, char **av)
{
	std::deque<int> _deque;
	
	OUTPUT_LINE("[BEFORE] : ");
	for (int i = 1; i < ac; i++)
	{
		OUTPUT_LINE(av[i]);
		if (i < ac - 1)
			OUTPUT_LINE(" ");
		_deque.push_back(atoi(av[i]));	
	}
	CR;

	OUTPUT_LINE("[AFTER] : ");
	auto deqStartTime = std::chrono::high_resolution_clock::now();
	sortDeque(_deque);
	auto deqEndTime = std::chrono::high_resolution_clock::now();
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
	{
		OUTPUT_LINE(*it);
		OUTPUT_LINE(" ");
	}
	CR;

	OUTPUT_TYPE("std::deque");
	OUTPUT_NB(_deque.size());
	auto duration = std::chrono::duration<double, std::micro>(deqEndTime - deqStartTime).count();
	OUTPUT_TIME(duration);
}

void	PmergeMe::sortDeque(std::deque<int> &_deque)
{
	int	n = _deque.size();
	int threshold = 16;
	
	if (n <= 1)
		return ;
	if (n <= threshold)
		insertDeque(_deque);
	else
	{
		int					mid = n / 2;
		std::deque<int>	left(_deque.begin(), _deque.begin() + mid);
		std::deque<int>	right(_deque.begin() + mid, _deque.end());

		sortDeque(left);
		sortDeque(right);
		mergeDeque(_deque, left, right);
	}
}

void	PmergeMe::mergeDeque(std::deque<int> &deq, std::deque<int> &left, std::deque<int> &right)
{
	int	sizeLeft = left.size();
	int	sizeRight = right.size();
	int i = 0, j = 0, k = 0;

	while (j < sizeLeft && k < sizeRight)
	{
		if (left[j] < right[k])
			deq[i++] = left[j++];
		else
			deq[i++] = right[k++];
	}

	while (j < sizeLeft)
		deq[i++] = left[j++];

	while (k < sizeRight)
		deq[i++] = right[k++];	
}

void	PmergeMe::insertDeque(std::deque<int> &deq)
{
	int	size = deq.size();
	for (int i = 1; i < size; i++)
	{
		int	x = deq[i];
		int j = i - 1;
		while (j >= 0 && deq[j] > x)
		{
			deq[j + 1] = deq[j];
			j--;
		}
		deq[j + 1] = x;
	}
}
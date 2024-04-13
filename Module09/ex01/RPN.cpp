/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:22:37 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/09 15:04:13 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#define OUTPUT(msg) std::cout << msg << std::endl;

/************************************************************
 *					CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const &src) {
	std::stack<int> newStack = src._stack;
	_stack = newStack;
}

RPN	&RPN::operator=(RPN const &src) {
	if (this != &src)
	{
		std::stack<int> newStack = src._stack;
		_stack = newStack;
	}
	return (*this);
}

RPN::RPN(std::string const &input)
{
	bool				err_code;
	std::istringstream	iss(input);
	std::string			token;

	while (iss >> token)
	{
		err_code = false;
		if (validNum(token) == true)
		{
			_stack.push(std::atoi(token.c_str()));
			err_code = true;
		}
		else if (validOp(token) == true && _stack.size() >= 2)
			err_code = process(token[0]);
		
		if (err_code == false)
		{
			throw std::runtime_error("err_code is false.");
		}
	}
	if (_stack.size() != 1) {
		throw std::runtime_error("stack.size() is not 1."); 
	}
	else {
		OUTPUT(_stack.top()); }
}

/************************************************************
 *							CHECKERS						*
 ************************************************************/

bool	RPN::validNum(std::string const &input)
{
	if (input.length() != 1 || !(input[0] >= '0' && input[0] <= '9'))
		return (false);
	return (true);
}

bool	RPN::validOp(std::string const &input)
{
	if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')
		return (true);
	return (false);
}

/************************************************************
 *						PROCESS								*
 ************************************************************/

bool	RPN::process(char c)
{
	int	two = _stack.top();
	_stack.pop();
	int	one = _stack.top();
	_stack.pop();
	
	switch (c)
	{
	case '+':
		_stack.push (one + two);
		break;
	case '-':
		_stack.push (one - two);
		break;
	case '*':
		_stack.push (one * two);
		break;
	case '/':
		if (two == 0)
			return (false);
		_stack.push (one / two);
		break;
	default:
		break;
	}
	return (true);
}
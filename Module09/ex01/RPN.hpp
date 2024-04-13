/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:22:35 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/09 09:36:47 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

class RPN
{
	public:
		RPN(std::string const &input);
		~RPN();

	private:
		RPN();
		RPN(RPN const &src);
		RPN &operator=(RPN const &src);

		std::stack<int>	_stack;
		
		bool	validOp(std::string const &input);
		bool	validNum(std::string const &input);
		bool	process(char c);
		
};

#endif
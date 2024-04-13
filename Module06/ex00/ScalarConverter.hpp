/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:51:16 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 10:31:34 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <climits>
# include <cmath>
# include <iomanip>

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();

		static void				convert(const std::string &str);
		static bool			identifyChar(std::string input_str);
		static bool			identifyInt(std::string input_str);
		static bool			identifyFloat(std::string input_str);
		static bool			identifyDouble(std::string input_str);
		ScalarConverter &operator=(const ScalarConverter &src);
};

#endif
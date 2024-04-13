/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:50:53 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 12:07:17 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define MSG(type, val) std::cout << type << ": " << val << std::endl
#define MSG_CHAR(c) std::cout << "char: '" << c << "'" << std::endl
#define MSG_FLOAT(f) std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl
#define MSG_DOUBLE(d) std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl

/************************************************************
 *						PRINT	 							*
 ************************************************************/

static void	printChar(char c)
{
	if (c >= 32 && c <= 126)
		MSG_CHAR(c);
	else if (c >= 0 && c <= 127)
		MSG("char", "non-displayable");
	else
		MSG("char", "impossible");
}

static void printInt(double d)
{
	if (d > INT_MAX || d < INT_MIN || std::isnan(d))
		MSG("int", "impossible");
	else
		MSG("int", static_cast<int>(d));;
}


static void isChar(char c)
{
	printChar(c);
	printInt(static_cast<int>(c));
	MSG_FLOAT(static_cast<float>(c));
	MSG_DOUBLE(static_cast<double>(c));
}

static void isNotChar(double d)
{
	printChar(static_cast<int>(d));
	printInt(d);
	MSG_FLOAT(static_cast<float>(d));
	MSG_DOUBLE(d);
}


/************************************************************
 *				CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

ScalarConverter::ScalarConverter(void) {
	// std::cout << "Default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	// std::cout << "Default copy constructor called." << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {
	// std::cout << "Default destructor called." << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	return (*this);
}

/************************************************************
 *						CONVERT	 							*
 ************************************************************/

void		ScalarConverter::convert(const std::string &str)
{
	
	bool (*func[5])(std::string str) = {ScalarConverter::identifyChar, ScalarConverter::identifyInt, ScalarConverter::identifyFloat, ScalarConverter::identifyDouble, NULL};
	unsigned long	i = 0;
	
	while(func[i] && func[i](str) == false)
		i++;

	char	_char = 0;
	double	_double = 0.0;

	switch (i)
	{
		case 0 :
			_char = str[0];
			std::cout << "[ORIGINAL STRING TYPE] : CHAR" << std::endl;
			isChar(_char);
			break;
		case 1 :
			_double = std::strtod(str.c_str(), NULL);
			std::cout << "[ORIGINAL STRING TYPE] : INT" << std::endl;
			isNotChar(_double);
			break;
		case 2 :
			_double = std::strtod(str.c_str(), NULL);
			std::cout << "[ORIGINAL STRING TYPE] : FLOAT" << std::endl;
			isNotChar(_double);
			break;
		case 3 :
			_double = std::strtod(str.c_str(), NULL);
			std::cout << "[ORIGINAL STRING TYPE] : DOUBLE" << std::endl;
			isNotChar(_double);
			break;
		default : 
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: " << "impossible" << std::endl;
			std::cout << "double: " << "impossible" << std::endl;
	}
	return ;
}

/************************************************************
 *						IDENTIFY	 							*
 ************************************************************/

bool		ScalarConverter::identifyChar(std::string str)
{
	if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
		return (true);
	return(false);
}

bool		ScalarConverter::identifyInt(std::string input_str)
{
	try
	{
		size_t pos;
		int int_value = std::stoi(input_str, &pos);
		return (pos == input_str.length());
	}
	catch (std::invalid_argument& e)
	{
		return (false);
	}
	return (false);
}

bool		ScalarConverter::identifyFloat(std::string str)
{
	int	counterDote = 0;
	int	counterF = 0;

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);

	for (size_t i = 0; i < str.length(); ++i)
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (str[i] == '.')
			counterDote++;
		else if (str[i] == 'f' || str[i] == 'F')
			counterF++;
		else if (!isdigit(str[i]) && str[i] == '-')
			return (false);
	}
	return (counterDote == 1 && counterF == 1);
}

bool		ScalarConverter::identifyDouble(std::string str)
{
	int	counterDote = 0;
	int	counterF = 0;
	
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);

	for (size_t i = 0; i < str.length(); ++i)
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (str[i] == '.')
			counterDote++;
		else if (str[i] == 'f' || str[i] == 'F')
			counterF++;
		else if (!isdigit(str[i]) && str[i] == '-')
			return (false);
	}
	return (counterDote == 1 && counterF == 0);
}
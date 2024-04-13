/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:03:14 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/09 16:03:40 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

# define OUTPUT_MSG(date, mult , value) std::cout << date << " => " << mult << " = " << mult * value << std::endl

/************************************************************
 *					CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	_mapData = src._mapData;
}

BitcoinExchange::BitcoinExchange(std::string const &inputfile, std::string const &datafile){
	if (inputfile.empty())
		throw std::runtime_error("input file is empty or has not been provided.input file is empty or has not been provided.");
	fill_map(datafile);
	process(inputfile);
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src)
		_mapData = src._mapData;
	return (*this);
}

/************************************************************
 *						INIT/PROCESS						*
 ************************************************************/

void	BitcoinExchange::fill_map(std::string const &datafile)
{
	std::ifstream	file(datafile.c_str());
	std::string	line;

	if (!file.is_open())
		throw std::runtime_error("there was an error opening a file.");
	while (std::getline(file, line))
	{
		std::istringstream	iss(line);
		std::string			date;
		float				value;
		if (std::getline(iss, date, ',') && iss >> value)
			_mapData[date] = value;
	}
	file.close();
}

void	BitcoinExchange::process(std::string const &inputfile)
{
	std::ifstream	file(inputfile.c_str());
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("input file is empty or has not been provided.input file is empty or has not been provided.");
	while (std::getline(file, line))
	{
		try
		{
			processLine(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
	file.close();
}

void	BitcoinExchange::processLine(std::string const &line)
{
	
	if (line.compare("date | value") == 0)
		return ;
	else if (line.empty())
		return ;

	size_t		separator_pos = line.find('|');
	if (separator_pos == std::string::npos)
		throw std::runtime_error("bad input => missing separator '|'");

	std::string	date = line.substr(0, separator_pos);
	std::string	strvalue = line.substr(separator_pos + 1);

	//VALUE
	for (size_t i = 0; i < strvalue.length(); ++i)
	{
		if (i == 0 && strvalue[i] == ' ')
		{
			while (strvalue[i] == ' ')
				i++;
		}
		if (!isdigit(strvalue[i]) && strvalue[i] != '.')
			throw std::runtime_error("invalid value => " + strvalue);
	}

	float		value;
	std::istringstream valueStream(strvalue);
	if (!(valueStream >> value))
		throw std::runtime_error("invalid value => " + strvalue);
	
	if (value < 0)
		throw std::runtime_error("not a positive number.");	
	
	if (value > 1000)
		throw std::runtime_error("too large number");

	//DATE
	if (!isValidDate(date))	
		throw std::runtime_error("invalid date => " + date);
	date = findClosestDate(date);
	if (date.empty())
		throw std::runtime_error("Inexistant date and no anterior date found");

	OUTPUT_MSG(date, value, _mapData[date]);
}

/************************************************************
 *							DATES							*
 ************************************************************/

bool		BitcoinExchange::isValidDate(std::string const &date)
{
	if (date.length() != 11 || date[4] != '-' || date[7] != '-')
		return (false);

	int year, month, day;
	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return (false);

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (false);

	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		return (false);

	if (month == 2)
	{
		bool	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
		if (day > 29 || (!leap && day > 28))
			return (false);
	}
	return  (true);
}

std::string		BitcoinExchange::findClosestDate(std::string const &date)
{
	std::map<std::string, float>::const_iterator it = _mapData.lower_bound(date);

	if (it != _mapData.end() && it->first == date)
		return (date);
	
	if (it == _mapData.begin())
		return ("");

	--it;
	return (it->first);
}

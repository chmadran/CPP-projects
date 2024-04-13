/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:03:11 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/09 14:21:03 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <cstdlib>
# include <fstream>
# include <sstream>


class BitcoinExchange {
	public:
		BitcoinExchange(std::string const &inputfile, std::string const &datafile);
		~BitcoinExchange();

	private:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		
		std::map<std::string, float>	_mapData;
	
		void		fill_map(std::string const &datafile);
		void		process(std::string const &inputfile);
		void		processLine(std::string const &line);

		bool		isValidDate(std::string const &date);
		std::string	findClosestDate(std::string const &date);
};

#endif
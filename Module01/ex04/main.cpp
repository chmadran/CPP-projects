/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:09:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/22 12:08:36 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>

bool fileExists(const std::string& filename) {
	std::ifstream file(filename.c_str());
	return (file.good());
}

int	openFiles(std::string filename, std::ifstream& inputFile, std::ofstream& outputFile) {	
	inputFile.open(filename);
	outputFile.open(filename + ".replace");
	if (!inputFile.is_open() || !outputFile.is_open())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	closeFiles(std::string filename, std::ifstream& inputFile, std::ofstream& outputFile)
{
	inputFile.close();
	outputFile.close();
}

void	begin(void)
{
	std::cout << "You will be asked to enter a filename, and then two strings." << std::endl;
	std::cout << "The program will open the file and copy its content into a new file." << std::endl;
	std::cout << "It will also replace every occurrence of s1 with s2. Ready ?" << std::endl;
}

std::string	set_filename(void)
{
	std::string	filename;
	std::cout << "[FILENAME] : ";
	if (!(std::cin >> filename))
		return ("");
	return (filename);
}

std::string	set_string1(void)
{
	std::string	string1;
	
	std::cout << "[STRING 1] : ";
	if (!(std::cin >> string1))
		return ("");
	return (string1);
}

std::string	set_string2(void)
{
	std::string	string2;
	
	std::cout << "[STRING 2] : ";
	if (!(std::cin >> string2))
		return ("");
	return (string2);
}

int	routine(std::ifstream& inputFile, std::ofstream& outputFile, std::string string1, std::string string2)
{
	size_t		pos;
	std::string	line;
	std::string	modifiedLine;
	bool		foundOccurrence;

	foundOccurrence = false;
	while (std::getline(inputFile, line))
	{
		pos = 0;
		while ((pos = line.find(string1, pos)) != std::string::npos) {
			modifiedLine += line.substr(0, pos) + string2;
			pos += string1.length();
			line = line.substr(pos);
			pos = 0;
			foundOccurrence = true;
		}
		modifiedLine += line;
		outputFile << modifiedLine << '\n';
	}
	if (foundOccurrence == true)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int main() {
	std::string		filename;
	std::string		string1;
	std::string		string2;

	std::ifstream	inputFile;
	std::ofstream	outputFile;

	begin();
	filename = set_filename();
	string1 = set_string1();
	string2 = set_string2();
	if (filename.empty() || string1.empty() || string2.empty()) {
		std::cout << "Error in input of filename, string1, or string2." << std::endl;
		return (EXIT_FAILURE);
	}
	if (!fileExists(filename)) {
		std::cout << "Input file does not exist or cannot be open." << std::endl;
		return (EXIT_FAILURE);
	}
	if (openFiles(filename, inputFile, outputFile) == EXIT_FAILURE) {
		std::cout << "Error opening one of the files." << std::endl;
		return (EXIT_FAILURE);
	}
	if (routine(inputFile, outputFile, string1, string2) == EXIT_SUCCESS)
		std::cout << "Successfully completed." << std::endl;
	else
		std::cout << "Not successfully completed." << std::endl;
	closeFiles(filename, inputFile, outputFile);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:09:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 16:53:26 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

bool fileExists(const std::string& filename) {
		struct stat buffer;
		return (stat(filename.c_str(), &buffer) == 0);
}

int main() {
	std::string		filename;	
	std::string		string1;
	std::string		string2;

	std::cout << "You will be asked to enter a filename, and then two strings." << std::endl;
	std::cout << "The program will open the file and copy its content into a new file." << std::endl;
	std::cout << "It will also replace every occurrence of s1 with s2. Ready ?" << std::endl;
	std::cout << "[FILENAME] : ";
	std::cin >> filename;
	std::cout << "[STRING 1] : ";
	std::cin >> string1;
	std::cout << "[STRING 2] : ";
	std::cin >> string2;
	
	if (!fileExists(filename)) {
        std::cout << "Input file does not exist." << std::endl;
        return 1;
    }
	
	std::ifstream inputFile(filename);
	std::ofstream outputFile(filename + ".replace");
	
	if (inputFile.is_open() && outputFile.is_open()) {
	bool foundOccurrence = false;
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        std::string modifiedLine;
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
		if (foundOccurrence == true) {
			std::cout << "Successfully completed." << std::endl; }
		else {
			std::cout << "No occurence of string1 found." << std::endl; }
	}
	else {
		inputFile.close();
		outputFile.close();
		std::cout << "Error opening the file." << std::endl;
		return (1);
	}
	inputFile.close();
	outputFile.close();
}
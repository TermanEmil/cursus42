/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:55:44 by eterman           #+#    #+#             */
/*   Updated: 2017/07/23 00:35:30 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <streambuf>
#include <sstream>

void replaceAll( std::string &s, std::string &search, std::string &replace ) {
	for( size_t pos = 0; ; pos += replace.length() ) {
		pos = s.find( search, pos );
	if( pos == std::string::npos ) break;
		s.erase( pos, search.length() );
		s.insert( pos, replace );
	}
}

void replaceInFile(char * filename, std::string s1, std::string s2) {
	std::ifstream inFile;
	std::ofstream outFile;
	std::stringstream buffer;
	std::string strBuffer;
	std::string finalFileName;

	inFile.open(filename);
	if (!inFile) {
		std::cerr << "Unable to open " << filename << std::endl;
		return;
	}

	buffer << inFile.rdbuf();
	inFile.close();

	strBuffer = buffer.str();

	replaceAll(strBuffer, s1, s2);

	buffer.str("");
	buffer << filename << ".replace";
	finalFileName = buffer.str();

	outFile.open(finalFileName.c_str());
	if (!outFile) {
		std::cerr << "Unable to open " << finalFileName << std::endl;
		return;
	}

	outFile << strBuffer;
	outFile.close();
}

int main(int argc, char ** argv) {
	if (argc != 4) {
		std::cerr << "The program accepts only 3 arguments" << std::endl;
		return 0;
	}
	replaceInFile(argv[1], argv[2], argv[3]);
	return 0;
}

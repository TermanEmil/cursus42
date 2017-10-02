/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 11:41:15 by eterman           #+#    #+#             */
/*   Updated: 2017/07/23 11:41:15 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Logger.hpp"
#include <fstream>
#include <sstream>

std::string getTimeStapm (void) {

	std::stringstream currentDateTime;
	time_t ttNow = time(0);
	tm *ptmNow;

	ptmNow = localtime(&ttNow);

	currentDateTime << "[";

	currentDateTime << 1900 + ptmNow->tm_year;

	if (ptmNow->tm_mon < 9)
		currentDateTime << "0" << 1 + ptmNow->tm_mon;
	else
		currentDateTime << (1 + ptmNow->tm_mon);

	if (ptmNow->tm_mday < 10)
		currentDateTime << "0" << ptmNow->tm_mday << "_";
	else
		currentDateTime <<  ptmNow->tm_mday << "_";

	if (ptmNow->tm_hour < 10)
		currentDateTime << "0" << ptmNow->tm_hour;
	else
		currentDateTime << ptmNow->tm_hour;

	if (ptmNow->tm_min < 10)
		currentDateTime << "0" << ptmNow->tm_min;
	else
		currentDateTime << ptmNow->tm_min;

	if (ptmNow->tm_sec < 10)
		currentDateTime << "0" << ptmNow->tm_sec;
	else
		currentDateTime << ptmNow->tm_sec;

	currentDateTime << "] ";
	return currentDateTime.str();
}

Logger::Logger (std::string logFile) : _logFile(logFile) {
	_logFunctions["logToConsole"] = &Logger::_logToConsole;
	_logFunctions["logToFile"] = &Logger::_logToFile;
}

Logger::~Logger (void) {}

void Logger::log(std::string const & dest, std::string const & message) {
	if (_logFunctions[dest] == NULL) {
		std::cerr << "No such function: " << dest << std::endl;
		return;
	}
	(this->*(_logFunctions[dest])) (_makeLogEntry(message));
}

void Logger::_logToConsole (std::string const & str) const {
	std::cout << str << std::endl;
}

void Logger::_logToFile (std::string const & str) const {
	std::ofstream outFile;

	outFile.open (_logFile.c_str(), std::ios_base::app);
	if (!outFile) {
		std::cerr << "Couldn't open " << _logFile << std::endl;
		return;
	}

	outFile << str << std::endl;

	outFile.close();
}

std::string Logger::_makeLogEntry (std::string const & str) const {
	std::stringstream stream;

	stream << getTimeStapm() << str;

	return stream.str();
}
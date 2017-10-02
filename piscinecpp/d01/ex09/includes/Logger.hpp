/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 11:41:16 by eterman           #+#    #+#             */
/*   Updated: 2017/07/23 11:41:16 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <map>

class Logger {
	typedef void (Logger::*logF)(std::string const &) const;

public:
	Logger (std::string logFile);
	~Logger (void);

	void log(std::string const & dest, std::string const & message);

private:
	std::string const _logFile;

	std::map<std::string, Logger::logF> _logFunctions;

	void _logToConsole (std::string const & str) const;
	void _logToFile (std::string const & str) const;
	std::string _makeLogEntry (std::string const & str) const;
};

#endif
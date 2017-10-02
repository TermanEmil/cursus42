/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 11:41:14 by eterman           #+#    #+#             */
/*   Updated: 2017/07/23 11:41:14 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main (void) {
	Logger logger("myLogs");
	logger.log("logToFile", "Some log");
	logger.log("logToConsole", "Some log");
	logger.log("logToSomwhere", "Some log");
	return 0;
}
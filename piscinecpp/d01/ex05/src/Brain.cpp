/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 22:23:35 by eterman           #+#    #+#             */
/*   Updated: 2017/07/22 11:23:09 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Brain.hpp"

Brain::Brain (void) {
	std::cout << "New Brain" << std::endl;
}

Brain::~Brain (void) {
	std::cout << "No brain" << std::endl;
}

std::string Brain::identify (void) const {
	std::stringstream stream;

	stream << this;
	return stream.str();
}

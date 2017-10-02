/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:50:23 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 13:21:49 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

Pony::Pony (std::string newName) {
	_name = newName;
	std::cout << _name << " has been born" << std::endl;
}

Pony::~Pony (void) {
	std::cout << getName() << " dies" << std::endl;
}

std::string Pony::getName (void) const {
	return _name;
}

void Pony::jump(void) const {
	std::cout << getName() << " jumps" << std::endl;
}

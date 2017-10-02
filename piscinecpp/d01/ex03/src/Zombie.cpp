/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:58:04 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 16:39:07 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <stdlib.h>

const std::string Zombie::brainEaterType = "BrainEater";
const std::string Zombie::assEaterType = "AssEater";

const std::string Zombie::names[] = {"Leosha", "Alen", "Viktor"};

Zombie::Zombie (void) {
	_name = names[rand() % 3];
	if (rand() % 2 == 0)
		_type = brainEaterType;
	else
		_type = assEaterType;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie died?" << std::endl;
}

std::string Zombie::getType (void) const {
	return _type;
}

std::string Zombie::getName (void) const {
	return _name;
}

void Zombie::setName(std::string name) {
	_name = name;
}

void Zombie::setType(std::string type) {
	_type = type;
}

void Zombie::announce(void) const {
	const std::string quotes[] = {"I wanna die...", "Very c++", "Much class"};
	std::cout << "<" << getName() << " (" << getType() << ")> ";
	std::cout << quotes[rand() % 3] << std::endl;
}

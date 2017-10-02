/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 11:33:50 by eterman           #+#    #+#             */
/*   Updated: 2017/07/22 11:55:17 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon (std::string newType) : type(newType) {}

Weapon::~Weapon (void) {}

const std::string & Weapon::getType (void) const {
	return type;
}

void Weapon::setType (std::string newType) {
	type = newType;
}

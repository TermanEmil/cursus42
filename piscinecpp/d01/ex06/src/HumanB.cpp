/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 11:33:47 by eterman           #+#    #+#             */
/*   Updated: 2017/07/22 18:46:12 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB (std::string name) : name(name) {}

HumanB::~HumanB (void) {}

void HumanB::setWeapon (Weapon & newWeapon) {
	myWeapon = &newWeapon;
}

void HumanB::attack(void) const {
	std::cout << name << " attacks with " << myWeapon->type << std::endl;
}

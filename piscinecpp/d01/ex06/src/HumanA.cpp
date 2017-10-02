/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 11:33:48 by eterman           #+#    #+#             */
/*   Updated: 2017/07/22 18:43:28 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA (std::string givenName, Weapon & givenWeapon) :
	name(givenName), myWeapon(givenWeapon) {}

HumanA::~HumanA (void) {}

void HumanA::attack(void) const {
	std::cout << name << " attacks with " << myWeapon.type << std::endl;
}

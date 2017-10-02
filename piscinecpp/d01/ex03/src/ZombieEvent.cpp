/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:00:44 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 16:02:27 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include <iostream>

ZombieEvent::ZombieEvent (void) {
	_zombieType = "-";
}

ZombieEvent::~ZombieEvent (void) {

}

void ZombieEvent::setZombieType (std::string zombieType) {
	_zombieType = zombieType;
}

Zombie* ZombieEvent::newZombie(std::string name) {
	Zombie* freshZombie = new Zombie ();

	freshZombie->setType(_zombieType);
	freshZombie->setName(name);
	return freshZombie;
}

Zombie* ZombieEvent::randomChump(void) {
	Zombie* freshZombie = new Zombie();

	freshZombie->setType(_zombieType);
	freshZombie->announce();
	return freshZombie;
}

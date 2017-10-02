/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:03:12 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 16:38:55 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <iostream>

ZombieHorde::ZombieHorde (int n) {
	_zombies = new Zombie[n];
	_nbZombies = n;
}

ZombieHorde::~ZombieHorde (void) {
	delete [] _zombies;
}

void ZombieHorde::announce (void) {
	for (int i = 0; i < _nbZombies; i++) {
		_zombies[i].announce ();
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:59:11 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 16:00:13 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

int main () {
	srand(time(NULL));

	ZombieEvent ze;

	ze.setZombieType(Zombie::assEaterType);
	Zombie* z1 = ze.newZombie("Leosha");
	Zombie* z2 = ze.randomChump();

	std::cout << z1->getName() << "\n";
	std::cout << z2->getName() << "\n";

	z1->announce();
	z2->announce();

	delete z1;
	delete z2;
	
	return 0;
}

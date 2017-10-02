/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:59:11 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 16:39:47 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include "ZombieHorde.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

int main () {
	srand(time(NULL));
	
	ZombieHorde zh (20);

	zh.announce();
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:49:57 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 13:21:06 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheHeap (void) {
	Pony* myPony = new Pony("Heapy");

	myPony->jump();
	delete myPony;
}

void ponyOnTheStack (void) {
	Pony myPony ("Stacky");

	myPony.jump();
}

int main(void) {
	ponyOnTheHeap();
	ponyOnTheStack();
	return 0;
}

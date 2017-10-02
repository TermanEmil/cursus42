/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 22:23:40 by eterman           #+#    #+#             */
/*   Updated: 2017/07/22 11:23:09 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"
#include "Brain.hpp"

const Brain & Human::getBrain (void) const {
	return *_myBrain;
}

Human::Human (void) : _myBrain(new Brain()) {
	std::cout << "New human" << std::endl;
}

Human::~Human (void) {
	delete _myBrain;
	std::cout << "No human" << std::endl;
}

std::string Human::identify (void) const {
	return _myBrain->identify();
}

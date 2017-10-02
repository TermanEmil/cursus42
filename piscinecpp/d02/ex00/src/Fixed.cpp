/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 13:28:35 by eterman           #+#    #+#             */
/*   Updated: 2017/07/23 13:28:47 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_nbOfFractionalBits = 8;

Fixed::Fixed (void) {
	_fixedValue = 0;

	std::cout << "Default contstructor called" << std::endl;
}

Fixed::Fixed (Fixed & targetToCopy) {
	_fixedValue = targetToCopy.getRawBits();

	std::cout << "Copy contstructor called" << std::endl;
}

Fixed::~Fixed (void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits (void) const {
	return _fixedValue;
}

void Fixed::setRawBits (int const raw) {
	_fixedValue = raw;
}

Fixed & Fixed::operator= (Fixed const & targetToAssign) {
	_fixedValue = targetToAssign.getRawBits();

	std::cout << "Assignation opperation called" << std::endl;
	return *this;
}
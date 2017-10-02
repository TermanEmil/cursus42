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

/*
** Constructor/destructors
*/

Fixed::Fixed (void) {
	_fixedValue = 0;

	std::cout << "Default contstructor called" << std::endl;
}

Fixed::Fixed (Fixed const & targetToCopy) {
	_fixedValue = targetToCopy.getRawBits();

	std::cout << "Copy contstructor called" << std::endl;
}

Fixed::Fixed (int const nb) {
	_fixedValue = nb << _nbOfFractionalBits;

	std::cout << "Int contstructor" << std::endl;
}

Fixed::Fixed (float const nb) {
	_fixedValue = (int) roundf(nb * (1 << _nbOfFractionalBits));

	std::cout << "Float contstructor" << std::endl;
}

Fixed::~Fixed (void) {
	std::cout << "Destructor called" << std::endl;
}

/*
** Getters/setters
*/

int Fixed::getRawBits (void) const {
	return _fixedValue;
}

void Fixed::setRawBits (int const raw) {
	_fixedValue = raw;
}

float Fixed::toFloat (void) const {
	return ((float)_fixedValue) / (1 << _nbOfFractionalBits);
}

int Fixed::toInt (void) const {
	return _fixedValue >> _nbOfFractionalBits;
}

/*
** Operators
*/

Fixed & Fixed::operator= (Fixed const & targetToAssign) {
	_fixedValue = targetToAssign.getRawBits();

	std::cout << "Assignation opperation called" << std::endl;

	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & fixed) {
	o << fixed.toFloat();

	return o;
}
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

int Fixed::fracNb (void) {
	return 1 << _nbOfFractionalBits;
}

/*
** Constructor/destructors
*/

Fixed::Fixed (void) {
	_fixedValue = 0;
}

Fixed::Fixed (Fixed const & targetToCopy) {
	_fixedValue = targetToCopy.getRawBits();
}

Fixed::Fixed (int const nb) {
	_fixedValue = nb << _nbOfFractionalBits;
}

Fixed::Fixed (float const nb) {
	_fixedValue = (int) roundf(nb * (1 << _nbOfFractionalBits));
}

Fixed::~Fixed (void) {}

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

	return *this;
}

//Bool

bool Fixed::operator > (Fixed const & target) const {
	return getRawBits() > target.getRawBits();
}

bool Fixed::operator < (Fixed const & target) const {
	return getRawBits() < target.getRawBits();
}

bool Fixed::operator >= (Fixed const & target) const {
	return getRawBits() >= target.getRawBits();
}

bool Fixed::operator <= (Fixed const & target) const {
	return getRawBits() <= target.getRawBits();
}

bool Fixed::operator == (Fixed const & target) const {
	return getRawBits() == target.getRawBits();
}

bool Fixed::operator != (Fixed const & target) const {
	return getRawBits() != target.getRawBits();
}

//Arithmetic

Fixed Fixed::operator + (Fixed const & target) const {
	Fixed result;

	result.setRawBits(_fixedValue + target.getRawBits());
	return result;
}

Fixed Fixed::operator - (Fixed const & target) const {
	Fixed result;

	result.setRawBits(_fixedValue - target.getRawBits());
	return result;
}

Fixed Fixed::operator * (Fixed const & target) const {
	Fixed result;

	result.setRawBits(
		(_fixedValue * target.getRawBits()) >> _nbOfFractionalBits
	);
	return result;
}

Fixed Fixed::operator / (Fixed const & target) const {
	Fixed result;

	result.setRawBits(
		(_fixedValue / ((float)target.getRawBits())) * fracNb()
	);
	return result;
}


//Pre

Fixed & Fixed::operator ++ (void) {
	_fixedValue++;
	return *this;
}

Fixed & Fixed::operator -- (void) {
	_fixedValue--;
	return *this;
}

//Post

Fixed Fixed::operator ++ (int) {
	Fixed copy(*this);

	_fixedValue++;
	return copy;
}

Fixed Fixed::operator -- (int) {
	Fixed copy(*this);

	_fixedValue--;
	return copy;
}


//Max Min

const Fixed & Fixed::max(Fixed const & target1, Fixed const & target2) {
	return (target1.getRawBits() > target2.getRawBits()) ? target1 : target2;
}

const Fixed & Fixed::min(Fixed const & target1, Fixed const & target2) {
	return (target1.getRawBits() < target2.getRawBits()) ? target1 : target2;
}


//Print

std::ostream & operator<<(std::ostream & o, Fixed const & fixed) {
	o << fixed.toFloat();

	return o;
}

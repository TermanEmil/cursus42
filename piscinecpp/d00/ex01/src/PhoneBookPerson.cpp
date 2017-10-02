/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookPerson.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:32:39 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 10:29:41 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookPerson.hpp"

PhoneBookPerson::PhoneBookPerson () {
	this->_InitKeys();
}

PhoneBookPerson::~PhoneBookPerson () {
}

void PhoneBookPerson::ReadValuesWizard () {
	for (int i = 0; i < 11; i++) {
		std::cout << _keys[i] << ": ";
		std::cin >> _vals[i];
	}	
}

void PhoneBookPerson::PrintRightAlligned (std::string str) {
	const std::string	spaces = "          ";

	size_t	strLen;

	strLen = str.length ();

	if (strLen <= 10) {
		std::cout << spaces.substr(0, 10 - strLen) << str;
	} else {
		std::cout << str.substr(0, 9) << ".";
	}
}

void PhoneBookPerson::DisplayMe (bool inCol) const {

	if (inCol) {
		std::cout << "|";

		for (int i = 0; i < 3; i++) {
			PrintRightAlligned(_vals[i]);
			std::cout << "|";
		}
	} else {
		for (int i = 0; i < 11; i++) {
			std::cout << _keys[i] << ": " << _vals[i] << std::endl;
		}
	}
}

void PhoneBookPerson::_InitKeys () {
	this->_keys[0] = "First name";
	this->_keys[1] = "Last name";
	this->_keys[2] = "Nickname";
	this->_keys[3] = "Login";
	this->_keys[4] = "Postal address";
	this->_keys[5] = "email";
	this->_keys[6] = "phone number";
	this->_keys[7] = "birthday date";
	this->_keys[8] = "favorite meal";
	this->_keys[9] = "underwear color";
	this->_keys[10] = "darkest secret";
}

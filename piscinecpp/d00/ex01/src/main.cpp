/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:19:36 by eterman           #+#    #+#             */
/*   Updated: 2017/07/20 17:57:23 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookPerson.hpp"
#include <string>
#include <stdlib.h>
#include <sstream>

const std::string propmtStr = "$>";

void CmdAdd (PhoneBookPerson *contacts, int *i) {
	if (*i >= 8) {
		std::cout << "You've reached the maximum number of contacts"
		<< std::endl;

		return;
	}

	contacts[*i].ReadValuesWizard();
	*i = *i + 1;
}

void PrintContact (PhoneBookPerson contact, int index) {
	std::cout << "|";

	std::ostringstream stream;
	stream << index;
	PhoneBookPerson::PrintRightAlligned(stream.str());
	contact.DisplayMe (true);
	std::cout << std::endl;
}

void PrintAllContacts (PhoneBookPerson *contacts, int len) {
	for (int i = 0; i < len; i++) {
		PrintContact(contacts[i], i);
	}
}

void CmdSearch(PhoneBookPerson *contacts, int len) {
	int	userIndex;

	if (len <= 0) {
		std::cout << "(Empty)" << std::endl;
		return;
	}

	PrintAllContacts(contacts, len);


	std::cout << "Index = ";
	std::cin >> userIndex;

	if (userIndex >= len) {
		std::cout << "Invalid index" << std::endl;
		return;
	}

	contacts[userIndex].DisplayMe(false);
}

void CmdExit () {
	exit (0);
}

int		main(void) {
	PhoneBookPerson contacts[8];
	int				lastIndex;
	std::string		buf;

	lastIndex = 0;
	while (true) {
		std::cout << propmtStr;
		std::cin >> buf;
		if (buf == "EXIT") {
			CmdExit ();
		} else if (buf == "ADD") {
			CmdAdd(contacts, &lastIndex);
		} else if (buf == "SEARCH") {
			CmdSearch(contacts, lastIndex);
		} else {
			std::cout << buf << ": Invalid command" << std::endl;
		}
	}

	return (0);
}

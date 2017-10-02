/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookPerson.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:29:17 by eterman           #+#    #+#             */
/*   Updated: 2017/07/20 15:29:17 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKPERSON_HPP
# define PHONEBOOKPERSON_HPP

# include <string>
# include <iostream>

class PhoneBookPerson {

public:
	PhoneBookPerson();
	~PhoneBookPerson();

	void ReadValuesWizard ();
	void DisplayMe (bool inCol) const;

	static void PrintRightAlligned (std::string str);

private:
	std::string _keys[11];
	std::string _vals[11];

	void _InitKeys();

};

#endif

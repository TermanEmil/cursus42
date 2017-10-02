/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 11:25:36 by eterman           #+#    #+#             */
/*   Updated: 2017/07/22 11:28:48 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
	std::string myStr;
	std::string* myStrPtr;
	std::string& myStrRef = myStr;

	myStr = "HI THIS IS BRAIN";
	myStrPtr = &myStr;

	std::cout << *myStrPtr << std::endl;
	std::cout << myStrRef << std::endl;
}

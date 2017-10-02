/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:55:44 by eterman           #+#    #+#             */
/*   Updated: 2017/07/23 00:51:55 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <streambuf>
#include <sstream>
#include "Human.hpp"

int main(void) {
	Human a;

	a.action("rangedAttack", "emil");
	a.action("meleeAttack", "matskan");
	a.action("intimidatingShout", "leosha");
	a.action("club attack", "the wall");
	return 0;
}

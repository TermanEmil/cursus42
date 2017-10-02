/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 00:46:40 by eterman           #+#    #+#             */
/*   Updated: 2017/07/23 00:51:55 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <iostream>
#include <map>

typedef void (Human::*attackAction)(std::string const &);

void Human::meleeAttack(std::string const & target) {
	std::cout << "Mele attack on " << target << std::endl;
}

void Human::rangedAttack(std::string const & target) {
	std::cout << "Ranged attack on " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target) {
	std::cout << "Shout on " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target) {
	std::map<std::string, attackAction> actions;

	actions["meleeAttack"] = &Human::meleeAttack;
	actions["rangedAttack"] = &Human::rangedAttack;
	actions["intimidatingShout"] = &Human::intimidatingShout;

	if (actions[action_name] == NULL) {
		std::cout << "No such action: " << action_name << std::endl;
		return;
	}
	
	(this->*(actions[action_name])) (target);
}
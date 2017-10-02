/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 11:33:48 by eterman           #+#    #+#             */
/*   Updated: 2017/07/22 11:33:48 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

class HumanA {
public:
	const std::string name;
	const Weapon & myWeapon;

	HumanA(std::string givenName, Weapon & givenWeapon);
	~HumanA(void);

	void attack (void) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 11:33:46 by eterman           #+#    #+#             */
/*   Updated: 2017/07/22 11:33:46 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

class HumanB {
public:
	const std::string name;

	Weapon * myWeapon;

	HumanB(std::string name);
	~HumanB(void);

	void setWeapon (Weapon & newWeapon);
	void attack (void) const;
};

#endif
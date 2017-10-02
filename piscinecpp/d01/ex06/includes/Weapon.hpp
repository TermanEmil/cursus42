/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 11:33:49 by eterman           #+#    #+#             */
/*   Updated: 2017/07/22 11:33:49 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class Weapon
{
public:
	std::string type;

	Weapon(std::string newType);
	~Weapon(void);

	const std::string & getType (void) const;
	void setType (std::string newType);
};

#endif
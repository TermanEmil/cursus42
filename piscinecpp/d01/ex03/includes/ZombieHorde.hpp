/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:03:13 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 16:03:13 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde {
public:
	ZombieHorde (int n);
	~ZombieHorde (void);

	void announce (void);

private:
	Zombie* _zombies;
	int _nbZombies;
};

#endif
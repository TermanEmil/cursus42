/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:00:45 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 15:00:45 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <string>
# include "Zombie.hpp"

class ZombieEvent {
public:
	ZombieEvent (void);
	~ZombieEvent (void);

	void setZombieType (std::string zombieType);
	Zombie* newZombie(std::string name);
	Zombie* randomChump(void);
	
private:
	std::string _zombieType;

};

#endif
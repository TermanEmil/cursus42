/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:57:10 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 14:57:10 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
public:
	const static std::string brainEaterType;
	const static std::string assEaterType;
	const static std::string names[];

	Zombie (void);
	~Zombie (void);

	std::string getType (void) const;
	std::string getName (void) const;
	
	void setName(std::string name);
	void setType(std::string type);

	void announce(void) const;

private:
	std::string _type;
	std::string _name;
};

#endif
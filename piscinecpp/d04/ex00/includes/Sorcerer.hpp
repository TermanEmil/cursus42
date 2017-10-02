#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <iostream>
# include "ft_colors.h"
# include "Victim.hpp"

/*
** Because it has a const meber _name, it makes no sense to write
** the assignment operator.
*/

class Sorcerer
{
public:
	static std::string const color;

	std::string const & getName(void) const;
	std::string const & getTitle(void) const;

	Sorcerer (Sorcerer const & target);
	Sorcerer (std::string const & name, std::string const & title);
	~Sorcerer (void);
	
	void Polymorph (Victim const &) const;

private:
	std::string const _name;
	std::string _title;

	Sorcerer (void);

	static void _PrintMyColor (void);
};

std::ostream & operator << (std::ostream & o, Sorcerer const & target);

#endif
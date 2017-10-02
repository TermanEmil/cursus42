#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

# include <iostream>
# include <string>

//Interface

class ISpaceMarine
{
public:
	virtual ~ISpaceMarine (void) {};
	
	virtual ISpaceMarine * clone() const = 0;
	virtual void battleCry (void) const = 0;
	virtual void rangedAttack (void) const = 0;
	virtual void meleeAttack (void) const = 0;
};

#endif
#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include <string>
# include <iostream>
# include <vector>
# include "ISpaceMarine.hpp"

//Interface

class ISquad
{
public:
	virtual ~ISquad (void) {};
	virtual int getCount () const = 0;
	virtual ISpaceMarine * getUnit(int i) const = 0;
	virtual int push (ISpaceMarine * newUnit) = 0;
};

#endif
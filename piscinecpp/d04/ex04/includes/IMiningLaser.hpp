#ifndef IMININGLASER_HPP
# define IMININGLASER_HPP

# include <string>
# include <iostream>
# include "IAsteroid.hpp"

class IMiningLaser
{
public:	
	virtual ~IMiningLaser() {}
	virtual void mine (IAsteroid * target) = 0;
	
};

#endif
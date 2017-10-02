#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

# include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser
{
public:
	DeepCoreMiner (void);
	DeepCoreMiner (DeepCoreMiner const & target);
	~DeepCoreMiner (void);
	
	void mine (IAsteroid * target);

	DeepCoreMiner & operator = (DeepCoreMiner const & target);
};

std::ostream & operator << (std::ostream & o, DeepCoreMiner const & target);

#endif
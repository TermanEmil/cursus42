#ifndef KOALASTEROID_HPP
# define KOALASTEROID_HPP

# include "IAsteroid.hpp"

//BocalSteroid 
class KoalaSteroid : public IAsteroid
{
public:
	std::string getName (void) const;

	KoalaSteroid (void);
	KoalaSteroid (KoalaSteroid const & target);
	~KoalaSteroid (void);

	std::string beMined (StripMiner const * tool) const;
	std::string beMined (DeepCoreMiner const * tool) const;
	
	KoalaSteroid & operator = (KoalaSteroid const & target);
};

std::ostream & operator << (std::ostream & o, KoalaSteroid const & target);

#endif
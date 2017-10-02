#ifndef IASTEROID_HPP
# define IASTEROID_HPP

# include <string>
# include <iostream>

class StripMiner;
class DeepCoreMiner;

class IAsteroid
{
public:
	virtual std::string getName (void) const = 0;

	virtual ~IAsteroid (void) {}

	virtual std::string beMined (StripMiner const * tool) const = 0;
	virtual std::string beMined (DeepCoreMiner const * tool) const = 0;
};

#endif
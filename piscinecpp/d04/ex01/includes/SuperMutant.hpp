#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant (void);
	~SuperMutant (void);
	
	void takeDamage (int amount);
};

#endif
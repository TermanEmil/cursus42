#ifndef POWERFIRST_HPP
# define POWERFIRST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist (void);
	~PowerFist (void);

	void attack (void) const;
};

#endif
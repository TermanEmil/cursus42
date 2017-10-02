#ifndef PLASMRIFLE_HPP
# define PLASMRIFLE_HPP

# include "AWeapon.hpp"

class PlasmRifle : public AWeapon
{
public:
	PlasmRifle (void);
	~PlasmRifle (void);

	void attack (void) const;
};

#endif
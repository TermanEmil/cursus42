#ifndef MISSLE_HPP
# define MISSLE_HPP

#include "GameObject.hpp"
#include "MovementCtrl.hpp"

class Shooter;

class Missle : public GameObject {
public:
	Missle (Shooter * newShooter);
	Shooter * shooter;

	void Update ();
	GameObject * GetCollision (void) const;

	MovementCtrl mvCtrl;
};

#endif
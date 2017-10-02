#ifndef SHOOTER_HPP
# define SHOOTER_HPP

# include "Missle.hpp"
# include "Transform.hpp"

class Shooter {
public:
	Vector2 missleSpeed;
	bool isFriendly;
	float dmg;

	Shooter (Transform & newTransform, Vector2 speed, bool newCollisionType, float newDmg);
	~Shooter (void);

	void Shoot(void);

	Transform & transform;
};

#endif
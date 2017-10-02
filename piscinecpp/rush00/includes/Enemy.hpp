#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "headers.hpp"
# include "GameObject.hpp"
# include "Shooter.hpp"
# include "MovementCtrl.hpp"

class Enemy : public GameObject {
public:
	Shooter shooter;
	MovementCtrl mvCtrl;

	Enemy (Vector2 pos);

	void Update();
};

#endif
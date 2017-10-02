#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "headers.hpp"
# include "GameObject.hpp"
# include "MovementCtrl.hpp"
# include "Shooter.hpp"

class Player : public GameObject {
public:
	Player (void);
	~Player (void);
	
	void Update (void);
	void PutMeToBottom (void) const;

	MovementCtrl mvCtrl;
	Shooter shooter;
};

#endif
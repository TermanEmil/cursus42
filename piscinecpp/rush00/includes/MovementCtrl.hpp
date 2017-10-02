#ifndef MOVEMENTCTRL_HPP
# define MOVEMENTCTRL_HPP

# include "headers.hpp"
# include "Transform.hpp"

class MovementCtrl {
public:
	MovementCtrl (Transform & newTransform);

	Vector2 speed;

	void MoveTo(Vector2 newPos, bool isBounded) const;
	void Translate (Vector2 deltaPos, bool isBounded) const;
	
private:
	Transform & _transform;
};

#endif
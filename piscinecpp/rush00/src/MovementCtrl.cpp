#include "MovementCtrl.hpp"

MovementCtrl::MovementCtrl (Transform & newTransform) : _transform(newTransform) {}

void MovementCtrl::MoveTo (Vector2 newPos, bool isBounded) const {
	if (isBounded) {
		Vector2 boundedPos = Vector2::GetBoundedPos(newPos, _transform.blocks);
		_transform.position = boundedPos;
	} else {
		_transform.position = newPos;
	}
}

void MovementCtrl::Translate (Vector2 deltaPos, bool isBounded) const {
	deltaPos.x *= speed.x;
	deltaPos.y *= speed.y;

	Vector2 newPos(_transform.position.x + deltaPos.x, _transform.position.y + deltaPos.y);
	MoveTo(newPos, isBounded);
}
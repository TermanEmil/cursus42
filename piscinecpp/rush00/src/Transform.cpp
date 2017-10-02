#include "headers.hpp"
#include "Transform.hpp"
#include "Vector2.hpp"

Transform::Transform (void) {
	blocks = Vector2(1, 1);
};

Transform::Transform (Vector2 newPos) {
	position = newPos;
	blocks = Vector2(1, 1);
};

bool Transform::IsBounded (void) const {
	if (position.x < 0 || position.x > COLS - blocks.x * XCELSIZE)
		return false;
	if (position.y < 0 || position.y > LINES - blocks.y * YCELSIZE)
		return false;
	return true;
}
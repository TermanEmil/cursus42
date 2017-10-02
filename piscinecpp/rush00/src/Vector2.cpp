#include "headers.hpp"
#include "Vector2.hpp"

Vector2 Vector2::left (void) {
	return Vector2(-1, 0);
}

Vector2 Vector2::right (void) {
	return Vector2(1, 0);
}

Vector2::Vector2 (void) : x(0), y(0) {}

Vector2::Vector2 (float const newX, float newY) : x(newX), y(newY) {}

Vector2::Vector2 (Vector2 const & rhs) : x(rhs.x), y(rhs.y) {}

Vector2::~Vector2 (void) {}

Vector2 Vector2::GetBoundedPos (Vector2 const & pos, Vector2 const & nrBLocks) {
	Vector2 newPos;

	if (pos.x  < 0)
		newPos.x = 0;
	else if (pos.x > COLS - nrBLocks.x * XCELSIZE)
		newPos.x = COLS - nrBLocks.x * XCELSIZE;
	else
		newPos.x = pos.x;

	if (pos.y < 0)
		newPos.y = 0;
	else if (pos.y > LINES - nrBLocks.y * YCELSIZE)
		newPos.y = LINES - nrBLocks.y * YCELSIZE;
	else
		newPos.y = pos.y;
	
	return newPos;
}

Vector2 & Vector2::operator=(Vector2 const & rhs) {
	x = rhs.x;
	y = rhs.y;
}

Vector2 Vector2::operator+(Vector2 const & rhs) const {
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(Vector2 const & rhs) const {
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(float const nb) const {
	return Vector2(x * nb, y * nb);
}

std::ostream & operator<<(std::ostream & o, Vector2 const & rhs) {
	o << "Vector2(" << rhs.x << ", " << rhs.y << ")";
}
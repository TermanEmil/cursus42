#ifndef VECTOR2_HPP
# define VECTOR2_HPP

# include <iostream>

class Vector2 {
public:
	static Vector2 left();
	static Vector2 right();
	static Vector2 GetBoundedPos (Vector2 const & pos, Vector2 const & nrBLocks);

	float x;
	float y;

	Vector2 (void);
	Vector2 (float const newX, float const newY);
	Vector2 (Vector2 const & rhs);
	~Vector2 (void);

	Vector2 & operator=(Vector2 const & rhs);
	Vector2 operator+(Vector2 const & rhs) const;
	Vector2 operator-(Vector2 const & rhs) const;
	Vector2 operator*(float const nb) const;
};

std::ostream & operator<<(std::ostream & o, Vector2 const & rhs);

#endif
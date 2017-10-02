#ifndef TRANSFORM_HPP
# define TRANSFORM_HPP

# include "headers.hpp"
# include "Vector2.hpp"

class Transform {
public:
	Vector2 position;
	Vector2 blocks;

	Transform (void);
	Transform (Vector2 newPos);

	bool IsBounded (void) const;
};

#endif
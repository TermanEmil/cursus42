#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

# include "headers.hpp"
# include "Renderer.hpp"
# include "Transform.hpp"

class GameObject {
public:

	GameObject (std::string const newName);
	~GameObject (void);

	std::string GetName (void) const;
	bool isFriendly;

	Transform * transform;
	Renderer * renderer;

	virtual void Update (void);

private:
	std::string _name;
};

#endif
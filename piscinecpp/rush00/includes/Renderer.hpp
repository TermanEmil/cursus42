#ifndef RENDERER_HPP
# define RENDERER_HPP

# include "headers.hpp"
# include "Transform.hpp"

class Renderer {
public:
	Renderer (Transform & newTransform);
	~Renderer (void);
	
	int prevX, prevY;
	int color;
	
	void Render (void);
	void Clear (void) const;

	void AssignSprite (std::string const newSprite[YCELSIZE]);

	Transform & transform;
	std::string sprite[YCELSIZE];
};

#endif
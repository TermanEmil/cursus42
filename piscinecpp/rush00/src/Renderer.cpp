#include "headers.hpp"
#include "Renderer.hpp"

Renderer::Renderer (Transform & newTransform) : transform(newTransform) {
	for (int i = 0; i < XCELSIZE; i++)
			sprite[i] = "";

	prevX = 9999;
	prevY = 9999;
}

Renderer::~Renderer (void) {
	Clear();
}

void Renderer::Render (void) {
	int newX = roundf(transform.position.x);
	int newY = roundf(transform.position.y);

	if (newX != prevX || newY != prevY) {
		Clear();
		prevX = newX;
		prevY = newY;

		for (int i = 0; i < XCELSIZE; i++) {
			if (color > 0)
				attron(A_BOLD | COLOR_PAIR(color));
			mvprintw(
				roundf(transform.position.y + i),
				roundf(transform.position.x),
				sprite[i].c_str()
			);
			if (color > 0)
				attroff(A_BOLD | COLOR_PAIR(color));
		}
	}
}

void Renderer::Clear (void) const {
	std::stringstream s;

	for (int i = 0; i < XCELSIZE * transform.blocks.x; i++) {
		s << " ";
	}

	for (int i = 0; i < YCELSIZE; i++) {
		mvprintw(
			roundf(prevY + i),
			roundf(prevX),
			s.str().c_str()
			// "              "
		);
	}
}

void Renderer::AssignSprite (std::string const newSprite[XCELSIZE]) {
	for (int i = 0; i < XCELSIZE; i++)
			sprite[i] = newSprite[i];
}
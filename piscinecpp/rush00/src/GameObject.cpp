#include "GameObject.hpp"
#include "GameController.hpp"

GameObject::GameObject (std::string const newName) : _name(newName) {
	transform = new Transform ();
	renderer = NULL;
}

GameObject::~GameObject (void) {
	if (transform)
		delete transform;
	if (renderer)
		delete renderer;
}

std::string GameObject::GetName (void) const {
	return _name;
}

void GameObject::Update (void) {
	if (renderer != NULL)
		renderer->Render ();
}
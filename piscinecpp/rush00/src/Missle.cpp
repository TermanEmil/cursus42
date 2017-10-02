#include "Missle.hpp"
#include "Shooter.hpp"
#include "headers.hpp"
#include "GameController.hpp"
#include <unistd.h>

Missle::Missle (Shooter * newShooter) : GameObject("Missle"),
	shooter(newShooter), mvCtrl(*transform)
{
	std::string sprite[3];

	sprite[0] = "   ";
	sprite[1] = " O ";
	sprite[2] = "   ";
	renderer = new Renderer(*transform);
	renderer->AssignSprite(sprite);

	if (shooter->isFriendly)
		renderer->color = 5;
	else
		renderer->color = 6;
}

void Missle::Update () {
	GameObject::Update();

	if (!transform->IsBounded()) {
		g_gmCtrl.DestroyGO(this);
		return;
	}

	mvCtrl.Translate(Vector2(0, 1), false);

	GameObject * obj = GetCollision();
	if (obj != NULL && obj->isFriendly != shooter->isFriendly) {
		g_gmCtrl.DestroyGO(obj);
		g_gmCtrl.DestroyGO(this);

		if (obj->GetName() == "Player") {
			endwin();
			std::cout << "You loose with score: " << g_gmCtrl.score << std::endl;
			curs_set(1);
			exit(0);
		}

		if (obj->GetName() == "Enemy" && shooter->isFriendly)
			g_gmCtrl.score += 500;
	}
}

GameObject * Missle::GetCollision (void) const {
	for (int i = 0; i < MAXNBOBJS; i++) {
		if (!g_gmCtrl.gos[i])
			continue;

		if (g_gmCtrl.gos[i] == this)
			continue;

		if ((int)(transform->position.x) == (int)(g_gmCtrl.gos[i]->transform->position.x) &&
			(int)(transform->position.y) == (int)(g_gmCtrl.gos[i]->transform->position.y))
			return g_gmCtrl.gos[i];
	}
	return NULL;
}
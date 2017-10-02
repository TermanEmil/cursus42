#include "Enemy.hpp"
#include "GameController.hpp"
#include "headers.hpp"

Enemy::Enemy (Vector2 pos) :
	GameObject("Enemy"),
	mvCtrl(*transform),
	shooter(*transform, Vector2(0, 0.00015), false, 50)
{
	transform->position = pos;

	renderer = new Renderer(*transform);
	std::string sprite[3];

	sprite[0] = "###";
	sprite[1] = "\\ /";
	sprite[2] = " V ";

	renderer->AssignSprite(sprite);
	renderer->color = 2;
	mvCtrl.speed = Vector2(0, 0.00001);

	isFriendly = false;
}

void Enemy::Update (void) {
	GameObject::Update();

	if (!transform->IsBounded()) {
		g_gmCtrl.DestroyGO(this);
		return;
	}

	if (rand() % 1000000 < 5) {
		shooter.Shoot();
	}

	mvCtrl.Translate(Vector2(0, 1), false);
}
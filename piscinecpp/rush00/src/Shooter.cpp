#include "Shooter.hpp"
#include "GameController.hpp"

Shooter::Shooter (Transform & newTransform, Vector2 speed, bool newCollisionType, float newDmg) :
	missleSpeed(speed), isFriendly(newCollisionType), dmg(newDmg), transform(newTransform) {
}

Shooter::~Shooter (void) {}

void Shooter::Shoot (void) {
	Missle * missle = new Missle(this);
	missle->mvCtrl.speed = missleSpeed;

	Vector2 misslePos(transform.position);

	if (missleSpeed.y < 0)
		misslePos.y += -1 * YCELSIZE;
	else
		misslePos.y += 1 * YCELSIZE;

	missle->mvCtrl.MoveTo(Vector2(misslePos), false);

	g_gmCtrl.Instantiate(missle);
}
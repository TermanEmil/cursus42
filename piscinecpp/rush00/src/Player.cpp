#include "Player.hpp"
#include "Renderer.hpp"
#include "GameController.hpp"

Player::Player (void) :
	GameObject("Player"),
	mvCtrl(*transform),
	shooter(*transform, Vector2(0, -0.0002), true, 100)
{

	renderer = new Renderer(*transform);

	std::string sprite[YCELSIZE];

	sprite[0] = " | ";
	sprite[1] = "/#\\";
	sprite[2] = "###";

	renderer->AssignSprite(sprite);
	renderer->color = 3;
	transform->blocks = Vector2(1, 1);

	mvCtrl.speed.x = 1 * XCELSIZE;
	mvCtrl.speed.y = 0;

	PutMeToBottom();
	isFriendly = true;
}

Player::~Player (void) {

}

void Player::Update (void) {
	int playerInput;

	GameObject::Update ();

	playerInput = 0;
	playerInput = getch();

	// std::stringstream leosha;


	if (playerInput != ERR) {
		switch (playerInput) {
			case ('a'):
			case (KEY_LEFT):
				mvCtrl.Translate(Vector2::left(), true);
				break;

			case ('d'):
			case (KEY_RIGHT):
				mvCtrl.Translate(Vector2::right(), true);
				break;

			case ('w'):
			case ('W'):
				shooter.Shoot();
				break;
		}
	}
}

void Player::PutMeToBottom (void) const {
	mvCtrl.MoveTo(Vector2(COLS / 2, LINES), true);
}

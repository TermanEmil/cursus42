#include "GameController.hpp"
#include <fstream>
#include "Enemy.hpp"

GameController::GameController (void) {
	for (int i = 0; i < MAXNBOBJS; i++)
		gos[i] = NULL;
	score = 0;
}

void GameController::Instantiate (GameObject * go) {
	gos[_GetEmptySlot()] = go;
}

void GameController::DestroyGO (GameObject * go) {
	for (int i = 0; i < MAXNBOBJS; i++)
		if (go == gos[i])
			gos[i] = NULL;
	if (go)
		delete go;
}

int GameController::_GetEmptySlot (void) const {
	for (int i = 0; i < MAXNBOBJS; i++)
		if (gos[i] == NULL)
			return i;

	return -1;
}

void GameController::UpdateAll (void) const {
	for (int i = 0; i < MAXNBOBJS; i++)
		if (gos[i])
			gos[i]->Update();
}

void GameController::ClearAll (void) const {
	for (int i = 0; i < MAXNBOBJS; i++)
		if (gos[i] && gos[i]->renderer)
			gos[i]->renderer->Clear();
}

int GameController::Count (void) const {
	int n = 0;

	for (int i = 0; i < MAXNBOBJS; i++)
		if (gos[i])
			n++;
	return n;
}

int GameController::CountEnemy(void) const {
	int n = 0;

	for (int i = 0; i < MAXNBOBJS; i++)
		if (gos[i] && gos[i]->GetName() == "Enemy")
			n++;
	return n;
}

void GameController::LoadLevel (int lvl) {
	int enemyType;
	int x;
	int y;

	if (lvl > MAX_LEVEL) {
		return;
	}

	std::ifstream inFile;
	std::stringstream stream;

	stream << "maps/level_" << lvl;
	inFile.open(stream.str().c_str());

	if (!inFile) {
		endwin();
		std::cout << "Couldnt find maps" << std::endl;
		exit(0);
	}

	stream.str("");
	stream << inFile;

	while (inFile >> enemyType >> x >> y) {
		SpawnEnemy(enemyType, x, y);
	}
}

void GameController::SpawnEnemy (int enemyType, int x, int y) {
	x *= XCELSIZE;
	y *= YCELSIZE;
	
	x = COLS / 2 + x;

	switch (enemyType) {
		case 1:
			Instantiate(new Enemy(Vector2(x, y)));
			break;
	}
}

void GameController::PrintScore (void) const {
	std::stringstream s;

	s << "Score: " << score;
	attron(A_BOLD | COLOR_PAIR(7));
	mvprintw(0, 0, s.str().c_str());
	attroff(A_BOLD | COLOR_PAIR(7));
}
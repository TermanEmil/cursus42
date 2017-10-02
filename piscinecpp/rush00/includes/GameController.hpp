#ifndef GAMECONTROLLER_HPP
# define GAMECONTROLLER_HPP

# define MAXNBOBJS 200
# define MAX_LEVEL 2

# include "headers.hpp"
# include "GameObject.hpp"

class GameController {
public:
	GameController (void);

	GameObject * gos[MAXNBOBJS];
	int score;

	void Instantiate (GameObject * go);
	void DestroyGO (GameObject * go);

	void UpdateAll (void) const;
	void ClearAll (void) const;

	int Count (void) const;
	int CountEnemy (void) const;

	void LoadLevel (int level);
	void SpawnEnemy(int enemyType, int x, int y);

	void PrintScore (void) const;

private:
	int _GetEmptySlot (void) const;
};

extern GameController g_gmCtrl;

#endif
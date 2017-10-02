#include "headers.hpp"
#include "GameController.hpp"
#include "Vector2.hpp"
#include "Player.hpp"
#include <unistd.h>
#include <sstream>
#include "Enemy.hpp"

GameController g_gmCtrl;
int g_frameRate = 100;

void initncourses (void) {
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	refresh();
	clear();

	cbreak();
	nodelay(stdscr, TRUE);
	curs_set(0);

	srand(time(NULL));

	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

int main(void) {
	int lvl = 1;

	initncourses();
	
	g_gmCtrl.Instantiate(new Player());
	g_gmCtrl.LoadLevel(1);

	while (true) {
		g_gmCtrl.PrintScore();

		if (g_gmCtrl.CountEnemy() == 0) {
			lvl++;
			if (lvl > MAX_LEVEL) {
				endwin();
				curs_set(1);
				std::cout << "You win with score: "  << g_gmCtrl.score << std::endl;
				exit(0);
			} else {
				g_gmCtrl.LoadLevel(lvl);
			}
		}

		g_gmCtrl.UpdateAll();
		

		refresh();
	}

	getch();
	endwin();
}
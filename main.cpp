#include "curses.h"
#include "GameLoop.h"
#include "Enemy.h"
#include "Bullet.h";
#include "Knight.h"
#include "Map.h"
#include <fstream>
#include <iostream>


int main() {

	std::ifstream mapfile("Map.txt");

	int h;
	int w;
	mapfile >> h;
	mapfile >> w;
	std::string str;

	getline(mapfile, str);
	std::vector<std::string> m;
	for (int i = 0; i < h; i++) {
		getline(mapfile, str);
		m.push_back(str);
	}
	Map map(m, h, w);
	initscr();
	GameLoop gl(map);
	gl.Run();
	endwin();
}
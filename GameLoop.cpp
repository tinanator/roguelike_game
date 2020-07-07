#include "GameLoop.h"
#include "Enemy.h"
#include <chrono>
#include <thread>
#include "Knight.h"
#include "Map.h"
#include <memory>
#include <fstream>
#include <iostream>
#include "Princess.h"

GameLoop::GameLoop(Map& _map) : map(_map) {}

void GameLoop::Run() {
	srand(5);

	map.InitializeCreators();
	while (true) {
		erase();
		map.UpdateMap();
	
		if (map.IsKnightDead()) {
			std::string over = "You are dead";
			while (true) {
				clear();
				mvprintw(2, 2, over.c_str());
				refresh();
			}
		}
		if (map.IsPrincessReached()) {
			clear();
			std::string over = "You win";
			while (true) {
				clear();
				mvprintw(2, 2, over.c_str());
				refresh();
			}
		}
		map.DrawMap();
		map.PrintHp();
		refresh();
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
}

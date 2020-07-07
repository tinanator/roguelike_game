#pragma once
#include "curses.h"

class Map;
static class GameLoop
{
public:
	GameLoop(Map& map);
	void Run();

private:
	Map& map;
};


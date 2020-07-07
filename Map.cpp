#include "Map.h"
#include "Character.h"
#include "curses.h"
#include <memory>
#include "Knight.h"
#include "Bullet.h"
#include "KnightCreator.h"
#include "ZombieCreator.h"
#include "DragonCreator.h"
#include <fstream>
#include "KBulletCreator.h"
#include "DBulletCreator.h"
#include "AidCreator.h"
#include "Princess.h"
#include "PrincessCreator.h"
#include <functional>


Map::Map(std::vector<std::string>& _map, int h, int w):map(_map),
height(h), width(w), knight(nullptr){
	for (int i = 0; i < h; i++) {
		std::string str = "";
		for (int j = 0; j < w; j++) {
			str += map[i][j];
		}
		copyMap.push_back(str);
	}
}

std::unique_ptr<Character> Map::CreateObject(std::string id) {
	return creators[id]->CreateObject(id);
}


void Map::InitializeCreators() {
	ReadConfigFile();
	auto k = std::move(CreateObject("Knight"));
	Point pos = GetEmptyPoint();
	k->SetPos(pos.x, pos.y);
	SetKnight(dynamic_cast<Knight*>(k.get()));
	UpdateObjectPosition(pos.x, pos.y, k->GetSym());
	AddGameObject(std::move(k));


	for (int i = 0; i < 4; i++) {
		k = std::move(CreateObject("Zombie"));
		pos = GetEmptyPoint();
		k->SetPos(pos.x, pos.y);
		UpdateObjectPosition(pos.x, pos.y, k->GetSym());
		AddGameObject(std::move(k));

	}
	for (int i = 0; i < 4; i++) {
		k = std::move(CreateObject("Dragon"));
		pos = GetEmptyPoint();
		k->SetPos(pos.x, pos.y);
		UpdateObjectPosition(pos.x, pos.y, k->GetSym());
		AddGameObject(std::move(k));
	}

	for (int i = 0; i < 5; i++) {
		k = std::move(CreateObject("AidKid"));
		pos = GetEmptyPoint();
		k->SetPos(pos.x, pos.y);
		UpdateObjectPosition(pos.x, pos.y, k->GetSym());
		AddGameObject(std::move(k));
	}

	k = std::move(CreateObject("Princess"));
	pos = GetEmptyPoint();
	k->SetPos(pos.x, pos.y);
	SetPrincess(dynamic_cast<Princess*>(k.get()));
	UpdateObjectPosition(pos.x, pos.y, k->GetSym());
	AddGameObject(std::move(k));
}
void Map::ReadConfigFile() {
	std::ifstream cf("config.txt");
	std::string fields = "";
	std::vector<std::string> c(28);
	for (int i = 0; i < 28; i++) {
		cf >> c[i];
	}
	creators[c[0]] = std::make_unique<KnightCreator>(c[0], std::stoi(c[1]), std::stoi(c[2]),
		std::stoi(c[3]), c[4][0]);
	creators[c[5]] = std::make_unique<ZombieCreator>(c[5], std::stoi(c[6]), std::stoi(c[7]),
		std::stoi(c[8]), c[9][0], std::stoi(c[10]));
	creators[c[11]] = std::make_unique<DragonCreator>(c[11], std::stoi(c[12]), std::stoi(c[13]),
		std::stoi(c[14]), c[15][0], std::stoi(c[16]));
	creators[c[17]] = std::make_unique<KBulletCreator>(c[17], Point(0, 0), Point(0, 0), std::stoi(c[18]), c[19][0]);
	creators[c[20]] = std::make_unique<DBulletCreator>(c[20], Point(0, 0), Point(0, 0), std::stoi(c[21]), c[22][0]);
	creators[c[23]] = std::make_unique<AidCreator>(c[23], std::stoi(c[24]), c[25][0]);
	creators[c[26]] = std::make_unique<PrincessCreator>(c[26], c[27][0]);
}
Point Map::GetEmptyPoint() {
	int y = 0; int x = 0;
	while (copyMap[y][x] != '.') {
		x = rand() % width;
		y = rand() % height;
	}
	return Point(x, y);
}
void Map::SetKnight(Knight* k) {
	knight = k;
}

void Map::SetPrincess(Princess* p) {
	princess = p;
}

void Map::DrawMap() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i > knight->GetPos().y - 5 &&
				i < knight->GetPos().y + 5 &&
				j > knight->GetPos().x - 10 && 
				j < knight->GetPos().x + 10) {

				addch(copyMap[i][j]);
				
			}
			else
				addch('-');
		}
		addch('\n');
	}
}

void Map::AddBullet(std::unique_ptr<Character> obj){
	bullets.push_back(std::move(obj));
}


int Map::IsKnightInRadius(int x, int y, int radius) {
	int _x = x;
	int _y = y;
	std::vector<std::function<void(int&, int&)>> directions = {
	[](int& _x, int& _y) {
		_x++;
	},
	[](int& _x, int& _y) {
		_x--;
	},
	[](int& _x, int& _y) {
		_y++;
	},
	[](int& _x, int& _y) {
		_y--;
	} };

	std::vector<int> res = { 1, 2, 3 ,4 };

	for (int i = 0; i < 4; i++) {
		for (_x = x, _y = y; _x < width && _x >= 0 && _x < x + radius
			&& _y < height && _y >= 0 && _y < y + radius; directions[i](_x, _y)) {
			if (map[_y][_x] == '#') {
				break;
			}
			if (knight->GetPos().x == _x && knight->GetPos().y == _y) {
				return res[i];
			}
		}
	}
	return 0;
}

void Map::AddGameObject(std::unique_ptr<Character> obj) {
   gameObjects.push_back(std::move(obj));
}

void Map::UpdateObjectPosition(int x, int y, char sym) {
	copyMap[y][x] = sym;
}
bool Map::IsPointAvailable(int x, int y) {
	return y < height && y >= 0 && x < width && x >= 0 && copyMap[y][x] != '#';
}

bool Map::Collision(int x, int y, Character& obj) {
	for (int i = 0; i < gameObjects.size(); i++) {
		if (x == gameObjects[i]->GetPos().x && y == gameObjects[i]->GetPos().y) {
			return obj.CollideWith(*gameObjects[i]);
		}
	}
	return false;
}



void Map::UpdateMap() {
	MakeCopy();
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Move(*this);
		int x = gameObjects[i]->GetPos().x;
		int y = gameObjects[i]->GetPos().y;
		UpdateObjectPosition(x, y, gameObjects[i]->GetSym());
	}
	for (int i = 0; i < bullets.size(); i++) {
		int x = bullets[i]->GetPos().x;
		int y = bullets[i]->GetPos().y;
		if (Collision(x, y, *bullets[i])) {
			bullets.erase(bullets.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Move(*this);
		int x = bullets[i]->GetPos().x;
		int y = bullets[i]->GetPos().y;
		if ( Collision(x, y, *bullets[i]) || x == width || x < 0||
			y == height || y < 0 || map[y][x] == '#' ) {
			bullets.erase(bullets.begin() + i);
			i--;
		} 
	}
	for (int i = 0; i < bullets.size(); i++) {
		UpdateObjectPosition(bullets[i]->GetPos().x, bullets[i]->GetPos().y, bullets[i]->GetSym());
	}
	UpdateObjectPosition(knight->GetPos().x, knight->GetPos().y, knight->GetSym());
	
	if (knight->isDead()) knightDead = true;
	if (princess->IsReached()) princessReached = true;
}

void Map::MakeCopy() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			copyMap[i][j] = map[i][j];
		}
	}
}

bool Map::IsKnightDead() {
	return knightDead;
}
bool Map::IsPrincessReached() {
	return princessReached;
}

void Map::PrintHp() {
	mvprintw(height, 0, "Hp = %d", knight->GetHp());
}
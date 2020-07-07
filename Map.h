#pragma once
#include <vector>
#include <string>
#include "Character.h"
#include <memory>
#include <map>
#include "Creator.h"
class Knight;
class Bullet;
class Map
	
{
public:
	Map(std::vector<std::string>& map, int h, int w);
	void DrawMap();
	void UpdateMap();
	void UpdateObjectPosition(int x, int y, char sym);
	bool IsPointAvailable(int x, int y);
	bool Collision(int x, int y, Character& obj);
	void MakeCopy();
	void AddGameObject(std::unique_ptr<Character> obj);
	void AddBullet(std::unique_ptr<Character> obj);
	void InitializeCreators();
	void ReadConfigFile();
	void SetKnight(Knight* knight);
	void SetPrincess(Princess* p);
	Point GetEmptyPoint();
	std::unique_ptr<Character> CreateObject(std::string id);
	bool IsKnightDead();
	bool IsPrincessReached();
	int IsKnightInRadius(int x, int y, int radius);
	void PrintHp();
	
private:
	bool knightDead = false;
	bool princessReached = false;
	std::vector<std::string> copyMap;
	std::vector<std::string>& map;
	size_t height;
	int width;
	std::vector<std::unique_ptr<Character>> gameObjects;
	Knight* knight = nullptr;
	Princess* princess = nullptr;
	std::vector<std::unique_ptr<Character>> bullets;
	std::map<std::string, std::unique_ptr<Creator>> creators;
	

};


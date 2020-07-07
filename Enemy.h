#pragma once
#include "Character.h";
#include <memory>
//#include "Map.h"
//#include "Knight.h"
//#include "Princess.h"
class Knight;
class Princess;
class Map;
class Bullet;
class Enemy :
	public Character
{
public:
	Enemy(int _hp, int _maxHp, int _damage, char _sym, int _radius);
	void Move(Map& map) override;
	bool CollideWith(Character& obj) override;
	bool CollideWith(Enemy& obj) override;
	bool CollideWith(Knight& obj) override;
	bool CollideWith(Princess& obj) override;
	bool CollideWith(Bullet& obj) override;
	bool CollideWith(AidKid& obj) override;
protected:
	int radius;

};


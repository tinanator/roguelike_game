#pragma once

#include "curses.h"
#include "Character.h";


//#include "Enemy.h"
//#include "Princess.h"
class Enemy;
class Princess;
class Bullet;
class Map;
class AidKid;
class Knight : 
	public Character
{
public:
	Knight(int _hp, int _maxHp, int _damage, char _sym);
	void Move(Map& map) override;
	bool CollideWith(Knight& obj) override;
	bool CollideWith(Enemy& obj)override;
	bool CollideWith(Character& obj) override;
	bool CollideWith(Princess& obj) override;
	bool CollideWith(Bullet& obj) override;
	bool CollideWith(AidKid& obj) override;
	void Shoot(Map&map) override;
	void CheckShooting(Map& map) override;
private:
	Point dir = {1, 0};
};


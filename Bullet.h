#pragma once
#include "Character.h"
class AidKid;
class Enemy;
class Knight;
class Princess;
class Map;
class Bullet :
	public Character
{
public:
	Bullet(Point _pos, Point _dir, int _damage, char _sym);
	void Move(Map& map) override;
	Point GetDir();
	void SetDir(Point _dir) override;
	bool CollideWith(Character& obj) override;
	bool CollideWith(Enemy& obj) override;
	bool CollideWith(Knight& obj) override;
	bool CollideWith(Princess& obj) override;
	bool CollideWith(Bullet& obj) override;
	bool CollideWith(AidKid& obj) override;
	
private:
	Point dir;

};


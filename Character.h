#pragma once
#include "Point.h";
#include <memory>
#include "Object.h"
class Bullet;
//#include "Knight.h"
//#include "Princess.h"
class Enemy;
class Knight;
class Princess;
class Map;
class AidKid;
class Character : public Object
{
public:
	Character() = default;
	Character(Point pos, int _damage, char _char);
	Character(int _hp, int _maxHp, int _damage, char _sym);
	virtual ~Character() = default;
	virtual Point GetPos();
	virtual int GetHp();
	virtual char GetSym();
	virtual int GetMaxHp();
	virtual void SetPos(int x, int y);
	virtual void Move(Map &map);
	virtual int Damage();
	virtual void SetDir(Point _dir);
	virtual void Heal(int hp);
	virtual void Shoot(Map & map);
	virtual void CheckShooting(Map& map);
	virtual bool CollideWith(Character& obj) = 0;
	virtual bool CollideWith(Enemy& obj) = 0;
	virtual bool CollideWith(Knight& obj) = 0;
	virtual bool CollideWith(Princess& obj) = 0;
	virtual bool CollideWith(Bullet& obj) = 0;
	virtual bool CollideWith(AidKid& obj) = 0;
	virtual bool isDead();

protected:
	int hp;
	int maxHp;
	int damage;
	char sym;
	Point pos;
	bool isShooting = false;
	bool dead = false;
};


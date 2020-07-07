#pragma once
#include "Enemy.h"
class Dragon :
	public Enemy
{
public:
	Dragon(int _hp, int _maxHp, int _damage, char _sym, int _radius);
	void Shoot(Map& map) override;
	void Move(Map &map) override;
private:
	Point bulDir;
};


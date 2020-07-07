#pragma once
#include "Enemy.h"
class Zombie :
	public Enemy
{
public:
	Zombie(int _hp, int _maxHp, int _damage, char _sym, int _radius);
	
};


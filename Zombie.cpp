#include "Zombie.h"
#include <string>
Zombie::Zombie(int _hp, int _maxHp, int _damage, char _sym, int _radius) :
	Enemy(_hp, _maxHp, _damage, _sym, _radius) {}

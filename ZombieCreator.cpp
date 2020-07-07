#include "ZombieCreator.h"
#include "Zombie.h"
ZombieCreator::ZombieCreator(std::string _id, int _hp, int _maxHp, int _damage, char _sym, int _radius): id(_id), hp(_hp),
maxHp(_maxHp), damage(_damage), sym(_sym), radius(_radius) {}
std::unique_ptr<Character> ZombieCreator::CreateObject(std::string id) {
	return std::make_unique<Zombie>(hp, maxHp, damage, sym, radius);
}
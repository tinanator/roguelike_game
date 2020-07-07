#include "DBulletCreator.h"
#include "Bullet.h"
DBulletCreator::DBulletCreator(std::string _id, Point _pos, Point _dir, int _damage, char _sym) :
	id(_id), pos(_pos), dir(_dir), damage(_damage), sym(_sym) {}
std::unique_ptr<Character> DBulletCreator::CreateObject(std::string id) {
	return std::make_unique<Bullet>(pos, dir, damage, sym);
}
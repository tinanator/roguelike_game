#include "KBulletCreator.h"
#include "Bullet.h"
#include <string>
KBulletCreator::KBulletCreator(std::string _id, Point _pos, Point _dir, int _damage, char _sym) :
	id(_id), pos(_pos), dir(_dir), damage(_damage), sym(_sym) {}
std::unique_ptr<Character> KBulletCreator::CreateObject(std::string id) {
	return std::make_unique<Bullet>(pos, dir, damage, sym);
}
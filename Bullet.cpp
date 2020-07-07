#include "Character.h"
#include "Bullet.h"
#include "Knight.h"
#include "Enemy.h"
#include "Princess.h"
#include "Map.h"
Bullet::Bullet(Point _pos, Point _dir, int _damage, char _sym) :
	Character(_pos, _damage, _sym) {
	dir = _dir;
}
void Bullet::SetDir(Point _dir) {
	dir.x = _dir.x;
	dir.y = _dir.y;
}
void Bullet::Move(Map& map) {
	pos.x += dir.x;
	pos.y += dir.y;
}

Point Bullet::GetDir() {
	return dir;
}

bool Bullet::CollideWith(Character& obj) {
	return obj.CollideWith(*this);
}
bool Bullet::CollideWith(Enemy& obj) {
	return true;
}
bool Bullet::CollideWith(Knight& obj) {
	return true;
}
bool Bullet ::CollideWith(Princess& obj) {
	return false;
}
bool Bullet::CollideWith(Bullet& obj) {
	return false;
}

bool Bullet::CollideWith(AidKid& obj) {
	return false;
}

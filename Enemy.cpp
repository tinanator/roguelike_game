#include "Enemy.h"
#include "Character.h"
#include <cstdlib>
#include "Map.h"
#include "Knight.h"
#include "iostream"
#include "Bullet.h"
#include <memory>
#include "Princess.h"
#include "Point.h"

Enemy::Enemy(int _hp, int _maxHp, int _damage, char _sym, int _radius) :
	Character(_hp, _maxHp, _damage, _sym) {
	radius = _radius;

};

void Enemy::Move(Map &map) {

	if (dead) return;
	int x = 0;
	int y = 0;
	Point point;
	std::vector<Point> tmp = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	std::vector<Point> valid;

	for (int i = 0; i < 4; i++) {
		x = tmp[i].x;
		y = tmp[i].y;
		if (map.IsPointAvailable(this->GetPos().x + x, this->GetPos().y + y) &&
			!map.Collision(this->GetPos().x + x, this->GetPos().y + y, *this)) {
			valid.push_back({ x, y });
		}
	}
	if (valid.size() > 0) {
		int v = 0 + rand() % (valid.size());
		SetPos(this->GetPos().x + valid[v].x, this->GetPos().y + valid[v].y);
		valid.clear();
	}

}
bool Enemy::CollideWith(Character& obj) {
	return obj.CollideWith(*this);
}
bool Enemy::CollideWith(Enemy& obj) {
	if (dead) return false;
	return true;
}
bool Enemy::CollideWith(Knight& obj) {
	if (dead) return false;
	hp -= obj.Damage();
	if (hp <= 0) {
		sym = '.';
		dead = true;
	}
	return true;
}
bool Enemy::CollideWith(Princess& obj) {
	return false;
}

bool Enemy::CollideWith(Bullet& obj) {
	if (dead) return false;
   	hp -= obj.Damage();
	if (hp <= 0) {
		sym = '.';
		dead = true;
	}
	return true;
}
bool Enemy::CollideWith(AidKid& obj) {
	return false;
}
#include "Dragon.h"
#include "Map.h"
#include "Enemy.h"
#include "Bullet.h";


void Dragon::Shoot(Map& map) {
	if (dead) return;
	int dir2 = map.IsKnightInRadius(pos.x, pos.y, radius);
	Point d;
	if (dir2 > 0) {
		int r = rand() % 2;
		if (r == 1) {
			isShooting = true;
			if (dir2 == 1) {
				bulDir = Point(1, 0);
			}
			if (dir2 == 2) {
				bulDir = Point(-1, 0);
			}
			if (dir2 == 3) {
				bulDir = Point(0, 1);
			}
			if (dir2 == 4) {
				bulDir = Point(0, -1);
			}
			if (map.IsPointAvailable(pos.x + bulDir.x, pos.y + bulDir.y) &&
				!map.Collision(pos.x + bulDir.x, pos.y + bulDir.y, *this)) {
				auto k = map.CreateObject("DBullet");
				k->SetPos(pos.x + bulDir.x, pos.y + bulDir.y);
				k->SetDir(bulDir);
				map.AddBullet(std::move(k));
			}
		}
	}
}

void Dragon::Move(Map& map) {
	Enemy::Move(map);
	Shoot(map);
}

Dragon::Dragon(int _hp, int _maxHp, int _damage, char _sym, int _radius) :
	Enemy(_hp, _maxHp, _damage, _sym, _radius) {}




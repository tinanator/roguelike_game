#include "Knight.h"
#include "curses.h"
#include "Character.h";
#include "Enemy.h"
#include "Bullet.h"
#include "Map.h"
#include "Princess.h"
#include "AidKid.h"
#include <memory>
//class Enemy;
Knight::Knight(int _hp, int _maxHp, int _damage, char _sym) :
	Character(_hp, _maxHp, _damage, _sym) {

};

void Knight::CheckShooting(Map &map) {
	
}

void Knight::Shoot(Map& map) {
	if (map.IsPointAvailable(pos.x + dir.x, pos.y + dir.y) && !map.Collision(pos.x + dir.x, pos.y + dir.y, *this)) {
		auto k = map.CreateObject("KBullet");
		k->SetDir(dir);
		k->SetPos(pos.x + dir.x, pos.y + dir.y);
		map.AddBullet(std::move(k));
	}
	
}

void Knight::Move(Map& map)  {
	nodelay(stdscr, TRUE);
	noecho();
	int x = 0;
	int y = 0;
	char ch = getch();
	while (true) {
		if (ch == -1) {
			break;
		}
		switch (ch) {
			case 'w': {
				x = 0;
				y = -1;
				dir = { x, y };
				break;
			}
			case 'a': {
				x = -1;
				y = 0;
				dir = { x, y };
				break;
			}
			case 'd': {
				x = 1;
				y = 0;
				dir = { x, y };
				break;
			}
			case 's': {
				x = 0;
				y = 1;
				dir = { x, y };
				break;
			}
			case ' ': {
				Shoot(map);
			}
		}
		if (map.IsPointAvailable(this->GetPos().x + x, this->GetPos().y + y)
			&& !map.Collision(this->GetPos().x + x, this->GetPos().y + y, *this)) {
			this->SetPos(this->GetPos().x + x, this->GetPos().y + y);
			break;
		}
		ch = -1;	
	}
}

bool Knight::CollideWith(Enemy& obj) {
	hp -= obj.Damage();
	if (hp <= 0) {
		sym = 'T';
		dead = true;
	}
	return true;
}
bool Knight::CollideWith(Knight& obj) {
	return false;
}
bool Knight::CollideWith(Princess& obj) {
	return true;
}
bool Knight::CollideWith(Character& obj) {
	return obj.CollideWith(*this);
	//return false;
}
bool Knight::CollideWith(Bullet& obj) {
	hp -= obj.Damage();
	if (hp <= 0) {
		sym = 'T';
  		dead = true;
	}
	return true;
}
bool Knight::CollideWith(AidKid& obj) {
	
	return false;
}
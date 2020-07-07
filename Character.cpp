#include "Character.h"

class Enemy;
class Knight;
class Princess;
	Character::Character(Point _pos, int _damage, char _sym): pos(_pos), hp(0), maxHp(0) , damage(_damage), sym(_sym) {}
	Character::Character(int _hp, int _maxHp, int _damage, char _sym): hp(_hp), maxHp(_maxHp), damage(_damage), sym(_sym) {
	}

	void Character::SetDir(Point _dir) {}
	Point Character::GetPos() {
		return pos;
	}

	void Character::Shoot(Map& map) {}
	int Character::GetHp() {
		return hp;
	}

	void Character::Heal(int _hp) {
		hp += _hp;
		if (hp > maxHp) {
			hp = maxHp;
		}
	}

	void Character::CheckShooting(Map &map) {}
	int Character::GetMaxHp() {
		return maxHp;
	}

	char Character::GetSym() {
		return sym;
	}

	void Character::SetPos(int x, int y) {
		this->pos.x = x;
		this->pos.y = y;
	}

	void Character::Move(Map& map) {}

	int Character::Damage() {
		return damage;
	}

	bool Character::isDead() {
		return dead;
	}

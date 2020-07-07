#pragma once
#include "Creator.h"
class DragonCreator :
	public Creator
{
public:
	DragonCreator(std::string id, int _hp, int _maxHp, int _damage, char _sym, int _radius);
	std::unique_ptr<Character> CreateObject(std::string id) override;
private:
	std::string id;
	int hp;
	int maxHp;
	int damage;
	char sym;
	int radius;
};


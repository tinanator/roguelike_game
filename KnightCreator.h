#pragma once
#include "Creator.h"
class KnightCreator :
	public Creator
{
public:
	KnightCreator(std::string id, int _hp, int _maxHp, int _damage, char _sym);
	std::unique_ptr<Character> CreateObject(std::string id) override;
private:
	std::string id;
	int hp;
	int maxHp;
	int damage;
	char sym;

};


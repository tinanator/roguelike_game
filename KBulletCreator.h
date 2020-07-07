#pragma once
#include "Creator.h"
#include "Point.h"
class KBulletCreator :
	public Creator
{
public:
	KBulletCreator(std::string id, Point _pos, Point _dir, int _damage, char _sym);
	std::unique_ptr<Character> CreateObject(std::string id) override;
private:
	std::string id;
	Point pos;
	Point dir;
	int damage;
	char sym;
};


#pragma once
#include "Character.h"
class AidKid :
	public Character
{
public:
	AidKid(int hp, char _sym);
	bool IsValid();
	void SetValid();
	bool CollideWith(Knight& obj) override;
	bool CollideWith(Enemy& obj)override;
	bool CollideWith(Character& obj) override;
	bool CollideWith(Princess& obj) override;
	bool CollideWith(Bullet& obj) override;
	bool CollideWith(AidKid& obj) override;
private:
	bool valid = true;
};


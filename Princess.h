#pragma once
#include "Character.h"
class Princess : public Character
{
public:
	Princess(char _sym);
	bool IsReached();
	void SetReached();
	bool CollideWith(Character& obj) override;
	bool CollideWith(Enemy& obj) override;
	bool CollideWith(Knight& obj) override;
	bool CollideWith(Princess& obj) override;
	bool CollideWith(Bullet& obj) override;
	bool CollideWith(AidKid& obj) override;
private:
	bool reached = false;
};


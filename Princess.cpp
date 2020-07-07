#include "Princess.h"
#include "Knight.h"
#include "curses.h"
#include "Character.h";
#include "Enemy.h"
#include "Bullet.h"
#include "Map.h"
#include "AidKid.h"
#include <memory>
Princess::Princess(char _sym) {
	sym = _sym;
}

bool Princess::IsReached() {
	return reached;
}

void Princess::SetReached() {
	reached = true;
}

bool Princess::CollideWith(Enemy& obj) {
	return true;
}
bool Princess::CollideWith(Knight& obj) {
	reached = true;
	return true;
}
bool Princess::CollideWith(Princess& obj) {
	return false;
}
bool Princess::CollideWith(Character& obj) {
	return obj.CollideWith(*this);
}
bool Princess::CollideWith(Bullet& obj) {
	return false;
}
bool Princess::CollideWith(AidKid& obj) {
	return false;
}
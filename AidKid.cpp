
#include "Knight.h"
#include "curses.h"
#include "Character.h";
#include "Enemy.h"
#include "Bullet.h"
#include "Map.h"
#include "Princess.h"
#include "AidKid.h"
#include <memory>

AidKid::AidKid(int _hp, char _sym) {
	hp = _hp;
	sym = _sym;

}
bool AidKid::IsValid() {
	return valid;
}
void AidKid::SetValid() {
	valid = true; 
}
bool AidKid::CollideWith(Enemy& obj) {
	return false;
}
bool AidKid::CollideWith(Knight& obj) {
	if (IsValid()) {
		obj.Heal(hp);
		valid = false;
		sym = '.';
	}
	return false;
}
bool AidKid::CollideWith(Princess& obj) {
	return false;
}
bool AidKid::CollideWith(Character& obj) {
	return obj.CollideWith(*this);
}
bool AidKid::CollideWith(Bullet& obj) {
	return false;
}
bool AidKid::CollideWith(AidKid& obj) {
	return true;
}
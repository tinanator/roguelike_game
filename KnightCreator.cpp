#include "KnightCreator.h"
#include "Knight.h"
KnightCreator::KnightCreator(std::string _id, int _hp, int _maxHp, int _damage, char _sym) : id(_id), hp(_hp),
maxHp(_maxHp), damage(_damage), sym(_sym) {}
std::unique_ptr<Character> KnightCreator::CreateObject(std::string id) {
	return std::make_unique<Knight>(hp, maxHp, damage, sym);
}
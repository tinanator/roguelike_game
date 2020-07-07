#include "AidCreator.h"
#include "AidKid.h"
#include <memory>
AidCreator::AidCreator(std::string _id, int _hp, char _sym) :
	id(_id), hp(_hp), sym(_sym) {}
std::unique_ptr<Character> AidCreator::CreateObject(std::string id) {
	return std::make_unique<AidKid>(hp, sym);
}
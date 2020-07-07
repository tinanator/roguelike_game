#include "PrincessCreator.h"
#include "Princess.h"
PrincessCreator::PrincessCreator(std::string _id, char _sym) : id(_id), sym(_sym) {}
std::unique_ptr<Character> PrincessCreator::CreateObject(std::string id) {
	return std::make_unique<Princess>(sym);
}
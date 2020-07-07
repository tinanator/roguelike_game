#pragma once
#include "Creator.h"
#include <string>
#include "Point.h"
class AidCreator :
	public Creator
{
public:
	AidCreator(std::string id, int _hp, char _sym);
	std::unique_ptr<Character> CreateObject(std::string id) override;
private:
	std::string id;
	int hp;
	char sym;

};


#pragma once
#include "Creator.h"
class PrincessCreator : public Creator
{
public:
	PrincessCreator(std::string id,  char _sym);
	std::unique_ptr<Character> CreateObject(std::string id) override;
private:
	std::string id;
	char sym;
};


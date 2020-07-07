#pragma once
#include "Object.h"
#include <memory>
#include <string>
class Character;
class Creator
{
public:
	Creator() = default;
	virtual ~Creator() = default;
	virtual std::unique_ptr<Character> CreateObject(std::string id) = 0;
};


#pragma once

#include "Item.h"
#include <string>

using namespace std;

class Sword :
	public Item
{
private:
	int power;
public:
	Sword();

	Sword(int _idSword, int _var, string _name, string _descriptionOrUse);

	~Sword();

	int getPower();
	void setPower(int newPower);
};


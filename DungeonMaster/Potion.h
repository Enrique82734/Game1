#pragma once

#include "Item.h"
#include <string>

using namespace std;

class Potion :
	public Item
{
private:
	int lifeRestored;
public:
	Potion();

	Potion(int _idPotion, int _var, string _name, string _descriptionOrUse);

	~Potion();

	int getLifeRestored();
	void setLifeRestored(int newLifeRestored);
};


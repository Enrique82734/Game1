#pragma once

#include "Item.h"
#include <string>

using namespace std;

class Shield :
	public Item
{
private:
	int defence;
public:
	Shield();

	Shield(int _idShield, int _var, string _name, string _descriptionOrUse);

	~Shield();

	int getDefence();
	void setDefence(int newDefence);
};


#pragma once

#include "Item.h"
#include <string>

using namespace std;

class Key : public Item
{
public:
	int idKey;
	Key();

	Key(int _idKey, string _name);

	~Key();
};
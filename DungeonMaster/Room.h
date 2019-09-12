#pragma once

#include "Item.h"
#include "Door.h"
#include "Enemy.h"

#include <string>
#include <vector>
#include <list>

#include <iostream>

using namespace std;

class Room
{
public:
	list<Door> doors;

	vector<Item*> items;

	vector<Enemy*> enemies;

	string description;

	Room();
	Room(list<Door> _doors, vector<Item*> _items, vector<Enemy*> _enemies, string _description) :
		doors(_doors), items(_items), enemies(_enemies), description(_description) {};

	~Room();
};


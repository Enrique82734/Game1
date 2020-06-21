#pragma once
#include "Enemy.h"
class Minion :
	public Enemy
{
public:
	Minion();

	Minion(int _enemyid, int _life, int _power, int _defence, bool _alive, string _name, string _text, map<int, string> _enemyInventory);

	~Minion();
};


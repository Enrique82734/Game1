#pragma once
#include "Enemy.h"
class Boss :
	public Enemy
{
public:
	Boss();

	Boss(int _life, int _power, int _defence, bool _alive, string _name, string _text, map<int, string> _enemyInventory);

	~Boss();
};


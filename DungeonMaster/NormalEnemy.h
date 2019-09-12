#pragma once
#include "Enemy.h"
class NormalEnemy :
	public Enemy
{
public:
	NormalEnemy();

	NormalEnemy(int _life, int _power, int _defence, bool _alive, string _name, string _text, map<int, string> _enemyInventory);

	~NormalEnemy();
};


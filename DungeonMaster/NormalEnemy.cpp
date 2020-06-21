#include "pch.h"
#include "NormalEnemy.h"


NormalEnemy::NormalEnemy()
{
}

NormalEnemy::NormalEnemy(int _enemyid, int _life, int _power, int _defence, bool _alive, string _name, string _text, map<int, string> _enemyInventory)
	: Enemy(_enemyid, _life, _power, _defence, _alive, _name, _text, _enemyInventory)
{
}


NormalEnemy::~NormalEnemy()
{
}

#include "pch.h"
#include "Enemy.h"


Enemy::Enemy()
{
}

Enemy::Enemy(int _life, int _power, int _defence, bool _alive, string _name, string _text, map<int, string> _enemyInventory)
{
	life = _life;
	power = _power;
	defence = _defence;
	alive = _alive;
	name = _name;
	text = _text;
	enemyInventory = _enemyInventory;
}


Enemy::~Enemy()
{
}


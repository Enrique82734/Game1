#include "pch.h"
#include "Minion.h"


Minion::Minion()
{
}

Minion::Minion(int _life, int _power, int _defence, bool _alive, string _name, string _text, map<int, string> _enemyInventory) 
	: Enemy(_life, _power, _defence, _alive, _name, _text, _enemyInventory)
{
}


Minion::~Minion()
{
}

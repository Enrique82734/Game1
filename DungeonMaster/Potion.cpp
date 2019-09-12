#include "pch.h"
#include "Potion.h"


Potion::Potion()
{
}

Potion::Potion(int _id, int _var, string _name, string _descriptionOrUse) :Item(_name, _descriptionOrUse, _var, _id)
{
	lifeRestored = _var;
}


Potion::~Potion()
{
}

int Potion::getLifeRestored()
{
	return lifeRestored;
}

void Potion::setLifeRestored(int newLifeRestored)
{
	lifeRestored = newLifeRestored;
}

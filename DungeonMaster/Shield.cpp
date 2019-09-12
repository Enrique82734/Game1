#include "pch.h"
#include "Shield.h"


Shield::Shield()
{
}

Shield::Shield(int _id, int _var, string _name, string _descriptionOrUse) : Item(_name, _descriptionOrUse, _var, _id)
{
	defence = _var;
}


Shield::~Shield()
{
}

int Shield::getDefence()
{
	return defence;
}

void Shield::setDefence(int newDefence)
{
	defence = newDefence;
}

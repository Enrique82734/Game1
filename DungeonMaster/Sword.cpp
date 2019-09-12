#include "pch.h"
#include "Sword.h"


Sword::Sword()
{
}

Sword::Sword(int _id, int _var, string _name, string _descriptionOrUse) : Item(_name, _descriptionOrUse, _var, _id)
{
	power = _var;
}


Sword::~Sword()
{
}

int Sword::getPower()
{
	return power;
}

void Sword::setPower(int newPower)
{
	power = newPower;
}

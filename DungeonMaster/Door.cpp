#include "pch.h"
#include "Door.h"


Door::Door()
{
}

Door::Door(int _idDoor, bool _closedDoor)
{
	idDoor = _idDoor;
	closedDoor = _closedDoor;
}


Door::~Door()
{
}

int Door::getIdDoor()
{
	return idDoor;
}

void Door::setIdDoor(int _newIdDoor)
{
	idDoor = _newIdDoor;
}

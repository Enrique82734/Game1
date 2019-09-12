#pragma once

#include <string>

using namespace std;

class Door
{
private:
	int idDoor;
public:
	bool closedDoor;

	Door();

	Door(int _idDoor, bool _closedDoor);

	~Door();

	int getIdDoor();
	void setIdDoor(int _newIdDoor);
};


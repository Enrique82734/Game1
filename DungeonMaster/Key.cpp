#include "pch.h"
#include "Key.h"


Key::Key()
{
}

Key::Key(int _idKey, string _name) : Item(_name, _idKey)
{
	idKey = _idKey;
}


Key::~Key()
{
}

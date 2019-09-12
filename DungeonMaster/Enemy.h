#pragma once
#include <string>
#include <map>

using namespace std;

class Enemy
{
public:
	int life, power, defence;
	bool alive;
	string name;
	string text;
	map<int, string> enemyInventory;

	Enemy();
	Enemy(int _life, int _power, int _defence, bool _alive, string _name, string _text, map<int, string> _enemyInventory);

	virtual ~Enemy();
};
//
//inline bool operator==(const Enemy& a, const Enemy& b) {
//	return true;
//}


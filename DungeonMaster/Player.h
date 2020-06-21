#pragma once

#include "Character.h"
#include "Shield.h"
#include "Sword.h"
#include "Potion.h"
#include "Key.h"
#include "Door.h"
#include "Enemy.h"
#include "Boss.h"
#include "Minion.h"
#include "NormalEnemy.h"
#include "Room.h"

#include <set>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <fstream>

//Incluir siempre que uses cout
#include <iostream>

using namespace std;

class Player
{
public:
private:
	int actualRoom, previousRoom;
	int life, power, defence;
public:
	vector<Key> keySorter;

	vector<Shield> shieldSorter;

	vector<Sword> swordSorter;

	vector<Potion> potionSorter;

	map<int, string> objectInventory;

	string name;
	string text;

	Room room;

	Player();
	Player(int _actualRoom, int _previousRoom, vector<Key> _keySorter, vector<Shield> _shieldSorter, vector<Sword> _swordSorter,
		vector<Potion> _potionSorter, map<int, string> _objectInventory, int _life, int _power, int _defence, string _name, string _text);

	~Player();

	int getActualRoom();
	void setActualRoom(int newActualRoom);

	int getPreviousRoom();
	void setPreviousRoom(int newPreviousRoom);

	int getLife();
	void setLife(int newLife);

	int getPower();
	void setPower(int newPower);

	int getDefence();
	void setDefence(int newDefence);

	// Si la puerta esta cerrada y no tienes la llave
	// Si la puerta esta cerrada y si tienes la llave
	// Si la puerta esta abierta
	void changeRoom(int doorToRoom, map<int, Room>& doorChange);
	void openDoor(int doorToRoom, map<int, Room>& doorChange);

	// Si no tienes una llave
	// Si si tienes una llave y tienes espacio para otra
	// Si si tienes una llave y no tienes espacio para otra
	void pickupKey(int pickKey, map<int, Room>& doorChange);
	void dropKey(int dropKey, map<int, Room>& doorChange);
	// Si no tienes un escudo / espada
	// Si si tienes un escudo / espada
	void pickupShield(int pickKey, map<int, Room>& shieldToInven);
	void dropShield(int dropShield, map<int, Room>& shieldToInven);
	void pickupSword(int pickSword, map<int, Room>& swordToInven);
	void dropSword(int dropSword, map<int, Room>& swordToInven);
	void dropSword(int dropSword, vector<Item*>& chunches);
	// Si no tienes una pocion
	// Si si tienes una pocion y tienes espacio para mas
	// Si s tienes una pocion y no tienes espaco para mas
	void pickupPotion(int pickPotion, map<int, Room>& potionToInven);
	void dropPotion(int dropPotion, map<int, Room>& potionToInven);

	// A cual enemgo estoy atacando y cuanto daño le hago
	void attackEnemy(int enemyPos, map<int, Room>& roomEnemy);

	// Cuanto daño me hacen mientras estoy en defensa
	void defend(int enemyPos, map<int, Room>& roomEnemy);

	// Recorrer todas las listas y poner informacion de ellas
	void inventory();

	//Guardar y leer partida anterior
	void loadGame(Player&);
	void saveGame(Player&);

	// Lootear el enemigo si tiene algo en el inventario
	// Si no regresa el mensaje de que no tiene loot
	void lootEnemies(int enemyLoot, map<int, string>/*map<int, Room>& roomEnemy*/);

	// Utilizar una pocion si se tiene una y añadir la cantidad de vida al total
	void usePotion(int usedPotion);

	// Revisar la cantidad de items que tiene y ver si alcanzan para craftear algo, luego dar la cantidad
	// posible para craftear reducirla del total, crear las pociones y añadirlas
	void crafting();

	// Place in screen the room information
	void roomInformation(map<int, Room> roomInfo);
};


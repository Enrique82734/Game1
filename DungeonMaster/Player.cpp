#include "pch.h"
#include "Player.h"


Player::Player()
{
}

Player::Player(int _actualRoom, int _previousRoom, vector<Key> _keySorter, vector<Shield> _shieldSorter, vector<Sword> _swordSorter,
	vector<Potion> _potionSorter, map<int, string> _objectInventory, int _life, int _power, int _defence, string _name, string _text)
{
	actualRoom = _actualRoom;
	previousRoom = _previousRoom;
	keySorter = _keySorter;
	shieldSorter = _shieldSorter;
	swordSorter = _swordSorter;
	potionSorter = _potionSorter;
	objectInventory = _objectInventory;
	life = _life;
	power =_power;
	defence =_defence;
	name = _name;
	text = _text;
}


Player::~Player()
{
}

int Player::getActualRoom()
{
	return actualRoom;
}

void Player::setActualRoom(int newActualRoom)
{
	actualRoom = newActualRoom;
}

int Player::getPreviousRoom()
{
	return previousRoom;
}

void Player::setPreviousRoom(int newPreviousRoom)
{
	previousRoom = newPreviousRoom;
}

int Player::getLife()
{
	return life;
}

void Player::setLife(int newLife)
{
	life = newLife;
}

int Player::getPower()
{
	return power;
}

void Player::setPower(int newPower)
{
	power = newPower;
}

int Player::getDefence()
{
	return defence;
}

void Player::setDefence(int newDefence)
{
	defence = newDefence;
}

void Player::changeRoom(int doorToRoom, map<int, Room>& doorChange)
{
	for (Door& door : doorChange.at(doorToRoom).doors) {
		if (door.getIdDoor() == doorToRoom) {
			if (door.closedDoor) {
				cout << "La puerta esta bloqueada, se requiere la llave numero: " << door.getIdDoor() << "\n";

			} else {
				cout << "Pasando a la siguiente habitacion...\n\n";
				previousRoom = actualRoom;
				actualRoom = door.getIdDoor();
			}
		}
	}
}

void Player::openDoor(int doorToRoom, map<int, Room>& doorChange)
{
	for (Door& door : doorChange.at(doorToRoom).doors) {
		if (door.getIdDoor() == doorToRoom) {
			if (door.closedDoor) {
				for (Key key : keySorter) {
					if (key.idKey == door.getIdDoor()) {
						cout << "Puerta desbloqueada\n\n";
						door.closedDoor = false;
					} else {
						cout << "La puerta esta bloqueada, se requiere la llave numero: " << door.getIdDoor() << "\n";
					}
				}
			}
		}
	}
}

void Player::pickupKey(int pickKey, map<int, Room>& keyToInven)
{
	try {
		for (Item* key : keyToInven.at(actualRoom).items) {
			if (key == dynamic_cast<Key*>(key)) {
				if (key->id == pickKey) {
					cout << "La llave numero " << key->id << " fue insertada en el invetario\n";
					//cout << "llego";
					Key* insertKey = dynamic_cast<Key*>(key);
					keySorter.push_back(*insertKey);
					keyToInven.at(actualRoom).items.erase(remove(keyToInven.at(actualRoom).items.begin(), keyToInven.at(actualRoom).items.end(), key));
					keyToInven.at(actualRoom).items.shrink_to_fit();
				}
			} else {
				cout << "No hay una llave en el cuarto\n";
			}
		}
	} catch (exception e) {
		cout << "Esa llave no existe\n";
	}
}

void Player::dropKey(int dropKey, map<int, Room>& keyToInven)
{
	try {
		for (Key key : keySorter) {
			if (key.idKey == dropKey) {
				Item* insertKey = &key;
				keyToInven.at(actualRoom).items.push_back(insertKey);
				keySorter.erase(remove(keySorter.begin(), keySorter.end(), key));
				keySorter.shrink_to_fit();
			}
		}
	} catch (exception e) {
		cout << "Esa llave no existe\n";
	}
}

void Player::pickupShield(int dropShield, map<int, Room>& shieldToInven)
{
	try {
		for (Item* shield : shieldToInven.at(actualRoom).items) {
			if (shield == dynamic_cast<Shield*>(shield)) {
				if (shield->id == dropShield) {
					cout << "El escudo llamado " << shield->name << " fue insertado en el invetario\n";
					Shield* insertShield = dynamic_cast<Shield*>(shield);
					shieldSorter.push_back(*insertShield);
					power += shield->var;
					shieldToInven.at(actualRoom).items.erase(remove(shieldToInven.at(actualRoom).items.begin(), shieldToInven.at(actualRoom).items.end(), shield));
					shieldToInven.at(actualRoom).items.shrink_to_fit();
				}
			} else {
				cout << "No hay un escudo en el cuarto\n";
			}
		}
	} catch (exception e) {
		cout << "Ese escudo no existe\n";
	}
}

void Player::dropShield(int dropShield, map<int, Room>& shieldToInven)
{
	try {
		for (Shield shield : shieldSorter) {
			if (shield.id == dropShield) {
				Item* insertShield = &shield;
				shieldToInven.at(actualRoom).items.push_back(insertShield);
				shieldSorter.erase(remove(shieldSorter.begin(), shieldSorter.end(), shield));
				shieldSorter.shrink_to_fit();
			}
		}
	} catch (exception e) {
		cout << "Ese escudo no existe\n";
	}
}

void Player::pickupSword(int pickSword, map<int, Room>& swordToInven)
{
	try {
		for (Item* sword : swordToInven.at(actualRoom).items) {
			if (sword == dynamic_cast<Sword*>(sword)) {
				if (sword->id == pickSword) {
					cout << "La espada llamada " << sword->name << " fue insertada en el invetario\n";
					Sword* insertSword = dynamic_cast<Sword*>(sword);
					swordSorter.push_back(*insertSword);
					swordToInven.at(actualRoom).items.erase(remove(swordToInven.at(actualRoom).items.begin(), swordToInven.at(actualRoom).items.end(), sword));
					swordToInven.at(actualRoom).items.shrink_to_fit();
				}
			} else {
				cout << "No hay una espada en el cuarto\n";
			}
		}
	} catch (exception e) {
		cout << "Esa espada no existe\n";
	}
}

void Player::dropSword(int dropSword, map<int, Room>& swordToInven)
{
	try {
		for (Sword sword : swordSorter) {
			if (sword.id == dropSword) {
				Item* insertSword = &sword;
				swordToInven.at(actualRoom).items.push_back(insertSword);
				swordSorter.erase(remove(swordSorter.begin(), swordSorter.end(), sword));
				swordSorter.shrink_to_fit();
			}
		}
	} catch (exception e) {
		cout << "Esa espada no existe\n";
	}
}

void Player::pickupPotion(int pickPotion, map<int, Room>& potionToInven)
{
	try {
		for (Item* potion : potionToInven.at(actualRoom).items) {
			if (potion == dynamic_cast<Potion*>(potion)) {
				if (potion->id == pickPotion) {
					cout << "La pocion de " << potion->name << " fue insertada en el invetario\n";
					Potion* insertPotion = dynamic_cast<Potion*>(potion);
					potionSorter.push_back(*insertPotion);
					potionToInven.at(actualRoom).items.erase(remove(potionToInven.at(actualRoom).items.begin(), potionToInven.at(actualRoom).items.end(), potion));
					potionToInven.at(actualRoom).items.shrink_to_fit();
				}
			} else {
				cout << "No hay una pocion en el cuarto\n";
			}
		}
	} catch (exception e) {
		cout << "Esa pocion no existe\n";
	}
}

void Player::dropPotion(int dropPotion, map<int, Room>& potionToInven)
{
	try {
		for (Potion potion : potionSorter) {
			if (potion.id == dropPotion) {
				Item* insertSword = &potion;
				potionToInven.at(actualRoom).items.push_back(insertSword);
				potionSorter.erase(remove(potionSorter.begin(), potionSorter.end(), potion));
				potionSorter.shrink_to_fit();
			}
		}
	} catch (exception e) {
		cout << "Esa pocion no existe\n";
	}
}

void Player::crafting()
{
	//bool pocionBrew;
	for (map<int, string>::iterator it = objectInventory.begin(); it != objectInventory.end(); it++) {
		if (it->first > 0) {
			if (it->second == "carne" || "huesos") {
				
			}
		}
	}
}

void Player::roomInformation(map<int, Room> roomInfo)
{
	string countStuff;
	int tempDead = 0;

	if (roomInfo.at(actualRoom).doors.size() > 1) {
		countStuff = " puertas";
	} else {
		countStuff = " puerta";
	}
	cout << roomInfo.at(actualRoom).description << "\n";

	cout << "En esta habitacion hay " << roomInfo.at(actualRoom).doors.size() << countStuff << "\n";
	for (list<Door>::iterator doorIt = roomInfo.at(actualRoom).doors.begin();
		doorIt != roomInfo.at(actualRoom).doors.end(); doorIt++) {
		string temp = doorIt->closedDoor ? "Cerrada" : "Abierta";
		cout << "La puerta " << doorIt->getIdDoor() << " se encuentra " << temp << "\n\n";
	}

	cout << "\n";

	for (Item* item : roomInfo.at(actualRoom).items) {
		if (roomInfo.at(actualRoom).items.size() > 1) {
			countStuff = " items diferentes";
		} else {
			countStuff = " item";
		}

		cout << "Tienes " << roomInfo.at(actualRoom).items.size() << countStuff << "\n";
		if (item == dynamic_cast<Key*>(item)) {
			cout << "Esta llave se llama " << item->name << " y abre la puerta numero " << item->id << "\n\n";
		}

		if (item == dynamic_cast<Sword*>(item)) {
			cout << "Esta espada de llama " << item->name << " y tiene " << item->var << " fuerza\n";
			cout << "Utiliza el numero " << item->id << " para referirte a ella\n";
			cout << item->descriptionOrUse << "\n";
		}

		if (item == dynamic_cast<Shield*>(item)) {
			cout << "Este escudo se llama " << item->name << " y tiene " << item->var << " de defenza a los ataques\n";
			cout << "Utiliza el numero " << item->id << " para referirte a el\n";
			cout << item->descriptionOrUse << "\n";
		}

		if (roomInfo.at(actualRoom).items.size() > 1) {
			countStuff = " pociones";
		} else {
			countStuff = " pocion";
		}

		cout << "Tienes " << count(roomInfo.at(actualRoom).items.begin(), roomInfo.at(actualRoom).items.end(), dynamic_cast<Potion*>(item)) << countStuff << "\n";
		if (item == dynamic_cast<Potion*>(item)) {
			cout << "Esta pocion es de " << item->name << " y recupera " << item->var << " de vida\n";
			cout << "Utiliza el numero " << item->id << " para referirte a ella\n";
		}
	}

	cout << "\n";

	for (Enemy* enemy : roomInfo.at(actualRoom).enemies) {
		if (roomInfo.at(actualRoom).items.size() > 1) {
			countStuff = " enemigos en la habitacion";
		} else {
			countStuff = " enemigo en la habitacion";
		}

		cout << "Hay " << roomInfo.at(actualRoom).enemies.size() << countStuff << "\n";

		if (roomInfo.at(actualRoom).items.size() > 1) {
			countStuff = " enemigos muertos en la habitacion";
		} else {
			countStuff = " enemigo muerto en la habitacion";
		}

		if (enemy == dynamic_cast<Minion*>(enemy)) {
			for (vector<Enemy*>::iterator it = roomInfo.at(actualRoom).enemies.begin(); it != roomInfo.at(actualRoom).enemies.end(); it++) {
				if (dynamic_cast<Minion*>(*it)->life < 0) {
					tempDead++;
				}
				if (it == roomInfo.at(actualRoom).enemies.end()) {
					cout << "Hay " << count(roomInfo.at(actualRoom).enemies.begin(),
						roomInfo.at(actualRoom).enemies.end(), dynamic_cast<Minion*>(*it)) << countStuff << "\n";
					tempDead = 0;
				}
			}
			cout << "Este es un minion llamado " << enemy->name << " y sus stats son:\n";
			cout << "Vida: " << enemy->life << "\n";
			cout << "Ataque: " << enemy->power << "\n";
			cout << "Defensa: " << enemy->defence << "\n";
			cout << enemy->text << "\n";
		}

		if (enemy == dynamic_cast<NormalEnemy*>(enemy)) {
			cout << "Este es un enemigo llamado " << enemy->name << " y sus stats son:\n";
			cout << "Vida: " << enemy->life << "\n";
			cout << "Ataque: " << enemy->power << "\n";
			cout << "Defensa: " << enemy->defence << "\n";
			cout << enemy->text << "\n";
		}

		if (enemy == dynamic_cast<Boss*>(enemy)) {
			cout << "Este es el Boss llamado " << enemy->name << " y sus stats son:\n";
			cout << "Vida: " << enemy->life << "\n";
			cout << "Ataque: " << enemy->power << "\n";
			cout << "Defensa: " << enemy->defence << "\n";
			cout << enemy->text << "\n";
		}
	}
}

void Player::attackEnemy(int enemyPos, map<int, Room>& roomEnemy)
{
	if (roomEnemy.at(actualRoom).enemies.at(enemyPos - 1)->enemyid == enemyPos) {
		if (roomEnemy.at(actualRoom).enemies.at(enemyPos)->defence < power) {
			roomEnemy.at(actualRoom).enemies.at(enemyPos)->life = roomEnemy.at(actualRoom).enemies.at(enemyPos)->life - (power - roomEnemy.at(actualRoom).enemies.at(enemyPos)->defence);
		}
	}

	if (roomEnemy.at(actualRoom).enemies.at(enemyPos)->life <= 0) {
		roomEnemy.at(actualRoom).enemies.at(enemyPos)->alive = false;
	}
}

void Player::defend(int enemyPos, map<int, Room>& roomEnemy)
{
	if (roomEnemy.at(actualRoom).enemies.at(enemyPos)->power > defence) {
		life = life - (roomEnemy.at(actualRoom).enemies.at(enemyPos)->power - defence);
	}
}

void Player::inventory()
{
	string notExactlyActive;
	string option;
	string delimiter = " ";
	string token;
	size_t pos = 0;

	vector<string> tempOptions{
		("llave", "llaves", "espada", "espadas", "escudo", "escudos", "pocion", "pociones", "loot")
	};

	vector<string> wordsInText;

	cout << "Escribe la parte del inventario que deseas ver\n";
	cout << "Opciones:\nLlaves\nEspadas\nEscudos\nPociones\nLoot de los enemigo\n";
	cin >> option;
	transform(option.begin(), option.end(), option.begin(), [](unsigned char c) { return std::tolower(c); });

	while (pos != string::npos) {
		pos = option.find(delimiter);
		token = option.substr(0, pos);
		wordsInText.push_back(token);
		option.erase(0, pos + delimiter.length());
	}

	for (vector<string>::iterator it = wordsInText.begin(); it != wordsInText.end(); it++) {
		if (*it == "llave" || "llaves") {
			if (keySorter.size() > 1) {
				notExactlyActive = " llaves";
			} else {
				notExactlyActive = " llave";
			}

			cout << "Tienes " << keySorter.size() << notExactlyActive << "\n";
			for (Key key : keySorter) {
				cout << "Nombre de la llave: " << key.name << "\n";
				cout << "LLave de la puerta: " << key.idKey << "\n";
				cout << key.descriptionOrUse << "\n";
			}
		}

		if (*it == "espada" || "espadas") {
			if (swordSorter.size() > 1) {
				notExactlyActive = " espadas";
			} else {
				notExactlyActive = " espada";
			}

			cout << "Tienes " << swordSorter.size() << notExactlyActive << "\n";
			for (Sword sword : swordSorter) {
				cout << "Nombre de la espada: " << sword.name << "\n";
				cout << "La espada hace " << sword.getPower() << " dano\n";
				cout << "Utiliza el numero " << sword.var << " para referirte a ella\n";
				cout << sword.descriptionOrUse << "\n";
			}
		}

		if (*it == "escudo" || "escudos") {
			if (shieldSorter.size() > 1) {
				notExactlyActive = " escudos";
			} else {
				notExactlyActive = " escudo";
			}

			cout << "Tienes " << shieldSorter.size() << notExactlyActive << "\n";
			for (Shield shield : shieldSorter) {
				cout << "Nombre del escudo: " << shield.name << "\n";
				cout << "El escudo otorga " << shield.getDefence() << " de defensa\n";
				cout << "Utiliza el numero " << shield.var << " para referirte a el\n";
				cout << shield.descriptionOrUse << "\n";
			}
		}

		if (*it == "pocion" || "pociones") {
			if (potionSorter.size() > 1) {
				notExactlyActive = " pociones";
			} else {
				notExactlyActive = " pocion";
			}

			cout << "Tienes " << potionSorter.size() << notExactlyActive << "\n";
			for (Potion potion : potionSorter) {
				cout << "Pocion de " << potion.name << "\n";
				cout << "La pocion restaura " << potion.getLifeRestored() << " de defensa\n";
				cout << "Utiliza el numero " << potion.var << " para referirte a ella\n";
				cout << potion.descriptionOrUse << "\n";
			}
		}

		if (*it == "loot") {
			for (map<int, string>::iterator lootIt = objectInventory.begin(); lootIt != objectInventory.end(); lootIt++) {
				cout << "Tienes " << lootIt->first << lootIt->second << "\n";
			}
		}
	}
}

void Player::saveGame(Player &jug) {
	ofstream archivo;
	archivo.open("save.txt", ios::out); //Abriendo el archivo
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo." << endl;
		exit(1);
	}

	string saveRoom;

	archivo << actualRoom;

	archivo.close(); //cerrar el archivo
}

void Player::loadGame(Player &jug) {
	string line;
	ifstream myfile("save.txt");
	int habSa;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			cout << line << '\n';
		}
		habSa = std::stoi(line);
		myfile.close();
	} else cout << "Unable to open file";

	jug.actualRoom;
}

void Player::lootEnemies(int enemyLoot, map<int, string> roomEnemy/*map<int, Room>& roomEnemy*/)
{
	/*for (map<int, string>::iterator it = roomEnemy.at(actualRoom).enemies.at(enemyLoot)->enemyInventory.begin();
									it != roomEnemy.at(actualRoom).enemies.at(enemyLoot)->enemyInventory.end(); it++) {
		for (Enemy* enemy : roomEnemy.at(actualRoom).enemies) {
			if (enemy->alive == false) {
				objectInventory.insert(pair<int, string>(it->first, it->second));
				roomEnemy.at(actualRoom).enemies.at(enemyLoot)->enemyInventory.erase(remove(roomEnemy.at(actualRoom).enemies.at(enemyLoot)->enemyInventory.begin(),
					roomEnemy.at(actualRoom).enemies.at(enemyLoot)->enemyInventory.end(), pair<int, string>(it->first, it->second)));
				cout << "Enemigo looteado!!\n";
			}
		}
	}*/
}

void Player::usePotion(int usedPotion)
{
	for (Potion potion : potionSorter) {
		if (potion.id == usedPotion) {
			life += potion.var;
			cout << "Te has recuperado " << potion.getLifeRestored() << " de vida\n";
			cout << "Tu vida total ahora es de: " << life << "\n";
			potionSorter.erase(remove(potionSorter.begin(), potionSorter.end(), potion));
			potionSorter.shrink_to_fit();
		}
	}
}

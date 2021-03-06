// DungeonMaster.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include "MathLibrary.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <fstream>

#include "Room.h"
#include "Door.h"
#include "Player.h"
#include "Enemy.h"
#include "NormalEnemy.h"
#include "Minion.h"
#include "Boss.h"
#include "Potion.h"
#include "Key.h"
#include "Sword.h"
#include "Shield.h"

Player player;

vector<NormalEnemy*> normalEnemyList{
	new NormalEnemy(1, 5, 1, 0, true, "Pila de Huesos\n",
				string("Puedes eschuchar claramente un movimiento de huesos que parecen estar afilados por el suelo\n"),
				{pair<int, string>(5, "huesos")}),
	new NormalEnemy(2, 10, 2, 1, true, "Esqueleto\n",
				string("Un esqueleto con una espada se te acerca\n"),
				{pair<int, string>(10, "huesos"),
				 pair<int, string>(1, "cabezas")}),
	new NormalEnemy(3, 10, 2, 1, true, "Guardia Esqueleto\n",
				string("Se te aproxima un esqueleto con armadura de oro, una espada magica y ojos rojos\n"),
				{pair<int, string>(20, "huesos"),
				 pair<int, string>(1, "cabezas"),
				 pair<int, string>(20, "monedas de oro")}),
	new NormalEnemy(4, 2, 1, 0, true, "Murcielago pequeno\n",
				string("Enseguida aparece un murcielago buscando tu sangre\n"),
				{pair<int, string>(5, "carne")}),
	new NormalEnemy(5, 10, 2, 1, true, "Zombie\n",
				string("Se ve una figura humanesca pero al acercarse te das cuenta de que esta negro y tiene un brazo ensangrentado en la boca\n"),
				{pair<int, string>(10, "carne"),
				 pair<int, string>(1, "cabezas")}),
	new NormalEnemy(6, 10, 2, 1, true, "Superzombie\n",
				string("Ves un grupo de cadaveres que no parecen tener mucho tiempo alli, al acercarte ves como todos salen disparados y de ellos sale un zombie el triple de grande que tu\n"),
				{pair<int, string>(20, "carne"),
				 pair<int, string>(1, "cabezas"),
				 pair<int, string>(20, "monedas de oro")})
};

vector<Minion*> minionEnemyList{
	new Minion(7, 10, 3, 1, true, "Trasgo\n",
				string("Cuando entraste en la habitacion te encontraste con un trasgo con armadura de metal\n"),
				{pair<int, string>(30, "huesos"),
				 pair<int, string>(5, "cabezas"),
				 pair<int, string>(30, "monedas de oro")}),
	new Minion(8, 20, 4, 2, true, "Chaman\n",
				string("Justo al entrar ves un rayo de energia pasar a tu lado y carboniza la puerta\n"),
				{pair<int, string>(30, "carne"),
				 pair<int, string>(5, "cabezas"),
				 pair<int, string>(30, "monedas de oro")}),
	new Minion(9, 30, 5, 3, true, "Gigante\n",
				string("Ves el ser mas grande de todos los que has visto hasta ahora que empuna un mazo descomunal hacia ti\n"),
				{pair<int, string>(50, "huesos"),
				 pair<int, string>(50, "carne"),
				 pair<int, string>(10, "cabeza"),
				 pair<int, string>(80, "monedas de oro")})
};

vector<Boss*> bossEnemylist{
	new Boss(10, 50, 10, 5, true, "Beholder\n",
				string("Cuando entraste en la habitacion te encontraste con un trasgo con armadura de metal\n"),
				{pair<int, string>(50, "huesos"),
				 pair<int, string>(20, "cabezas"),
				 pair<int, string>(100, "monedas de oro")}) ,
	new Boss(11, 70, 10, 7, true, "Dragon\n",
				string("Justo al entrar ves un rayo de energia pasar a tu lado y carboniza la puerta\n"),
				{pair<int, string>(50, "carne"),
				 pair<int, string>(20, "cabezas"),
				 pair<int, string>(100, "monedas de oro")}) ,
	new Boss(12, 100, 20, 10, true, "Dios de la guerra\n",
				string("Ves el ser mas grande de todos los que has visto hasta ahora que empuna un mazo descomunal hacia ti\n"),
				{pair<int, string>(100, "huesos"),
				 pair<int, string>(100, "carne"),
				 pair<int, string>(100, "cabeza"),
				 pair<int, string>(500, "monedas de oro")}) 
};

map<int, Room> rooms{
		{0, {Room(list<Door>{Door(1, true), Door(2, false), Door(3, false), Door(4, false)},
				  vector<Item*>{new Key(1, "Key of a normal door\n")},
				  vector<Enemy*>{new NormalEnemy(1, 5, 2, 1, true, "Esqueleto\n",
											"Una vez entras al siguiente cuarto se te es lanzada una flecha que te pasa sobre la cabeza casi matandote\n",
											{pair<int, string>(20, "huesos"),
											 pair<int, string>(1, "cabeza")}),
							 new NormalEnemy(2, 2, 2, 1, true, "Murcielago pequeno\n",
											"Enseguida aparece un murcielago buscando tu sangre\n",
											{pair<int, string>(10, "huesos"),
											 pair<int, string>(1, "cabeza")})},
				  string("Eres un aventurero que se encuentra explorando el mundo por sabiduria y riquezas, en tus viajes escuchas que la gente habla de una mazmorra\n y decides dirigirte hacia ella\n"))}},
		{1, {Room(list<Door>{Door(0, false), Door(5, false), Door(6, true)},
				  vector<Item*>{new Key(6, "Key to secondary quest\n")},
				  vector<Enemy*>{normalEnemyList[0], normalEnemyList[1]},
				  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una flecha y un numero marcado con el numero 5\n"))}},
		{2, {Room(list<Door>{Door(0, false), Door(7, true), Door(8, true)},
				  vector<Item*>{new Key(8, "Key of a normal door\n")},
				  vector<Enemy*>{normalEnemyList[0]},
				  string("Al atravesar la puerta descubriste que habia un recetario de pociones en la mesa, al revisarlo detalladamente te diste cuenta de que funcionaba con los objetos que sueltan los enemigos\n"))}},
		{3, {Room(list<Door>{Door(0, false), Door(9, true)},
				  vector<Item*>{new Key(9, "Key of a normal door\n")},
				  vector<Enemy*>{normalEnemyList[3]},
				  string("Mentras investigabas la habitacion descubriste que habia una puerta mas pequena de lo normal por donde solamente entrarias arastrandote\n"))}},
		{4, {Room(list<Door>{Door(0, false), Door(10, true), Door(11, true), Door(12, true)},
				  vector<Item*>{new Key(10, "Key of a normal door\n"), new Key(12, "Key of a normal door\n")},
				  vector<Enemy*>{normalEnemyList[1], normalEnemyList[1]},
				  string("Al entrar te encontraste con unos pedestales en los cuales estaban grabados los numeros: 10 y 12 respectivamente y parecian orientar hacia las puertas laterales\n"))}},
		{5, {Room(list<Door>{Door(1, false), Door(13, true), Door(14, true)},
				  vector<Item*>{new Key(14, "Key of a normal door\n")},
				  vector<Enemy*>{normalEnemyList[4], minionEnemyList[0]},
				  string("Al entrar notaste una precencia maligna como ninguna otra vista hasta ahora pero no pudiste detectar de donde venia sino solo su cercana a ti y entonces supiste <\n"))}},
		{6, {Room(list<Door>{Door(1, false)},
				  vector<Item*>{new Key(7, "Key to secondary quest\n")},
				  vector<Enemy*>{normalEnemyList[3], normalEnemyList[3]},
				  string("Al entrar encuentras una inscripcion en la pared que dice 'Si osas conseguir los tesoros de la zona debereis encontrar una llave hecha de oro'\n"))}},
		{7, {Room(list<Door>{Door(2, false)},
				  vector<Item*>{new Key(16, "Key to secondary quest\n"), new Potion(1, 10, "Life Potion", "Drink for health")},
				  vector<Enemy*>{normalEnemyList[4], normalEnemyList[4]},
				  string("Te encuentras con otra inscripcion que dice 'Continua por este camino y te encontaras con una esperanza a la gloria'\n"))}},
		{8, {Room(list<Door>{Door(2, false), Door(15, true)},
				  vector<Item*>{new Key(15, "Key of a normal door\n")},
				  vector<Enemy*>{normalEnemyList[3]},
				  string("Solo enuentras algunos pinceles y cuadros colgados alrededor de la habitacion\n"))}},
		{9, {Room(list<Door>{Door(3, false)},
				  vector<Item*>{new Key()},
				  vector<Enemy*>{normalEnemyList[5]},
				  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{10, {Room(list<Door>{Door(4, false), Door(16, true), Door(17, true)},
				vector<Item*>{new Key(17, "Key of a normal door\n")},
				  vector<Enemy*>{normalEnemyList[3]},
				  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{11, {Room(list<Door>{Door(4, false)},
				  vector<Item*>{new Key(13, "Key of a normal door\n")},
				  vector<Enemy*>{normalEnemyList[2]},
				  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{12, {Room(list<Door>{Door(4, false), Door(18, true)},
				  vector<Item*>{new Key(6, "Key of a normal door\n")},
				  vector<Enemy*>{normalEnemyList[1], normalEnemyList[4]},
				  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{13, {Room(list<Door>{Door(5, false)},
				  vector<Item*>{new Key(23, "Key of a golden door\n")},
				  vector<Enemy*>{bossEnemylist[2], minionEnemyList[2]},
				  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{14, {Room(list<Door>{Door(0, false), Door(5, false), Door(6, true)},
				  vector<Item*>{new Key(6, "Key to secondary quest\n")},
				  vector<Enemy*>{},
			  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{15, {Room(list<Door>{Door(0, false), Door(5, false), Door(6, true)},
			  vector<Item*>{new Key(6, "Key to secondary quest\n")},
			  vector<Enemy*>{},
			  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{16, {Room(list<Door>{Door(0, false), Door(5, false), Door(6, true)},
			  vector<Item*>{new Key(6, "Key to secondary quest\n")},
			  vector<Enemy*>{},
			  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{17, {Room(list<Door>{Door(0, false), Door(5, false), Door(6, true)},
			  vector<Item*>{new Key(6, "Key to secondary quest\n")},
			  vector<Enemy*>{},
			  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{18, {Room(list<Door>{Door(0, false), Door(5, false), Door(6, true)},
			  vector<Item*>{new Key(6, "Key to secondary quest\n")},
			  vector<Enemy*>{},
			  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{19, {Room(list<Door>{Door(0, false), Door(5, false), Door(6, true)},
			  vector<Item*>{new Key(6, "Key to secondary quest\n")},
			  vector<Enemy*>{},
			  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{20, {Room(list<Door>{Door(0, false), Door(5, false), Door(6, true)},
			  vector<Item*>{new Key(6, "Key to secondary quest\n")},
			  vector<Enemy*>{},
			  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{21, {Room(list<Door>{Door(0, false), Door(5, false), Door(6, true)},
			  vector<Item*>{new Key(6, "Key to secondary quest\n")},
			  vector<Enemy*>{},
			  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{22, {Room(list<Door>{Door(0, false), Door(5, false), Door(6, true)},
			  vector<Item*>{new Key(6, "Key to secondary quest\n")},
			  vector<Enemy*>{},
			  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}},
		{23, {Room(list<Door>{Door(0, false), Door(5, false), Door(6, true)},
			  vector<Item*>{new Key(6, "Key to secondary quest\n")},
			  vector<Enemy*>{},
			  string("Despues de que fuera atacado en la anterior sala y tomando mucho cuidado te diste cuenta de que una de las 2 puertas estaba hecha de plata y en la parte superior tenia una fleca y un numero marcado con el numero 5\n"))}}
};

map<string, map<string, int>> dictionary{
		{ ("abrir", "desbloquear"), {pair<string, int>("puerta", 1) } },
		{ "recojer", {pair<string, int>("espada", 2),
					  pair<string, int>("pocion", 3),
					  pair<string, int>("escudo", 4),
					  pair<string, int>("llave", 5)} },
		{ "atacar", { pair<string, int>("enemigo", 6),
					  pair<string, int>("monstruo", 6),
					  pair<string, int>("monstro", 6) } },
		{ "cambiar", { pair<string, int>("habitacion", 7) } },
		{ "consultar", { pair<string, int>("inventario", 8),
						 pair<string, int>("recetas", 9),
						 pair<string, int>("bestiario", 10) } },
		{ "tirar", { pair<string, int>("espada", 11),
					 pair<string, int>("pocion", 12),
					 pair<string, int>("escudo", 13),
					 pair<string, int>("llave", 14) } },
		{ ("informacion", "revelar"), { pair<string, int>("habitacion", 15) } },
		{ "utilizar", { pair<string, int>("pocion", 16) } },
		{ "craftear", { pair<string, int>("pocion", 17) } },
		{ ("save", "guardar"), {pair<string, int>("partida", 18) } },
		{ ("load", "cargar"), {pair<string, int>("partida", 19) } }
};

template<class T, class S>
int defenceRest(T enemyState, S playerInfo){
	return enemyState - playerInfo;
}

void commandDictionary(string _readOption);
void recetary();
void bestiary();

int main()
{
	//Construyendo las habitaciones en un contenedor

	 // Variables necesaras para el juego
	string readOption;
	bool runGame = true;

	//Inicializando las varables necesarias
	player.setActualRoom(0);
	player.setLife(100);
	player.setPower(5);
	player.setDefence(2);
	player.roomInformation(rooms);

	//Preparando el guardado del juego
	//char buf[128];
	ofstream save("saved_data.txt");
	save << "Begin the savefile" << endl;
	save.close();

	//Inicializar el juego
	while (runGame) {
		/*for (Enemy* enemy : rooms.at(player.getActualRoom()).enemies) {
			if (enemy->alive == true) {
				combatSistem(rooms.at(player.getActualRoom()).enemies, player);
			}
		}*/
		player.roomInformation(rooms);
		getline(cin, readOption);
		transform(readOption.begin(), readOption.end(), readOption.begin(), [](unsigned char c) { return std::tolower(c); });
		commandDictionary(readOption);
	}
}

void commandDictionary(string _readOption) {
	string searchOption = _readOption;
	string delimiter = " ";
	string token;
	size_t pos = 0;

	bool optionFound = true;
	int numOption;

	/*map<string, vector<string>>::iterator firstIt;*/
	//Iteradores necesarios
	map<string, map<string, int>>::iterator firstIt;

	vector<string> wordsInText;
	vector<string>::iterator optionIt1;
	vector<string>::iterator optionIt2;
	vector<string>::iterator optionIt3;

	cout << "Command excecution...\n";
	cout << "Please wait\n";

	//Separador de palabras
	try {
		while (pos != string::npos) {
			pos = searchOption.find(delimiter);
			token = searchOption.substr(0, pos);
			wordsInText.push_back(token);

			bool has_only_digits = true;
			for (size_t i = 0; i < token.length(); i++) {
				if (!isdigit(token[i])) {
					has_only_digits = false;
					break;
				}
			}

			if (has_only_digits) {
				numOption = stoi(token);
			}

			searchOption.erase(0, pos + delimiter.length());
		}
	} catch (exception e) {
		cout << "Tienes que ingresar tus acciones\n";
		cin >> searchOption;
		commandDictionary(searchOption);
	}

	//Lector de palabras
	for (firstIt = dictionary.begin(); firstIt != dictionary.end(); firstIt++) {
		for (optionIt1 = wordsInText.begin(); optionIt1 != wordsInText.end(); optionIt1++) {
			if (*optionIt1 == firstIt->first) {
				cout << "Word: " << firstIt->first << "\n";
				for (map<string, int>::iterator secondIt = firstIt->second.begin(); secondIt != firstIt->second.end(); secondIt++) {
					for (optionIt2 = wordsInText.begin(); optionIt2 != wordsInText.end(); optionIt2++) {
						if (*optionIt2 == secondIt->first) {
							cout << "Word: " << secondIt->first << "\n";

							switch (secondIt->second) {
							case 1:
								player.openDoor(numOption, rooms);
								cout << "logrado";
								break;
							case 2:
								player.pickupSword(numOption, rooms);
								break;
							case 3:
								player.pickupPotion(numOption, rooms);
								break;
							case 4: 
								player.pickupShield(numOption, rooms);
								break;
							case 5:
								player.pickupKey(numOption, rooms);
								break;
							case 6:
								player.attackEnemy(numOption, rooms);
								break;
							case 7:
								player.changeRoom(numOption, rooms);
								break;
							case 8:
								player.inventory();
								break;
							case 9:
								recetary();
								break;
							case 10:
								bestiary();
								break;
							case 11:
								//player.dropSword(numOption, rooms.at(player.getActualRoom()).items);
								player.dropSword(numOption, rooms);
								break;
							case 12:
								player.dropPotion(numOption, rooms);
								break;
							case 13:
								player.dropShield(numOption, rooms);
								break;
							case 14:
								player.dropKey(numOption, rooms);
								break;
							case 15:
								player.roomInformation(rooms);
								break;
							case 16:
								player.usePotion(numOption);
								break;
							case 17:
								player.crafting();
								break;
							case 18:
								player.saveGame(player);
								break;
							case 19:
								player.loadGame(player);
								break;
							default:
								break;
							}
						}
					}
				}
			}
		}
	}

	if (optionFound == false) {
		cout << "Rewrite command\n";
	}
}

void recetary() {
	cout << "Recetario\n";
	cout << "Para craftear una pocion necesitas 5 huesos o carne de algun enemigo y una cabeza, juntalo con una botella y disfruta de tu pocion de curacion\n";
	cout << "'Solamente funciona con elementos magicos'\n";
}

void bestiary() {
	cout << "Bestiario\n";
	for (NormalEnemy* enemy : normalEnemyList) {
		cout << "Enemigo: " << enemy->name << "\n";
		cout << "Life: " << enemy->life << "\n";
		cout << "Power: " << enemy->power << "\n";
		cout << "Defence: " << enemy->defence << "\n";
	}

	for (Minion* minion : minionEnemyList) {
		cout << "Enemigo: " << minion->name << "\n";
		cout << "Life: " << minion->life << "\n";
		cout << "Power: " << minion->power << "\n";
		cout << "Defence: " << minion->defence << "\n";
	}

	for (Boss* boss : bossEnemylist) {
		cout << "Enemigo: " << boss->name << "\n";
		cout << "Life: " << boss->life << "\n";
		cout << "Power: " << boss->power << "\n";
		cout << "Defence: " << boss->defence << "\n";
	}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

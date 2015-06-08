//-------------------------------------------------------------------------------------
// File name...................: main.h
// Purpose.....................: 
// Programmer..................: Andr� Rubira
// Date........................: 2015-06-05
// Version.....................:
// Changed.....................: 
//--------------------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

struct Highscore
{
	string namn;
	unsigned int po�ng;
};

struct Armour {
	char *namn;
	unsigned int skydd;
};

void addNamn(vector<Highscore> *highscore);
void displayLista(vector<Highscore> *highscore);
void bubelSortHighscore(vector<Highscore> *highscore);

Armour* createArmour();
void destroyArmour(Armour *armour);
int ramdomFunc(int max);

/*
Steg A)
Skapa en struct Weapon f�r att h�lla information om ett vapen. Vapnet ska ha ett namn,
och ett antal attackpo�ng (hur mycket skada vapnet g�r). Attackpo�ngen har tv� delar,
en min-v�rde (som �r den minsta skada vapnet kan g�ra per attack), och ett max-v�rde
(som �r den mesta skada vapnet kan g�ra per attack). Str�ngen som h�ller namnet ska vara
en char-pekare som allokeras dynamiskt.*/

struct MaxMin {
	unsigned int min;
	unsigned int max;
};
struct Weapon
{
	char *namn;
	MaxMin attackpoang;
};

/*
Steg B)
Skriv en funktion som skapar ett vapen. Funktionen ska ha f�ljande form:
Weapon* createWeapon(); */
Weapon* createWeapon();
void showWeaponInfo(Weapon *w);
void destroyWeapon(Weapon *w);
void showWeapons(vector<Weapon> *weapons);

/*
Steg G) Skapa en struct Player som inneh�ller information om en spelare. Spelaren ska ha ett namn, en typ 
(t.ex. Paladin, Battlemage, Priest, Farmer, etc.), en h�lsa (som representeras av ett tal), ett vapen och 
en rustning. Namnet och typen ska kunna allokeras dynamiskt. Vapnet och rustningen ska representeras av 
pekare till structar av typen Weapon och Armour.
*/

struct Player
{
	char * name;
	char * type;
	int health;
	Weapon * weapon;
	Armour * armour;
};
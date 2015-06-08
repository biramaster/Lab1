//-------------------------------------------------------------------------------------
// File name...................: main.h
// Purpose.....................: 
// Programmer..................: André Rubira
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
	unsigned int poäng;
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
Skapa en struct Weapon för att hålla information om ett vapen. Vapnet ska ha ett namn,
och ett antal attackpoäng (hur mycket skada vapnet gör). Attackpoängen har två delar,
en min-värde (som är den minsta skada vapnet kan göra per attack), och ett max-värde
(som är den mesta skada vapnet kan göra per attack). Strängen som håller namnet ska vara
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
Skriv en funktion som skapar ett vapen. Funktionen ska ha följande form:
Weapon* createWeapon(); */
Weapon* createWeapon();
void showWeaponInfo(Weapon *w);
void destroyWeapon(Weapon *w);
void showWeapons(vector<Weapon> *weapons);

/*
Steg G) Skapa en struct Player som innehåller information om en spelare. Spelaren ska ha ett namn, en typ 
(t.ex. Paladin, Battlemage, Priest, Farmer, etc.), en hälsa (som representeras av ett tal), ett vapen och 
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
#pragma once
//-------------------------------------------------------------------------------------
// File name...................: Player.h
// Purpose.....................: Definitions
// Programmer..................: André Rubira
// Date........................: 2015-06-05
// Version.....................:
// Changed.....................: 
//--------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include "Armour.h"
#include "Weapon.h"


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

Player* createPlayer(char *name, char *type, Weapon *w, Armour *a);
void destroyPlayer(Player *player);
void showPlayerInfo(Player *p);
void equipPlayerWeapon(Player *p, Weapon *w);
void equipPlayerArmour(Player *p, Armour *a);


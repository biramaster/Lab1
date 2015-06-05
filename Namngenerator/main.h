#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

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
	MaxMin attackpo�ng;
};
struct Highscore
{
	string namn;
	unsigned int po�ng;
};

void addNamn(vector<Highscore> *highscore);
void displayLista(vector<Highscore> *highscore);
void bubelSortHighscore(vector<Highscore> *highscore);
int ramdomFunc();
/*
Steg B) 
Skriv en funktion som skapar ett vapen. Funktionen ska ha f�ljande form: 
Weapon* createWeapon(); */
Weapon* createWeapon();
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
	MaxMin attackpoäng;
};
struct Highscore
{
	string namn;
	unsigned int poäng;
};

void addNamn(vector<Highscore> *highscore);
void displayLista(vector<Highscore> *highscore);
void bubelSortHighscore(vector<Highscore> *highscore);
int ramdomFunc();
/*
Steg B) 
Skriv en funktion som skapar ett vapen. Funktionen ska ha följande form: 
Weapon* createWeapon(); */
Weapon* createWeapon();
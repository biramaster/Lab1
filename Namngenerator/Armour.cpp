#include "Armour.h"

using namespace std;

Armour* createArmour()
{
	string armourType[] = { "Bronze armour", "Iron armour", "Steel armour", "Elite black armour", "Rune armour", "Dragonstone armour" };
	/*
	Steg F) Skapa en struct Armour f�r att h�lla reda p� information om en rustning. Rustningen ska ha ett namn, och
	en armour-class (som �r ett tal som anger hur mycket skydd rustningen ger, d.v.s hur m�nga attack-po�ng fr�n vapnet
	som absorberas av rustningen). Slumpa ut detta tal. Intervall kan du avg�ra sj�lv. Structen ska skapas p� samma s�tt
	som structen Weapon skapades i f�reg�ende uppgift. G�r sedan p� samma s�tt som i f�reg�ende uppgift funktioner f�r
	rustningen:
	*/
	Armour *armour = new Armour;
	armour->skydd = ramdomFunc(0, 200);
	string s1 = armourType[ramdomFunc(0, 5)];
	armour->namn = new char[s1.length() + 1];
	strcpy(armour->namn, s1.c_str());
	return armour;
}

void showArmourInfo(Armour *armour)
{
	cout << "Armour namn :" << armour->namn << endl;
	cout << "Attackpo�ngen max:" << armour->skydd << endl;
	cout << "==================================================" << endl;
}

void destroyArmour(Armour *armour)
{
	delete[] armour->namn;
	delete armour;
}


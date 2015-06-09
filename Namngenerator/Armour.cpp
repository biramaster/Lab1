#include "Armour.h"

using namespace std;

Armour* createArmour()
{
	string armourType[] = { "Bronze armour", "Iron armour", "Steel armour", "Elite black armour", "Rune armour", "Dragonstone armour" };
	/*
	Steg F) Skapa en struct Armour för att hålla reda på information om en rustning. Rustningen ska ha ett namn, och
	en armour-class (som är ett tal som anger hur mycket skydd rustningen ger, d.v.s hur många attack-poäng från vapnet
	som absorberas av rustningen). Slumpa ut detta tal. Intervall kan du avgöra själv. Structen ska skapas på samma sätt
	som structen Weapon skapades i föregående uppgift. Gör sedan på samma sätt som i föregående uppgift funktioner för
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
	cout << "Attackpoängen max:" << armour->skydd << endl;
	cout << "==================================================" << endl;
}

void destroyArmour(Armour *armour)
{
	delete[] armour->namn;
	delete armour;
}


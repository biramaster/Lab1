//-------------------------------------------------------------------------------------
// File name...................: main.cpp
// Purpose.....................: Test all methods
// Programmer..................: André Rubira
// Date........................: 2015-06-05
// Version.....................:
// Changed.....................: 
//--------------------------------------------------------------------------------------

#include "main.h"

using namespace std;

int main()
{
	locale swedish("swedish");
	locale::global(swedish);

	string done = "Y";
	// Set seed for random
	srand(time(0));
	// Create Weapons
	Weapon *w = createWeapon();
	destroyWeapon(w);
	Armour *a = createArmour();
	destroyArmour(a);

	Weapon* weapons[2] = { 0 };
	for (int i = 0; i < 2; i++)
	{
		weapons[i] = createWeapon();
	}

	// Create Armour
	Armour* armours[2] = { 0 };
	for (int i = 0; i < 2; i++)
	{
		armours[i] = createArmour();
	}

	// Create Players
	Player* player1 = createPlayer("Rapunzel", "Battlemage", weapons[0], armours[0]);
	Player* player2 = createPlayer("Moohaa", "Paladin", weapons[1], armours[1]);

	// Show player stats
	cout << "** FIRST PLAYER **" << endl;
	showPlayerInfo(player1);
	showWeaponInfo(player1->weapon);
	showArmourInfo(player1->armour);

	cout << endl << endl << "** SECOND PLAYER **" << endl;
	showPlayerInfo(player2);
	showWeaponInfo(player2->weapon);
	showArmourInfo(player2->armour);

	// Wait for keypress...
	getline(cin, done);

	// Engage in battle!
	doBattle(player1, player2);

	// Destroy Players
	destroyPlayer(player1);
	destroyPlayer(player2);

	// Destroy Weapons
	for (int i = 0; i < 2; i++)
	{
		destroyWeapon(weapons[i]);
	}

	// Destroy Armours
	for (int i = 0; i < 2; i++)
	{
		destroyArmour(armours[i]);
	}
	cout << "Done!YES!";
	cin >> done;
	return 0;
}

/*
vector<Highscore> higscore;
vector<Weapon> weapons;
vector<Armour> armours;

string done = "Y";
Weapon *weapon;
Armour *armour;

while (done[0] != 'N') {

// Highscore
addNamn(&higscore);

// Weapon creation
weapon = createWeapon();
weapons.push_back(*weapon);
armour = createArmour();

cout << "\nVill du mata in ett nytt namn (Y/N)? ";
getline(cin, done);
}

bubelSortHighscore(&higscore);
displayLista(&higscore);
showWeapons(&weapons);
Weapon *w = createWeapon();
showWeaponInfo(w);
destroyWeapon(w);
showWeapons(&weapons);*/
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
	showWeapons(&weapons);
	cout << "Done!YES!";
	cin >> done;
	return 0;
}

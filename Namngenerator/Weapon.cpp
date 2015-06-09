#include "Weapon.h"

using namespace std;

void showWeaponInfo(Weapon *w)
{
	/*
	Steg C) Skriv en funktion som skriver ut information om ett vapen. Funktionen ska skriva ut vapnets namn,
	och hur mycket skada vapnet gör (min och max). Funktionen ska ha följande form: void showWeaponInfo( Weapon *w );
	Den tar alltså en struct av typen Weapon, och presenterar informationen på något snyggt sätt.
	*/
	cout << "Vapensnamn :" << w->namn << endl;
	cout << "Attackpoängen max:" << w->attackpoang.max << endl;
	cout << "Attackpoängen min:" << w->attackpoang.min << endl;
	cout << "==================================================" << endl;

}

void destroyWeapon(Weapon *weapon)
{
	/*
	Steg D) Skriv en funktion som förstör (avallokerar) ett vapen. Funktionen ska ha följande form:
	void destroyWeapon( Weapon *w ); Funktionen ska avallokera allt minne som upptas av structen, d.v.s både namnet och
	structen själv.
	*/
	delete[] weapon->namn;
	delete weapon;
}

void showWeapons(vector<Weapon> *weapons) {

	for (unsigned int i = 0; i < (*weapons).size(); i++)
	{
		showWeaponInfo(&(*weapons)[i]);
	}
}

Weapon* createWeapon() {
	string adjectiv[4] = { "Divine ", "Ultimate ", "Dodgy ", "Spiked " };
	string vapentyp[3] = { "Blade ", "Club ", "Axe " };
	string subtitle[3] = { "of Doom", "of the Wind", "of the Phoenix" };

	/*
	Steg B)
	Börja med att fylla i värdena för attackpoängen.
	Dessa värden ska slumpas ut, intervall får du välja själv. Vapnets namn ska skapas på ett
	speciellt sätt. Namnet ska bestå av tre delar: 1. Ett adjektiv, t.ex. "Divine ","Ultimate ",
	"Dodgy " eller "Spiked " (hitta på själv!) 2. En vapentyp, t.ex. "Blade ","Club " eller "Axe "
	(hitta på själv!) 3. En 'subtitel', t.ex. "of Doom", "of the Wind" eller "of the Phoenix"
	(hitta på själv!) Namnet bildas sedan genom att man tar en slumpad sträng från första listan,
	en slumpad sträng från andra listan, och till sist en slumpad sträng från tredje listan. Om man
	t.ex. tar den första strängen från varje lista så får man "Divine Blade of Doom". Strängen som
	ska hålla vapnets namn ska vara en char-pekare allokeras med operatorn 'new', så att den bara tar
	upp precis så mycket minne som behövs.

	Funktionen ska alltså dynamiskt skapa (med new) en struct av typen Weapon, fylla den med
	information, och returnera pekaren till structen.
	*/
	Weapon *newWeapon = new Weapon;

	/*
	Namnet ska bestå av tre delar:
	1. Ett adjektiv, t.ex. "Divine ","Ultimate ","Dodgy " eller "Spiked " (hitta på själv!)
	2. En vapentyp, t.ex. "Blade ","Club " eller "Axe " (hitta på själv!)
	3. En 'subtitel', t.ex. "of Doom", "of the Wind" eller "of the Phoenix"
	*/

	string s1 = adjectiv[ramdomFunc(0, 3)];
	s1 += vapentyp[ramdomFunc(0, 2)];
	s1 += subtitle[ramdomFunc(0, 2)];

	newWeapon->namn = new char[s1.length() + 1];
	strcpy(newWeapon->namn, s1.c_str());

	//http://www.cplusplus.com/reference/string/string/c_str/

	newWeapon->attackpoang.max = ramdomFunc(20, 200);
	newWeapon->attackpoang.min = ramdomFunc(0, 20);

	return newWeapon;
}
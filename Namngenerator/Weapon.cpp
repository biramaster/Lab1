#include "Weapon.h"

using namespace std;

void showWeaponInfo(Weapon *w)
{
	/*
	Steg C) Skriv en funktion som skriver ut information om ett vapen. Funktionen ska skriva ut vapnets namn,
	och hur mycket skada vapnet g�r (min och max). Funktionen ska ha f�ljande form: void showWeaponInfo( Weapon *w );
	Den tar allts� en struct av typen Weapon, och presenterar informationen p� n�got snyggt s�tt.
	*/
	cout << "Vapensnamn :" << w->namn << endl;
	cout << "Attackpo�ngen max:" << w->attackpoang.max << endl;
	cout << "Attackpo�ngen min:" << w->attackpoang.min << endl;
	cout << "==================================================" << endl;

}

void destroyWeapon(Weapon *weapon)
{
	/*
	Steg D) Skriv en funktion som f�rst�r (avallokerar) ett vapen. Funktionen ska ha f�ljande form:
	void destroyWeapon( Weapon *w ); Funktionen ska avallokera allt minne som upptas av structen, d.v.s b�de namnet och
	structen sj�lv.
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
	B�rja med att fylla i v�rdena f�r attackpo�ngen.
	Dessa v�rden ska slumpas ut, intervall f�r du v�lja sj�lv. Vapnets namn ska skapas p� ett
	speciellt s�tt. Namnet ska best� av tre delar: 1. Ett adjektiv, t.ex. "Divine ","Ultimate ",
	"Dodgy " eller "Spiked " (hitta p� sj�lv!) 2. En vapentyp, t.ex. "Blade ","Club " eller "Axe "
	(hitta p� sj�lv!) 3. En 'subtitel', t.ex. "of Doom", "of the Wind" eller "of the Phoenix"
	(hitta p� sj�lv!) Namnet bildas sedan genom att man tar en slumpad str�ng fr�n f�rsta listan,
	en slumpad str�ng fr�n andra listan, och till sist en slumpad str�ng fr�n tredje listan. Om man
	t.ex. tar den f�rsta str�ngen fr�n varje lista s� f�r man "Divine Blade of Doom". Str�ngen som
	ska h�lla vapnets namn ska vara en char-pekare allokeras med operatorn 'new', s� att den bara tar
	upp precis s� mycket minne som beh�vs.

	Funktionen ska allts� dynamiskt skapa (med new) en struct av typen Weapon, fylla den med
	information, och returnera pekaren till structen.
	*/
	Weapon *newWeapon = new Weapon;

	/*
	Namnet ska best� av tre delar:
	1. Ett adjektiv, t.ex. "Divine ","Ultimate ","Dodgy " eller "Spiked " (hitta p� sj�lv!)
	2. En vapentyp, t.ex. "Blade ","Club " eller "Axe " (hitta p� sj�lv!)
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
//-------------------------------------------------------------------------------------
// File name...................: main.cpp
// Purpose.....................: Test the all methods
// Programmer..................: Andr� Rubira
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

	string s1 = adjectiv[ramdomFunc(3)];
	s1 += vapentyp[ramdomFunc(2)];
	s1 += subtitle[ramdomFunc(2)];

	newWeapon->namn = new char[s1.length() + 1];
	strcpy(newWeapon->namn, s1.c_str());

	//http://www.cplusplus.com/reference/string/string/c_str/

	newWeapon->attackpoang.max = ramdomFunc(200);
	newWeapon->attackpoang.min = ramdomFunc(20);

	return newWeapon;
}



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
	armour->skydd = ramdomFunc(200);
	string s1 = armourType[ramdomFunc(5)];
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

int ramdomFunc(int max) {
	srand(static_cast<unsigned int>(time(0)));  // seed random number generator based on current time

	int randomNumber = rand(); // generate random number

	int die = (randomNumber % max); // get a number between 0 and max
	return die;
}

void bubelSortHighscore(vector<Highscore> *highscore)
{
	for (unsigned int m = (*highscore).size() - 1; m > 0; m--)
	{
		for (unsigned int n = 0; n < m; n++)
		{
			if ((*highscore)[n].po�ng < (*highscore)[n + 1].po�ng)
			{
				Highscore temp = (*highscore)[n];
				(*highscore)[n] = (*highscore)[n + 1];
				(*highscore)[n + 1] = temp;
			}
		}
	}
}

void addNamn(vector<Highscore> *highscore) {
	Highscore *myscore = new Highscore;
	string namn;
	unsigned int po�ng;
	cout << "Skriv in ditt namn?" << endl;
	getline(cin, namn);
	cout << "Skriv in po�ng?" << endl;
	cin >> po�ng;
	myscore->namn = namn;
	myscore->po�ng = po�ng;
	(*highscore).push_back(*myscore);
	cin.ignore(INT_MAX, '\n');
	cin.clear();
}

void displayLista(vector<Highscore> *highscore) {
	const char separator = ' ';
	const int nameWidth = 18;
	const int numWidth = 8;

	cout << "======= HIGHSCORES =======" << endl;

	cout << left << setw(nameWidth) << setfill(separator) << "Namn"
		<< right << setw(numWidth) << setfill(separator) << "Po�ng" << endl;

	cout << "--------------------------" << endl;

	for (unsigned int i = 0; i < (*highscore).size(); i++)
	{
		cout << left << setw(nameWidth) << setfill(separator) << (*highscore)[i].namn
			<< right << setw(numWidth) << setfill(separator) << (*highscore)[i].po�ng << endl;
	}
}

Player* createPlayer(char *name, char *type, Weapon *w, Armour *a)
{
	/*
	Steg H) Skriv en funktion som skapar en spelare. Funktionen ska ha f�ljande form:
	Player* createPlayer( char *name, char *type, Weapon *w, Armour *a ); Funktionen ska allts�
	skapa en struct av typen Player (med new), fylla den med information, och returnera den.
	Vapnet och rustningen skapas i main() och skickas till funktionen som parametrar. Namnet och
	typen ska kopieras till nya str�ngar inuti structen Player.
	*/

	Player *player = new Player;
	player->health = ramdomFunc(200);
	
	player->type = new char[strlen(type) + 1];
	strcpy(player->type, type);

	player->name = new char[strlen(name) + 1];
	strcpy(player->name, name);

	player->weapon = w;
	player->armour = a;

	return player;
}

void destroyWeapon(Player *player)
{
	/*
	Steg I) Skriv en funktion som f�rst�r (avallokerar allt minne som upptas av) en spelare.
	Funktionen ska ha f�ljande form: void destroyPlayer( Player *p ); Funktionen ska dock INTE
	avallokera varken varken vapnet eller rustningen.
	*/
	delete[] player->name;
	delete[] player->type; 
	destroyWeapon(player->weapon);
	destroyArmour(player->armour);
}
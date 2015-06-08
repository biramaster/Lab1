//-------------------------------------------------------------------------------------
// File name...................: main.cpp
// Purpose.....................: Test the all methods
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
	Steg F) Skapa en struct Armour för att hålla reda på information om en rustning. Rustningen ska ha ett namn, och
	en armour-class (som är ett tal som anger hur mycket skydd rustningen ger, d.v.s hur många attack-poäng från vapnet
	som absorberas av rustningen). Slumpa ut detta tal. Intervall kan du avgöra själv. Structen ska skapas på samma sätt
	som structen Weapon skapades i föregående uppgift. Gör sedan på samma sätt som i föregående uppgift funktioner för
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
	cout << "Attackpoängen max:" << armour->skydd << endl;
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
			if ((*highscore)[n].poäng < (*highscore)[n + 1].poäng)
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
	unsigned int poäng;
	cout << "Skriv in ditt namn?" << endl;
	getline(cin, namn);
	cout << "Skriv in poäng?" << endl;
	cin >> poäng;
	myscore->namn = namn;
	myscore->poäng = poäng;
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
		<< right << setw(numWidth) << setfill(separator) << "Poäng" << endl;

	cout << "--------------------------" << endl;

	for (unsigned int i = 0; i < (*highscore).size(); i++)
	{
		cout << left << setw(nameWidth) << setfill(separator) << (*highscore)[i].namn
			<< right << setw(numWidth) << setfill(separator) << (*highscore)[i].poäng << endl;
	}
}

Player* createPlayer(char *name, char *type, Weapon *w, Armour *a)
{
	/*
	Steg H) Skriv en funktion som skapar en spelare. Funktionen ska ha följande form:
	Player* createPlayer( char *name, char *type, Weapon *w, Armour *a ); Funktionen ska alltså
	skapa en struct av typen Player (med new), fylla den med information, och returnera den.
	Vapnet och rustningen skapas i main() och skickas till funktionen som parametrar. Namnet och
	typen ska kopieras till nya strängar inuti structen Player.
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
	Steg I) Skriv en funktion som förstör (avallokerar allt minne som upptas av) en spelare.
	Funktionen ska ha följande form: void destroyPlayer( Player *p ); Funktionen ska dock INTE
	avallokera varken varken vapnet eller rustningen.
	*/
	delete[] player->name;
	delete[] player->type; 
	destroyWeapon(player->weapon);
	destroyArmour(player->armour);
}
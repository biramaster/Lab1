//-------------------------------------------------------------------------------------
// File name...................: main.cpp
// Purpose.....................: 
// Programmer..................: André Rubira
// Date........................: 2015-06-05
// Version.....................:
// Changed.....................: 
//--------------------------------------------------------------------------------------


#include "main.h"

int main()
{
	locale swedish("swedish");
	locale::global(swedish);

	vector<Highscore> higscore;
	vector<Weapon> weapons;

	string done = "Y";
	Weapon *weapon;
	while (done[0] != 'N') {

		// Highscore
		addNamn(&higscore);

		// Weapon creation
		weapon = createWeapon();

		weapons.push_back(*weapon);
		
		cout << "\nVill du mata in ett nytt namn (Y/N)? ";
		getline(cin, done);
	}
	bubelSortHighscore(&higscore);
	displayLista(&higscore);
	displayWeapons(&weapons);
	cout << "Done!YES!";
	return 0;
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
	Highscore myscore;
	string namn;
	unsigned int poäng;
	cout << "Skriv in ditt namn?" << endl;
	getline(cin, namn);
	cout << "Skriv in poäng?" << endl;
	cin >> poäng;
	myscore.namn = namn;
	myscore.poäng = poäng;
	(*highscore).push_back(myscore);
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
int ramdomFunc(int max) {
	srand(static_cast<unsigned int>(time(0)));  // seed random number generator based on current time

	int randomNumber = rand(); // generate random number

	int die = (randomNumber % max); // get a number between 0 and max
	return die;
}
/*

*/
void displayWeapons(vector<Weapon> *weapons) {
	const char separator = ' ';
	const int nameWidth = 30;
	const int numWidth = 8;

	cout << "======= WEAPONS =======" << endl;

	cout << left << setw(nameWidth) << setfill(separator) << "Namn"
		<< right << setw(numWidth) << setfill(separator) << "Attackpoäng" << endl;

	cout << "--------------------------" << endl;

	for (unsigned int i = 0; i < (*weapons).size(); i++)
	{
		cout << left << setw(nameWidth) << setfill(separator) << (*weapons)[i].namn
			<< right << setw(numWidth) << setfill(separator) << (*weapons)[i].attackpoang.max << endl;
	}
}

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
upp precis så mycket minne som behövs.*/

Weapon* createWeapon() {
	/*
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

	newWeapon->namn = new char(s1.length() + 1);
	strcpy(newWeapon->namn, s1.c_str());

	//http://www.cplusplus.com/reference/string/string/c_str/

	newWeapon->attackpoang.max = ramdomFunc(200);
	newWeapon->attackpoang.min = ramdomFunc(20);

	return newWeapon;

}
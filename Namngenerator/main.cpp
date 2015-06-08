//-------------------------------------------------------------------------------------
// File name...................: main.cpp
// Purpose.....................: 
// Programmer..................: Andr� Rubira
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
	Highscore myscore;
	string namn;
	unsigned int po�ng;
	cout << "Skriv in ditt namn?" << endl;
	getline(cin, namn);
	cout << "Skriv in po�ng?" << endl;
	cin >> po�ng;
	myscore.namn = namn;
	myscore.po�ng = po�ng;
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
		<< right << setw(numWidth) << setfill(separator) << "Po�ng" << endl;

	cout << "--------------------------" << endl;

	for (unsigned int i = 0; i < (*highscore).size(); i++)
	{
		cout << left << setw(nameWidth) << setfill(separator) << (*highscore)[i].namn
			<< right << setw(numWidth) << setfill(separator) << (*highscore)[i].po�ng << endl;
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
		<< right << setw(numWidth) << setfill(separator) << "Attackpo�ng" << endl;

	cout << "--------------------------" << endl;

	for (unsigned int i = 0; i < (*weapons).size(); i++)
	{
		cout << left << setw(nameWidth) << setfill(separator) << (*weapons)[i].namn
			<< right << setw(numWidth) << setfill(separator) << (*weapons)[i].attackpoang.max << endl;
	}
}

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
upp precis s� mycket minne som beh�vs.*/

Weapon* createWeapon() {
	/*
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

	newWeapon->namn = new char(s1.length() + 1);
	strcpy(newWeapon->namn, s1.c_str());

	//http://www.cplusplus.com/reference/string/string/c_str/

	newWeapon->attackpoang.max = ramdomFunc(200);
	newWeapon->attackpoang.min = ramdomFunc(20);

	return newWeapon;

}
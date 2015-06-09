//-------------------------------------------------------------------------------------
// File name...................: Highscore.cpp
// Purpose.....................: 
// Programmer..................: André Rubira
// Date........................: 2015-06-05
// Version.....................:
// Changed.....................: 
//--------------------------------------------------------------------------------------

#include "Highscore.h"

using namespace std;

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
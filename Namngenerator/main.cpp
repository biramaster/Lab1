#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

struct MaxMin {
	unsigned int min;
	unsigned int max;
};
struct Weapon
{
	char *namn;
	MaxMin attackpoäng;
};
struct Highscore
{
	string namn;
	unsigned int poäng;
};

void addNamn(vector<Highscore> *highscore);
void displayLista(vector<Highscore> *highscore);
void bubelSortHighscore(vector<Highscore> *highscore);
void ramdomFunc();

int main()
{
	locale swedish("swedish");
	locale::global(swedish);

	vector<Highscore> myLista;

	string done = "Y";
	while (done[0] != 'N') {
		addNamn(&myLista);
		bubelSortHighscore(&myLista);
		displayLista(&myLista);

		cout << "\nVill du mata in ett nytt namn (Y/N)? ";
		getline(cin, done);
	}
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

	for (unsigned int i = 0; i<(*highscore).size(); i++)
	{
		cout << left << setw(nameWidth) << setfill(separator) << (*highscore)[i].namn
			<< right << setw(numWidth) << setfill(separator) << (*highscore)[i].poäng << endl;
	}
}
void ramdomFunc() {
	srand(static_cast<unsigned int>(time(0)));  // seed random number generator based on current time

	int randomNumber = rand(); // generate random number

	int die = (randomNumber % 6) + 1; // get a number between 1 and 6
	cout << "You rolled a " << die << endl;
}
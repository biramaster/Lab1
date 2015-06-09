//-------------------------------------------------------------------------------------
// File name...................: Player.cpp
// Purpose.....................: Player functions
// Programmer..................: André Rubira
// Date........................: 2015-06-05
// Version.....................:
// Changed.....................: 
//--------------------------------------------------------------------------------------


#include "Player.h"

using namespace std;


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
	player->health = ramdomFunc(0, 200);

	player->type = new char[strlen(type) + 1];
	strcpy(player->type, type);

	player->name = new char[strlen(name) + 1];
	strcpy(player->name, name);

	player->weapon = w;
	player->armour = a;

	return player;
}

void destroyPlayer(Player *player)
{
	/*
	Steg I) Skriv en funktion som förstör (avallokerar allt minne som upptas av) en spelare.
	Funktionen ska ha följande form: void destroyPlayer( Player *p ); Funktionen ska dock INTE
	avallokera varken varken vapnet eller rustningen.
	*/
	delete[] player->name;
	delete[] player->type;
	delete player;
}

void showPlayerInfo(Player *p)
{
	/*
	Steg J) Skriv en funktion som visar information om en spelare. Den ska visa spelarens namn,
	och hur mycket hälsa han/hon har kvar. Den ska ha följande form: void showPlayerInfo( Player *p );
	*/

	cout << "Player name: " << p->name << endl;
	cout << "Health: " << p->health << endl;
}

void equipPlayerArmour(Player *p, Armour *a)
{
	/*
	Steg K) Skriv två funktioner som utrustar spelaren, dels med ett vapen och dels med en rustning.
	Funktionerna ska ha följande form: void equipPlayerWeapon( Player *p, Weapon *w ); // utrustar
	spelaren 'p' med ett vapen 'w' void equipPlayerArmour( Player *p, Armour *a ); // utrustar spelaren 'p' med en rustning 'a'
	*/
	p->armour = a;

}

void equipPlayerWeapon(Player *p, Weapon *w)
{
	p->weapon = w;
}


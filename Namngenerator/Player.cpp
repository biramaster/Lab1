//-------------------------------------------------------------------------------------
// File name...................: Player.cpp
// Purpose.....................: Player functions
// Programmer..................: Andr� Rubira
// Date........................: 2015-06-05
// Version.....................:
// Changed.....................: 
//--------------------------------------------------------------------------------------


#include "Player.h"

using namespace std;


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
	player->health = ramdomFunc(0, 200);

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

void showPlayerInfo(Player *p)
{
	/*
	Steg J) Skriv en funktion som visar information om en spelare. Den ska visa spelarens namn,
	och hur mycket h�lsa han/hon har kvar. Den ska ha f�ljande form: void showPlayerInfo( Player *p );
	*/

	cout << "Player name: " << p->name << endl;
	cout << "Health: " << p->health << endl;
}

void equipPlayerArmour(Player *p, Armour *a)
{
	/*
	Steg K) Skriv tv� funktioner som utrustar spelaren, dels med ett vapen och dels med en rustning.
	Funktionerna ska ha f�ljande form: void equipPlayerWeapon( Player *p, Weapon *w ); // utrustar
	spelaren 'p' med ett vapen 'w' void equipPlayerArmour( Player *p, Armour *a ); // utrustar spelaren 'p' med en rustning 'a'
	*/
	p->armour = a;

}

void equipPlayerWeapon(Player *p, Weapon *w)
{
	p->weapon = w;
}

void attack(Player *attacker, Player *victim){

	/*
	Steg M) Skapa en funktion som l�ter en spelare attackera en annan. Funktionen ska ha f�ljande form:
	void attack( Player *attacker, Player *victim );

	Funktionen ska fungera s� h�r:

	F�rst ber�knas hur mycket skada den attackerande spelaren g�r, genom att slumpa ut ett
	v�rde i intervallen min - max (gr�nserna finns i den attackerande spelarens vapen).

	Skadepo�gen minskas med offrets rustningspo�ng (armour class). Om skadepo�ngen �r mindre �n noll,
	s� s�tt den till noll (spelaren g�r ingen skada).

	Skriv ut statistik f�r attacken:

	vad den attackerande spelaren heter

	vad han/hon har f�r typ

	vapnets namn

	hur mycket skada som spelaren ger

	vad offret heter och har f�r typ

	namnet p� offrets rustning


	Ett exempel p� utskrift �r:

	Rapunzel the Battlemage wields the Divine Spoon of Pain against Moohaa the Paladin's Sucky
	Helmet of Gold, and does 13 of damage. Moohaa has 18 hp left.

	Minska offrets h�lsopo�ng med skadepo�ngen fr�n vapnet

	Om offrets h�lsopo�ng �r mindre eller lika med noll, s� d�r offret.
	Skriv ut en text som anger vem som dog i striden, och vem som vann (namnen p� anfallaren och offret)
	*/
}

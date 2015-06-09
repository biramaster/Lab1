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

void attack(Player *attacker, Player *victim){

	/*
	Steg M) Skapa en funktion som låter en spelare attackera en annan. Funktionen ska ha följande form:
	void attack( Player *attacker, Player *victim );

	Funktionen ska fungera så här:

	Först beräknas hur mycket skada den attackerande spelaren gör, genom att slumpa ut ett
	värde i intervallen min - max (gränserna finns i den attackerande spelarens vapen).

	Skadepoägen minskas med offrets rustningspoäng (armour class). Om skadepoängen är mindre än noll,
	så sätt den till noll (spelaren gör ingen skada).

	Skriv ut statistik för attacken:

	vad den attackerande spelaren heter

	vad han/hon har för typ

	vapnets namn

	hur mycket skada som spelaren ger

	vad offret heter och har för typ

	namnet på offrets rustning


	Ett exempel på utskrift är:

	Rapunzel the Battlemage wields the Divine Spoon of Pain against Moohaa the Paladin's Sucky
	Helmet of Gold, and does 13 of damage. Moohaa has 18 hp left.

	Minska offrets hälsopoäng med skadepoängen från vapnet

	Om offrets hälsopoäng är mindre eller lika med noll, så dör offret.
	Skriv ut en text som anger vem som dog i striden, och vem som vann (namnen på anfallaren och offret)
	*/
}

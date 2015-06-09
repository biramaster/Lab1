//-------------------------------------------------------------------------------------
// File name...................: Game.cpp
// Purpose.....................: 
// Programmer..................: André Rubira
// Date........................: 2015-06-05
// Version.....................:
// Changed.....................: 
//--------------------------------------------------------------------------------------

#include "Game.h"

using namespace std;

void attack(Player *attacker, Player *victim){

	/*
	Steg M) Skapa en funktion som låter en spelare attackera en annan. Funktionen ska ha följande form:
	void attack( Player *attacker, Player *victim );

	Funktionen ska fungera så här:

	Först beräknas hur mycket skada den attackerande spelaren gör, genom att slumpa ut ett
	värde i intervallen min - max (gränserna finns i den attackerande spelarens vapen).*/
	int attackstrength = ramdomFunc(attacker->weapon->attackpoang.min, attacker->weapon->attackpoang.max);

	/*Skadepoägen minskas med offrets rustningspoäng (armour class). Om skadepoängen är mindre än noll,
	så sätt den till noll (spelaren gör ingen skada).*/
	int damage = attackstrength - victim->armour->skydd;

	if (damage < 0) damage = 0;

	/*Skriv ut statistik för attacken:

	vad den attackerande spelaren heter, vad han/hon har för typ, vapnets namn, hur mycket skada som spelaren ger
	vad offret heter och har för typ, namnet på offrets rustning,

	Ett exempel på utskrift är:

	Rapunzel the Battlemage wields the Divine Spoon of Pain against Moohaa the Paladin's Sucky
	Helmet of Gold, and does 13 of damage. Moohaa has 18 hp left.
	Minska offrets hälsopoäng med skadepoängen från vapnet*/
	victim->health -= damage;
	cout << attacker->name << " wields " << attacker->weapon->namn << " agains " << endl 
		<< victim->name << "'s " << victim->armour->namn << " and does " << damage << endl 
		<< " of damage. " << victim->name << " has " << victim->health << " hp left." << endl;

	cout << "================================================================================" << endl;
	/*Om offrets hälsopoäng är mindre eller lika med noll, så dör offret.
	Skriv ut en text som anger vem som dog i striden, och vem som vann (namnen på anfallaren och offret)
	*/
	if (victim->health <= 0)
		cout << victim->name << " died. " << attacker->name << " won the battle." << endl;
}

void doBattle(Player *p1, Player *p2)
{
	/*
	Striden ska delas upp i ett antal rundor. För varje runda ska det slumpas ut vem som börjar. 
	Därefter ska den som fick börja, anfalla sin motståndare. Sedan ska motståndaren göra ett motanfall. 
	När båda anfallit varandra är rundan slut. Striden slutar då den ena av spelarna dör, d.v.s. har en 
	hälsopoäng som är mindre än noll. Använd funktionen attack() som skapades i förra uppgiften för att 
	sköta anfallen.
	*/
	Player *attacker, *victim;
	do
	{ 
		attacker = p1;
		victim = p2;
		if(ramdomFunc(0,20)>10)
		{
			attacker = p2;
			victim = p1;
		}

		attack(attacker, victim);

		if (victim->health > 0)
			attack(victim, attacker);

	} while (p1->health > 0 && p2->health > 0);
}
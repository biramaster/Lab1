//-------------------------------------------------------------------------------------
// File name...................: Game.cpp
// Purpose.....................: 
// Programmer..................: Andr� Rubira
// Date........................: 2015-06-05
// Version.....................:
// Changed.....................: 
//--------------------------------------------------------------------------------------

#include "Game.h"

using namespace std;

void attack(Player *attacker, Player *victim){

	/*
	Steg M) Skapa en funktion som l�ter en spelare attackera en annan. Funktionen ska ha f�ljande form:
	void attack( Player *attacker, Player *victim );

	Funktionen ska fungera s� h�r:

	F�rst ber�knas hur mycket skada den attackerande spelaren g�r, genom att slumpa ut ett
	v�rde i intervallen min - max (gr�nserna finns i den attackerande spelarens vapen).*/
	int attackstrength = ramdomFunc(attacker->weapon->attackpoang.min, attacker->weapon->attackpoang.max);

	/*Skadepo�gen minskas med offrets rustningspo�ng (armour class). Om skadepo�ngen �r mindre �n noll,
	s� s�tt den till noll (spelaren g�r ingen skada).*/
	int damage = attackstrength - victim->armour->skydd;

	if (damage < 0) damage = 0;

	/*Skriv ut statistik f�r attacken:

	vad den attackerande spelaren heter, vad han/hon har f�r typ, vapnets namn, hur mycket skada som spelaren ger
	vad offret heter och har f�r typ, namnet p� offrets rustning,

	Ett exempel p� utskrift �r:

	Rapunzel the Battlemage wields the Divine Spoon of Pain against Moohaa the Paladin's Sucky
	Helmet of Gold, and does 13 of damage. Moohaa has 18 hp left.
	Minska offrets h�lsopo�ng med skadepo�ngen fr�n vapnet*/
	victim->health -= damage;
	cout << attacker->name << " wields " << attacker->weapon->namn << " agains " << endl 
		<< victim->name << "'s " << victim->armour->namn << " and does " << damage << endl 
		<< " of damage. " << victim->name << " has " << victim->health << " hp left." << endl;

	cout << "================================================================================" << endl;
	/*Om offrets h�lsopo�ng �r mindre eller lika med noll, s� d�r offret.
	Skriv ut en text som anger vem som dog i striden, och vem som vann (namnen p� anfallaren och offret)
	*/
	if (victim->health <= 0)
		cout << victim->name << " died. " << attacker->name << " won the battle." << endl;
}

void doBattle(Player *p1, Player *p2)
{
	/*
	Striden ska delas upp i ett antal rundor. F�r varje runda ska det slumpas ut vem som b�rjar. 
	D�refter ska den som fick b�rja, anfalla sin motst�ndare. Sedan ska motst�ndaren g�ra ett motanfall. 
	N�r b�da anfallit varandra �r rundan slut. Striden slutar d� den ena av spelarna d�r, d.v.s. har en 
	h�lsopo�ng som �r mindre �n noll. Anv�nd funktionen attack() som skapades i f�rra uppgiften f�r att 
	sk�ta anfallen.
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
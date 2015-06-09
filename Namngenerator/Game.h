#pragma once
//-------------------------------------------------------------------------------------
// File name...................: Game.h
// Purpose.....................: 
// Programmer..................: André Rubira
// Date........................: 2015-06-05
// Version.....................:
// Changed.....................: 
//--------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include "Player.h"

void attack(Player *attacker, Player *victim);
void doBattle(Player *p1, Player *p2);
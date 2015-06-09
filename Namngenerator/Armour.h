#pragma once
//-------------------------------------------------------------------------------------
// File name...................: Armour.h
// Purpose.....................: 
// Programmer..................: Andr� Rubira
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
#include "Tools.h"

struct Armour {
	char *namn;
	unsigned int skydd;
};

Armour* createArmour();
void destroyArmour(Armour *armour);


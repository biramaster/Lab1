#pragma once
//-------------------------------------------------------------------------------------
// File name...................: Highscore.h
// Purpose.....................: Definitions
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

struct Highscore
{
	std::string namn;
	unsigned int poäng;
};

void addNamn(std::vector<Highscore> *highscore);
void displayLista(std::vector<Highscore> *highscore);
void bubelSortHighscore(std::vector<Highscore> *highscore);




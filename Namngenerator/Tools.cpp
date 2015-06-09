#include "Tools.h"

int ramdomFunc(int min, int max) {
	srand(static_cast<unsigned int>(time(0)));  // seed random number generator based on current time

	int randomNumber = rand(); // generate random number

	int die = (randomNumber % max) + min; // get a number between 0 and max
	return die;
}
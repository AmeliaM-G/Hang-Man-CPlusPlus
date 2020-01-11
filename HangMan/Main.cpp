#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h> // for random selection
#include <time.h> // for random slection

using namespace std;

const int maxTries = 3;
int wrongGuesses = 0; //count of wrong guesses cannot exceed 3

string words[] = {
	"pyramid",
	"document",
	"conscience",
	"perceive",
	"feminine",
	"extension",
	"grimace",
	"garbage",
	"mosquito",
	"intervention",
	"disorder" };
// random words with more than 5 letters from a random word generator.
// would like to allow the code to pick random words from the dictionary itself in the future.



int main() {

	// RANDOM WORD SELECTION:
	srand(time(NULL)); // initialises random seed
	int length = sizeof(words) / sizeof(words[0]);
	//cout << "length of array is: " << length << endl;
	int randIndex = rand() % length;
	//cout << "random word is: " << words[randIndex] << endl;

	return 0;
}
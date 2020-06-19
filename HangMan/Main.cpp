#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h> // for random selection
#include <time.h> // for random slection

using namespace std;

int lives = 5;
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

int gamePlay(char guess, string answer, string &visible) {
	int matches = 0;
	for (int i = 0; i < answer.length(); i++) {
		if (guess == visible[i]) {
			return 0;
		}
		else if (guess == answer[i]) {
			matches ++;
		}
	}
	return matches;
}


int main() {

	// RANDOM WORD SELECTION:
	srand(time(NULL)); // initialises random seed
	int length = sizeof(words) / sizeof(words[0]);
	//cout << "length of array is: " << length << endl;
	int randIndex = rand() % length;
	const string word = words[randIndex];
	//cout << "random word is: " << word << endl;

	//BLANK OUT WORD:
	int wordLength = word.size();
	//cout << "word is: " << word << ". Length of word is: " << wordLength << endl;
	string blank(wordLength, '-');
	//cout << "word is: " << word << ". blank is: " << blank << endl;

	//DISPLAY TO USER:
	cout << "Welcome to HangMan!" << endl;
	cout << "You have to guess a randomly generated word of 5 characters or more!" << endl;
	cout << "You have " << lives << " lives." << endl;
	cout << "You will lose lives if you guess wrong or enter the same letter more than once." << endl;
	string start;
	while (start != "start" && start != "START" && start != "Start") {
		cout << "Enter \"START\" to begin." << endl;
		cin >> start;
	}
	cout << "This is your word: " << blank << endl;

	//GAME PLAY:
	char letter; // letter user inputs
	while (lives > 0 && blank != word) {
		cout << "You have " << lives << " lives left." << endl;
		cout << "Please enter your guess:" << endl;
		cin >> letter;
		int ans = gamePlay(letter, word, blank); //function defined above main
		//cout << ans << endl;
		if (ans == 0) {
			cout << letter << " is wrong!" << endl;
			lives--;
		}
		else{
			cout << letter << " is correct! Well done!" << endl;
			for (int i = 0; i < wordLength; i++) {
				if (letter == word[i]) {
					blank[i] = letter;
				}
			}
			cout << "This is your word: " << blank << endl;
		}
	}
	if (blank == word) {
	cout << "Congratulations! You win! Restart to play again." << endl;
	}
	else {
		cout << "You lose! Restart to play again." << endl;
	}

	return 0;
}
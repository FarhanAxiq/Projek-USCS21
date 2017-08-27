/*
*	   WordScrambler.cpp
*	   Written by FarhanAxiq - Ditulis oleh FarhanAxiq
*	   ©2017 All right reserved	 - Hak cipta Terpelihara
*	   August ,2017
*
*	   "Decide which procedures you want;
       use the best algorithms you can find"
*
*/

#include "stdafx.h"
#include <iostream>
#include <string>	  //std::string
#include <fstream>	  //ifstream
#include <stdlib.h>
#include <string.h>	  //c-style string
#include <time.h>	  //srand()



using namespace std;

// Function prototype
void permuteWord(char items[], int len);




int main(int argc, char *argv[])
{

	string theword[6];
	srand(time(NULL)); //initialize rand
	ifstream wordBank(argv[1]);	//wordBank.txt lies here

	wordBank >> argc;		 //use number in wordbank


	if (!wordBank) {
		cerr << "wordBank file could not be found, Program will terminate." << endl;
		exit(1);
	}


	string dummyLine;
	getline(wordBank, dummyLine);

	while (!wordBank.eof()) {
		for (int i = 0; i < argc; i++) {
			wordBank >> theword[i];
		}
	}

	
	char guess[80];

	bool answer = false;
	int turn = 10;

	// Pick a random word from the wordBank
	int target = rand() % argc;
	int targetLen = theword[target].length();

	// initialize more stuff here
	char* word = new char[targetLen + 1];
	strcpy(word, theword[target].c_str());
	permuteWord(word, targetLen);

	//This is where the game take places, 10 guess
	while (!answer && turn > 0) {
		//TODO: ADD COUT HERE
		cout << "\nCurrent word:  " << word << endl;
		cin >> guess;
		answer = (strncmp(guess, theword[target].c_str(), targetLen + 1) == 0);			  //check the answer, compare string
		turn--;
	}

	if (answer) {
		cout << "You win!" << endl;
	}

	else {
		cout << "Too many turns...You lose!" << endl;
	}

	delete[] word;
							 
	wordBank.close(); 
	cin.get();   //pause
	return 0;

}

/*
 ===========================================
		scramble / permute word
 ===========================================
*/
void permuteWord(char items[], int len)
{
	for (int i = len - 1; i > 0; --i) {
		int r = rand() % i;
		int temp = items[i];
		items[i] = items[r];
		items[r] = temp;
	}

}

		


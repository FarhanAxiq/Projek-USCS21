/*
*	   WordScrambler.cpp
*	   Written by FarhanAxiq - Ditulis oleh FarhanAxiq
*	   ©2017 All right reserved	 - Hak cipta Terpelihara
*	   August ,2017
*
*	   "Decide which procedures you want;
*       use the best algorithms you can find"
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
void question(int, string[6]);
void permuteWord(char items[], int len);




int main(int argc, char *argv[])
{

	char confirm;
	cout << R"(
===========================================================
Welcome to Word Scramble
To start Playing, you can Press Y else press N
===========================================================)" << endl;

	cin >> confirm;

	if (confirm == 'Y' || confirm == 'y')
		goto play;

	else if (confirm == 'n' || confirm == 'N') {
		cout << "Alright, goodbye\n";
		exit(0);
	}

	else {
		cout << "Invalid input has been enter, try again" << endl;
		cin >> confirm;
	}



play:
	string theword[6];
	srand(time(NULL)); //initialize rand
	ifstream wordBank(argv[1]);	//wordBank.txt lies here

	wordBank >> argc;		 //use number in wordbank


    //File checking
	if (!wordBank) {
		cerr << "wordBank.txt could not be found, Program will terminate." << endl;
		exit(1);
	}


	string dummyLine;
	getline(wordBank, dummyLine);


	//put the word from textfile into an array of 6
	while (!wordBank.eof()) {
		for (int i = 0; i < argc; i++) {
			wordBank >> theword[i];
		}
	}


	cout << R"(Game Rule
-----------------
1.The word will appear scramble, as the game suggest
2.Try to solve it by putting the correct word.
3.You have 10 guesses, if you reach the maximum guess you lose.
HAVE FUN!)" << endl;

	question(argc, theword);

	wordBank.close();
	cin.get();   //pause
	return 0;

}


/*
===============================================
Game goes here
===============================================
*/
void question(int argc, string theword[6])
{
	char guess[100];
	bool answer = false;
	int turn = 10;
	char confirm;

	// Pick a random word from the wordBank
	int elementContent = rand() % argc;
	int elementLength = theword[elementContent].length();

	// initialize more stuff here
	char* word = new char[elementLength + 1];
	strcpy(word, theword[elementContent].c_str());
	permuteWord(word, elementLength);
	cout << endl;

	//This is where the game take places, 10 guess
	while (!answer && turn > 0) {
		cout << "Enter guess here";
		cout << "\nCurrent word:  " << word << endl;
		cin >> guess;
		answer = (strncmp(guess, theword[elementContent].c_str(), elementLength + 1) == 0);			  //check the answer, compare string
		turn--;
		cout << endl;
	}


	if (answer) {
		cout << "You win!" << endl;
		cout << endl;
	}

	else {
		cout << "Too many turns...You lose!" << endl;
		cout << endl;
	}


	cout << "Wish to play again? If so press Y else press N" << endl;
	cin >> confirm;
	if (confirm == 'Y' || confirm == 'y')
		question(argc, theword);

	else if (confirm == 'n' || confirm == 'N') {
		cout << "Alright, goodbye\n";
		exit(0);
	}

	else {
		cout << "Invalid input has been enter, try again" << endl;
		cin >> confirm;
	}


	delete[] word;
	return;
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

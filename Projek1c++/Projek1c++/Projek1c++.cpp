/*
*	   WordScrambler.cpp
*	   Written by FarhanAxiq - Ditulis oleh FarhanAxiq
*	   ©2017 All right reserved	 - Hak cipta Terpelihara
*	   August ,2017
*
*	   "Decide which procedures you want; use the best algorithms you can find"
*
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>   

using namespace std;




int main(int argc, char *argv[])
{

	string word[6];
	ifstream wordBank("wordBank.txt");

	if (!wordBank) {
		cerr << "wordBank file could not be found, Program will terminate" << endl;
		exit(1);
	}

	


	wordBank >> argc; //Use the numeric value from the text file for array size


	//This is to ignore the first line
	string dummyLine;
	getline(wordBank, dummyLine);


	//How i suppose to put it into argv goddamnit????????
	while (!wordBank.eof()) {
		for (int i = 1; i < argc; i++) {
			getline(wordBank, dummyLine);
			wordBank >> word[i];
		}
		
	}


	cout << word[5];
	wordBank.close(); 

    return 0;
}



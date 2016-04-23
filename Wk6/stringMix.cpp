/**********************************************************************
 * Program: stringMix.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/03/14
 * Modified: 11/03/14
 * Description: This program takes a c-style string as a parameter and 
 * 				passes it to a function. Upon completion of the
 * 				function, a second string will be a random rearrangement 
 * 				of the characters in the first string. The first string
 * 				will remain unchanged. 
 * Output: Random rearrangement of 1st string
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>	 // Strings
#include <vector>	 // Used for random shuffle function
#include <algorithm> // random_shuffle 
#include <limits>	 // limits 
#include <ctime>	 // setting seed using time(NULL)
#include <cctype>	 // isprint function

using namespace std;

// Global Constants and Variables
const int SIZE = 30;
vector <int> numbers;

// Prototype Function(s)
void rand_int(); 
void get_random_str2(const char [], char [], int);
bool go_again();

int main()
{
	bool answer; 				// Holds Go again answer
	char str1[SIZE] = {},		// Variable to hold user's input
		 str2[SIZE] = {};		// Variable to hold randomized str1 
	int count = 0;				// Variable to count actual size of
								// user's input
	
	// Initialize seed
	srand(time(NULL));
	
	cout << "Enter a string upto 30 characters long." << endl;
	cin.getline(str1, SIZE);
	
	// Get actual size of user's input if < SIZE
	for (int a = 0; a < SIZE; a++)
	{
		if (isprint(str1[a]))
		{
			count++;
		}
	}
	
	// Do/while loop to allow user to go again w/o exiting
	do
	{	
		// Set values
		for (int a = 0; a < count; ++a)
		{
			numbers.push_back(a);
		}
		
		// Randomly shuffle numbers
		random_shuffle (numbers.begin(), numbers.end());
		
		// Call to function to randomly shuffle str1 contents
		get_random_str2(str1, str2, count);
		
		cout << "You entered \"" << str1 << "\" as your string." 
			 << endl;
		
		cout << endl << "Here it is in a random order \""; 
		
		for (int a = 0; a < count; a++)
		{
			cout<< str2[a];
		}
		 
		cout << "\"" <<  endl;
		
		// Allow user to go again w/o exiting
		answer = go_again(); 
	}
	while (answer == true);
	
	return 0;
}

/**********************************************************************
 * This function takes to contents of str1 and copies a random
 * rearrangement of it to str2. 
 *********************************************************************/
void get_random_str2(const char str1[], char str2[], int count)
{
	for (int a = 0; a < count; a++)
	{
		str2[a] = str1[numbers[a]];
	}
}

/***********************************************************************
 * Function used to ask user if they would like to go again.
***********************************************************************/
bool go_again()
{
	static int count = 0;	// Used to clear input buffer on 1st go round
	bool answer = false; 	// Sets return to false 
	string user_answer;  	// Used to get user's answer
	
	// If statement clears input buffer on 1st pass through program
	if (count == 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		count++;
	}

	cout << "Would you like to go again? [y/n] ";
	getline (cin, user_answer);
	
	if (user_answer == "y" || user_answer == "Y" || user_answer == "yes"
		|| user_answer == "Yes")
	{
		answer = true;
	}
	
	return answer;
}

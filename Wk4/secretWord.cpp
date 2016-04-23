/**********************************************************************
 * Program: secretWord.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/24/14
 * Modified: 10/24/14
 * Description: This program will emulate the popular game Hangman.
 * Output: Secret Word and whether player 2 guessed it or not  
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>   // needed for srand/rand
#include <fstream>	 // needed to use files
#include <string>    // needed to use strings

using namespace std;

// Prototype Function(s)
void menu();
void get_choices();
int user_selection();
int rand_int(int a); 
bool go_again();

// Global Variables and Constants
const int MAX_SECRET_WORDS = 8; // constant to easily change number of words in word.txt file
string choice[MAX_SECRET_WORDS];   // array to hold all the possible secret word choices
int winner[4] = {}; // Variables to hold random number from rand_int function

int main()
{
	int word_choice = 0; 		// Holds the user's menu choice
	string secret_word = ""; 	// Holds secret word
	bool answer; 				// Holds Go again answer
	
	// do/while loop to allow user to repeat program w/o exiting
	do
	{
		get_choices(); // Populate secret word choices from file
	
		// Do/while loop gets 4 numbers until no two are the same
		do
		{
			// For loop gets 4 numbers and stores them in an array
			for (int a = 0; a < 4; a++)
			{
				winner[a] = rand_int(a);
			}
		
		}
		while ((winner[0] == winner[1]) || (winner[0] == winner[2]) || 
			   (winner[0] == winner[3]) || (winner[1] == winner[2]) || 
			   (winner[1] == winner[3]) || (winner[1] == winner[0]) ||
			   (winner[2] == winner[3]) || (winner[2] == winner[0]) || 
			   (winner[2] == winner[1]) || (winner[3] == winner[0]) || 
			   (winner[3] == winner[1]) || (winner[3] == winner[2]));
	
			
		menu();							// Display menu choices
		word_choice = user_selection(); // Assign word_choice the value 
										// returned by the user_selection
										// funcition
		
		// If/else to assign user choice to secret word								
		if (word_choice == 1)
		{
			secret_word = choice[winner[0]];
		}
		
		else if (word_choice == 2)
		{
			secret_word = choice[winner[1]];
		}
		
		else if (word_choice == 3)
		{
			secret_word = choice[winner[2]];
		}
		
		else if (word_choice == 4)
		{
			secret_word = choice[winner[3]];
		}

		system("clear"); // Clear screen so player 2 doesn't see possible choices
	
		char space_correct[secret_word.length()]; 	// Variable to determine correct guesses
		char space_wrong[5] = {}; 					// Variable to determine incorrect guesses
		char guess = ' '; 							// Variable to hold player 2's guesses
		int num_of_guesses = 0; 					// Initialize # of wrong guesses to 0 
		unsigned found1 = 0, 						// Variable for locating user guess in secret word
				 count_same = 0;					// Variable to count number of correct guesses
		int wrong = 0;								// Variable to count number of wrong guesses
		
		// For loop assigns a '_' to each spot it space correct array
		for (unsigned begin = 0; begin < secret_word.length(); begin++)
		{
			space_correct[begin] = '*';
		}
		
		// Do/while loop to get player 2 guesses until 6 wrong guesses
		do
		{
			cout << "Enter guess number " << num_of_guesses << " of 6: ";
			cin.ignore();
			cin.get(guess); // Store player 2's guess 
		
			found1 = secret_word.find(guess, 0); // Search secret word for guess
			
			// If guess found in secret word, find all occurances and store them to space correct
			if (found1 != 4294967295)
			{
				// Look at each character of secret word
				for (unsigned ans = 0; ans < secret_word.length(); ans++)
				{
					// If guess and character are same, assign guess to array and count
					if (guess == secret_word.at(ans))
					{
						space_correct[ans] = guess;
						count_same++;
					}
				}
			}
			
			// If guess wrong, store it to space wrong and count 
			else
			{
				space_wrong[wrong] = guess;
				num_of_guesses++;
				wrong++;
			}
			
			// Had to add this to get program to work on flip
			if (count_same == secret_word.length())
			{
				cout << "You're correct. The secret word was "
					 << secret_word << " . You only used " 
					 << num_of_guesses << " wrong guess(es) out of 6." 
					 << endl;
				goto end;
			}	
			
			// If space correct (ie guesses) is secret word, you WIN
			if (space_correct == secret_word)
			{
				cout << "You're correct. The secret word was "
					 << secret_word << " . You only used " 
					 << num_of_guesses << " wrong guess(es) out of 6." 
					 << endl;
				goto end;
			}
			
			cout << "Guesses correct: ";
			
			// For loop to display all correct guesses
			for (unsigned right = 0; right < secret_word.length(); right++)
				{
					cout << space_correct[right];
				}
			
			cout << endl;
			cout << "Guesses incorrect: "; 
			
			// For loop to display all wrong guesses
			for (unsigned no = 0; no < secret_word.length(); no++)
				{
					cout << space_wrong[no];
				}
			
			cout << endl;	
		}
		while (num_of_guesses < 6);
	
		cout << "Sorry you failed to guess the correct word, which was "
			 << secret_word << "\"" << endl;
		
		end:
		answer = go_again(); // Allow user to play again w/o exiting
	}
	while (answer == true);
		
	return 0;
}

/***********************************************************************
 * This function displays the selection menu for player 1 to choice a 
 * word from.
 **********************************************************************/
void menu()
{
	system("clear"); // clear the screen
	
	cout << "Please choose a secret word from the following list." << endl;
	cout << "1. " << choice[winner[0]] << endl;
	cout << "2. " << choice[winner[1]] << endl;
	cout << "3. " << choice[winner[2]] << endl;
	cout << "4. " << choice[winner[3]] << endl;
}
	
/***********************************************************************
 * This function gets the possible secret word choices from the text 
 * file labeled "words.txt" and stores the words to an array to allow 
 * the random number generator to randomly select 4 of them as choices
 * for player 1. 
***********************************************************************/
void get_choices()
{
	ifstream inputFile; 			// File stream object
	
	inputFile.open ("words.txt"); 	// Open the input file
	
	// For loop to read each word of file to an array spot
	for (int i = 0; i < MAX_SECRET_WORDS; i++)
	{
		inputFile >> choice[i];
	}
	
	inputFile.close();				// Close the input file
}

/***********************************************************************
 * This function gets the user's menu choice, validates it, and returns
 * it back to main.
***********************************************************************/
int user_selection()
{
	int menu_choice = 0; 	// Variable to store user choice
	cin >> menu_choice;	
	
	// While loop to validate user input 
	while (menu_choice < 1 || menu_choice > 4)
	{
		cout << "That is not a valid choice. Please select a number"
			 << " between 1 and 4: ";
		cin >> menu_choice;
	}
	
	return menu_choice;
}
	
/***********************************************************************
 * This function returns a random number between 0 and the MAX
 * value established as a Global Constant. 
 *********************************************************************/	
int rand_int(int a)
{	
	int possible_sec_word = 0; 	// Variable to hold random number
	int seed = 0;	 			// Variable to seed the random number generator
	
	seed = time(0) + a; 		// Set seed using time and value of place in array
	
	srand(seed); 				// Initialize random generator seed
	
	// Get random number b/w 0 and MAX to include MAX 
	possible_sec_word = rand() % (MAX_SECRET_WORDS);
	
	return possible_sec_word;	// Return random # to main
}	

/***********************************************************************
 * Function used to ask user if they would like to go again.
***********************************************************************/

bool go_again()
{
	bool answer = false; // Sets return to false 
	string user_answer;  // Used to get user's answer
	
	cout << "Would you like to play again? [y/n] ";
	cin.ignore();
	getline (cin, user_answer);
	
	if (user_answer == "y" || user_answer == "Y" || user_answer == "yes"
		|| user_answer == "Yes")
	{
		answer = true;
	}
	
	return answer;
}

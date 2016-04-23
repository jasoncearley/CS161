/**********************************************************************
 * Program: numGuess.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/9/14
 * Modified: 10/9/14
 * Description: This program will is a 2 player number guessing game.
 * Input: number to be guessed
 * Output: tell user if they are too high, low, or correct 
 * *******************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string again; 				// Establish string to determine if user wants to play again
	int number_to_guess, 		// Establish variable to hold the secrect number
		number_of_guesses,		// Establish variable to hold the number of guesses allowed
		guess_number;			// Establish variable to hold the current guess number
	int best_guess;				// Establish variable to hold the users closest guess
	
	// do loop to allow players to continue playing w/o having to run program again
	do
	{		
		cout << "Do not let your opponent see the screen while you input"
			 << " your number." << endl;
		cout << "Please enter a number between 0 and 1000: ";
		cin >> number_to_guess;
	
		// while loop prevents using number outside of given range
		while (number_to_guess < 0 || number_to_guess > 1000)
		{
			cout << "That is not a valid number. Please try again: ";
			cin >> number_to_guess;
		}
	
		cout << "How many tries would you like to give your opponent?"
			 << " Enter a value between 1 and 20: ";
		cin >> number_of_guesses;
	
		// while loop prevents using number outside of given range
		while (number_of_guesses < 1 || number_of_guesses > 20)
		{
			cout << "That is not a valid number. Please try again: ";
			cin >> number_of_guesses;
		}
	
		// clear screen so player 2 doesn't see secret number
		for (int clrscrn = 1; clrscrn <= 10000; clrscrn++)
		{
			cout << ' ' << endl;
		}
		
		int guess[number_of_guesses + 1]; // setup array to store guesses
		
		// for loop to allow user to guess secret number a given number of times
		for (guess_number = 1; guess_number <= number_of_guesses; 
			guess_number++)	
		{
			int max, min; // establish variables to dynamically eliminate possible choices
			if (guess_number == 1) // initialize max and min to max range of possible choices
			{
				max = 1001;
				min = -1;
			}
			
			cout << "Please enter guess number " << guess_number 
				 << " of " << number_of_guesses 
				 << " (between 0 & 1000): ";
			cin >> guess[guess_number];
			
			/* While loop ensures valid input based on users previous guesses. 
			 * If user guessed above secret number, then this loop prevents
			 * them from guessing a number > that number.*/
			while (guess[guess_number] >= max || guess[guess_number] <= min)
			{
				cout << "That is not a valid number. Please try again: ";
				cin >> guess[guess_number];
			}
			
			// Dynamically adjusts and stores max guess 
			if (guess[guess_number] < max && guess[guess_number] > number_to_guess)
			{
				max = guess[guess_number];
			}
			
			// Dynamically adjusts and stores min guess
			if (guess[guess_number] > min && guess[guess_number] < number_to_guess)
			{
				min = guess[guess_number];
			}
			
			// Escape sequence if user guesses correct number
			if (guess[guess_number] == number_to_guess)
			{
				cout << "That's Correct!" << endl;
				goto end;
			}
			
			// Tells user if they are above secret number
			if (guess[guess_number] > number_to_guess && guess_number < number_of_guesses)
			{
				cout << "You're too high. Pick a lower number. ";
			}
			
			// Tells user if they are below secret number
			if (guess[guess_number] < number_to_guess && guess_number < number_of_guesses)
			{
				cout << "You're too low. Pick a higher number. ";
			}	
			
			// This if/else statement stores the users closest guess
			if ((max - number_to_guess) <= (number_to_guess - min))
			{
				best_guess = max;
			}
		
			else
			{
				best_guess = min;
			}
			
		}	
		
		// If user failed to guess secret number, tells them what it was and their closest guess
		cout << "The secret number was " << number_to_guess << ". "
			 << "Your closest answer was " << best_guess << "." << endl;
		
		// Allows players to play again w/o exiting program	 	
		end:
		cout << "Would you like to play again [y/n]? ";
		cin.ignore();
		getline (cin, again);
	}
		while (again == "y" || again == "Y");
		
	return 0;
}

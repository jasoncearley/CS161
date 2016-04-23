/**********************************************************************
 * Program: finalist.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/21/14
 * Modified: 10/21/14
 * Description: This program will generate 4 random numbers using a 
 * 				function and none of the numbers will repeat.
 * Output: 4 non-repeating random numbers
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>   // rand/srand
#include <ctime>     // time 

using namespace std;

// Global Constants
const int MIN = 1, MAX = 25;

// Prototype rand_int function
int rand_int(int a); 

int main()
{
	// Variables to hold random number from rand_int function
	int winner[4] = {};
	
	// Do/while loop gets 4 winners until no two are the same
	do
	{
		// For loop gets 4 winners and stores them in an array
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
		   
	cout << "And the winners are .............. " << endl
		 << "Contestant number " << winner[0] << endl
		 << "Contestant number " << winner[1] << endl
		 << "Contestant number " << winner[2] << endl
		 << "Contestant number " << winner[3] << endl;
		 
	return 0;
}
	
/**********************************************************************
 * This function returns a random number between the MIN and MAX 
 * values established as Global Constants. 
 *********************************************************************/
	
int rand_int(int a)
{	
	int winners = 0; // Variable to hold random winner
	int seed = 0;	 // Variable to seed the random number generator
	
	seed = time(0) + a; // Set seed using time and value of place in array
	
	// Initialize random generator seed
	srand(seed); 
	
	// Get random number b/w min and max to include max 
	winners = rand() % ((MAX + 1) - MIN) + MIN;
	
	return winners;
}

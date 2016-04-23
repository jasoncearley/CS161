/**********************************************************************
 * Program: randFun.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/27/14
 * Modified: 10/27/14
 * Description: This program will generate a random number b/w a user
 * 				entered min and max value using a pass by reference
 * 				function.
 * Output: A random number w/in user's range
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>    // strings 
#include <cstdlib>   // rand/srand
#include <ctime>     // time 

using namespace std;

// Prototype rand_int function
void rand_int(const int &min, const int &max, int &val); 
void get_min(int &min);
void get_max(int &max);

int main()
{
	// Variables to store min, max, and random number
	int min = 0, max = 0, val = 0;   
	
	// do/while loop ensures min is < max
	do
	{
		get_min(min); // Get user's min value for random number range
						 // from the get_min function. 
						 
		get_max(max); // Get user's max value for random number range
						 // from the get_max function.
						 
		if (min >= max)
		{
			cout << "That is not a valid range. ";
		}
	}
	while (min >= max);
	
	// Use rand_int function to set val to random number w/in range provided
	rand_int(min, max, val);
	
	cout << "Your random number between " << min << " and " << max
		 << " is " << val << "." << endl;
		 
	return 0;
}

/***********************************************************************
 * This function gets the user's min value for the random number range 
 * and validates it.
 **********************************************************************/
void get_min(int &min)
 {
	 string low = ""; 		// Variable to hold user's input
	 unsigned found1 = 0; 	// Variable used to detect non-numeric entries
	 
	 // Do/while loop ensures low only contains numbers
	do 
	{
		cout << "Please enter the the minimum value for your random"
			 <<	" number range: ";
		getline (cin, low);
	
		found1 = low.find_first_not_of ("1234567890", 0);
		
		if (found1 != 4294967295)
		{
			cout << "That is not a valid entry. ";
		}  
	}
	while (found1 != 4294967295 || low.size() >= 20);
	
	// atoi converts string into an integer for use in rand_int function
	min = (atoi (low.c_str()));
}

/***********************************************************************
 * This function gets the user's max value for the random number range 
 * and validates it.
 **********************************************************************/
void get_max(int &max)
{
	string high = ""; 	 // String to store user's input
	unsigned found2 = 0; // Variable used to detect non-numeric entries
	
	// Do/while loop ensures high only contains numbers
	do
	{
		cout << "Please enter the the maximum value for your random"
			 <<	" number range: ";	 
		getline (cin, high);
		
		found2 = high.find_first_not_of ("1234567890", 0);
		
		if (found2 != 4294967295)
		{
			cout << "That is not a valid entry. ";
		}  
	} 
	while (found2 != 4294967295 || high.size() >= 20);
	
	// atoi converts string into an integer for use in rand_int function
	max = (atoi (high.c_str()));
}
	
/**********************************************************************
 * This function takes user's min and max vaules for the range of 
 * possible random numbers and sets val to a number within that range.
 *********************************************************************/
void rand_int(const int &min, const int &max, int &val)
{	
	// Initialize random generator seed using current time
	srand(time(NULL)); 
	
	// Set val to a random number b/w min and max
	val = rand() % (max - min) + min; 
}

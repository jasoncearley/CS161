/**********************************************************************
 * Program: randFun2.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/05/14
 * Modified: 11/05/14
 * Description: This program will generate a random number b/w a user
 * 				entered min and max value using a function with 
 * 				pointers as parameters.
 * Output: A random number w/in user's range
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>    // strings 
#include <cstdlib>   // rand/srand
#include <ctime>     // time 

using namespace std;

// Prototype rand_int function
void rand_int(const int *min, const int *max, int *val); 
void get_input(int*, int);

int main()
{
	// Variables to store min, max, and random number
	int min = 0, max = 0, val = 0; 
	
	// Establish pointers to an int
	int *min_ptr, *max_ptr, *val_ptr;
	
	// Store address of their respective parameter
	min_ptr = &min;
	max_ptr = &max;
	val_ptr = &val;  
	
	// do/while loop ensures min is < max
	do
	{
		get_input(min_ptr, 1); // Get user's min value for random 
							   // number range 
						 
		get_input(max_ptr, 2); // Get user's max value for random 
							   // number range
						 
		if (min >= max)
		{
			cout << "That is not a valid range. ";
		}
	}
	while (min >= max);
	
	// Use rand_int function to set val to random number w/in range
	rand_int(min_ptr, max_ptr, val_ptr);
	
	cout << "Your random number between " << min << " and " << max
		 << " is " << val << "." << endl;
		 
	return 0;
}

/***********************************************************************
 * This function gets the user's input values for the random number
 * range and validates it.
 **********************************************************************/
void get_input(int *num, int min_or_max)
 {
	 string value = "";   // Variable to hold user's input
	 unsigned found1 = 0; // Variable used to detect non-numeric entries
	 
	// Do/while loop ensures only numbers are entered
	do 
	{
		if (min_or_max == 1)
		{
			cout << "Please enter the minimum value for your random"
				 <<	" number range: ";
			getline (cin, value);
		}
		
		else
		{
			cout << "Please enter the maximum value for your random"
				 <<	" number range: ";
			getline (cin, value);
		}
	
		found1 = value.find_first_not_of ("1234567890", 0);
		
		if (found1 != 4294967295)
		{
			cout << "That is not a valid entry. ";
		}  
	}
	while (found1 != 4294967295 || value.size() >= 20);
	
	// atoi converts string into an integer for use in rand_int function
	*num = (atoi (value.c_str()));
}

/**********************************************************************
 * This function takes user's min and max vaules for the range of 
 * possible random numbers and sets val to a number within that range.
 *********************************************************************/
void rand_int(const int *min, const int *max, int *val)
{	
	// Initialize random generator seed using current time
	srand(time(NULL)); 
	
	// Set val to a random number b/w min and max
	*val = rand() % (*max - *min) + *min; 
}

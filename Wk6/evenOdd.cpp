/**********************************************************************
 * Program: evenOdd.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/03/14
 * Modified: 11/03/14
 * Description: This program takes as parameters an array of ints and
 *  			the size of the array. It should return the 
 * 				(sum of the even values) – (sum of the odd values). 
 * Output: (sum of the even values) – (sum of the odd values)
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>	 // Strings and atoi 

using namespace std;

// Prototype Function(s)
int get_values();
int array_math(const int [], int);

int main()
{
	// Initialize variable size to 0, this will hold user's array size
	int size = 0;
	
	cout << "How many values, upto 50, would you like to enter?";
	size = get_values();
	
	// While loop to ensure user's array size is valid
	while (size > 50 || size < 0)
	{
		cout << "That value is outside the available range. Please try"
			 << " again. " << endl;
		size = get_values();
	}
	
	int array[size]; // Initialize array size based on user input
	
	// For loop to initialize array values to 0
	for (int a = 0; a < size; a++)
	{
		array[a] = 0;
	}
	
	// For loop to fill contents of array w/ user's input
	for (int a = 0; a < size; a++)
	{
		cout << "Enter value " << a + 1 << " of " << size << ": ";
		array[a] = get_values();
	}
	
	cout << "The sum of the even values minus the sum of the odd values"
		 << " is: " << array_math(array, size) << endl;
	
	return 0;
}
	
/***********************************************************************
 * This function gets the user's array values.
 **********************************************************************/
int get_values()
{
	 string number = ""; 		// Variable to hold user's input
	 unsigned found1 = 0; 	// Variable used to detect non-numeric entries
	 
	 // Do/while loop ensures low only contains numbers
	do 
	{
		getline (cin, number);
	
		found1 = number.find_first_not_of ("1234567890-", 0);
		
		if (found1 != 4294967295)
		{
			cout << "That is not a valid entry. Please try again." 
				 << endl;
		}  
	}
	while (found1 != 4294967295 || number.size() >= 20);
	
	// atoi converts string into an integer
	return atoi (number.c_str());
}

/***********************************************************************
 * This function returns the sum of the even values minus the sum of 
 * the odd values.
 **********************************************************************/
int array_math(const int array[], int size)
{
	int total_evens = 0,	// Variable to add all evens
		total_odds = 0;		// Variable to add all odds
	
	// For loop to look at each value of array
	for (int a = 0; a < size; a++)
	{
		if (array[a] % 2 == 0) // If value at a is even sum it 
		{
			total_evens += array[a];
		}
		else 				  // If value at a is odd sum it
		{
			total_odds += array[a];
		}
	}
	
	return total_evens - total_odds;
}

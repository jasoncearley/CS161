/**********************************************************************
 * Program: sortFun.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/27/14
 * Modified: 10/27/14
 * Description: This program will ask the user for 3 integers and then
 * 				rearrange them in order of smallest to largest.
 * Output: 3 integers from smallest to largest
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>    // strings and atoi

using namespace std;

// Prototype rand_int function
void get_val1(int &val1);
void get_val2(int &val2);
void get_val3(int &val3);
void sort(int &val1, int &val2, int &val3, int &temp); 

int main()
{
	// Variables to store min, max, and random number
	int val1 = 0, val2 = 0, val3 = 0, temp = 0;   
	
	get_val1(val1); // Get user's 1st value 
						 
	get_val2(val2); // Get user's 2nd value 
		
	get_val3(val3); // Get user's 3rd value
	
	
	// Use sort function to sort the numbers provided
	sort(val1, val2, val3, temp);
	
	cout << "Your numbers sorted are " << val1 << " " << val2 << " "
		 << val3 << "." << endl;
		 
	return 0;
}

/***********************************************************************
 * This function gets the user's 1st value.
 **********************************************************************/
void get_val1(int &val1)
 {
	 string num1 = ""; 		// Variable to hold user's input
	 unsigned found1 = 0; 	// Variable used to detect non-numeric entries
	 
	 // Do/while loop ensures low only contains numbers
	do 
	{
		cout << "I will arrange any integer values entered from lowest"
			 << " to highest. Please enter your 1st interger: ";
		getline (cin, num1);
	
		found1 = num1.find_first_not_of ("1234567890", 0);
		
		if (found1 != 4294967295)
		{
			cout << "That is not a valid entry. ";
		}  
	}
	while (found1 != 4294967295 || num1.size() >= 20);
	
	// atoi converts string into an integer for use in rand_int function
	val1 = (atoi (num1.c_str()));
}

/***********************************************************************
 * This function gets the user's 2nd value.
 **********************************************************************/
void get_val2(int &val2)
{
	string num2 = ""; 	 // String to store user's input
	unsigned found2 = 0; // Variable used to detect non-numeric entries
	
	// Do/while loop ensures high only contains numbers
	do
	{
		cout << "Please enter your second number: ";	 
		getline (cin, num2);
		
		found2 = num2.find_first_not_of ("1234567890", 0);
		
		if (found2 != 4294967295)
		{
			cout << "That is not a valid entry. ";
		}  
	} 
	while (found2 != 4294967295 || num2.size() >= 20);
	
	// atoi converts string into an integer for use in rand_int function
	val2 = (atoi (num2.c_str()));
}

/***********************************************************************
 * This function gets the user's 3rd value.
 **********************************************************************/
void get_val3(int &val3)
{
	string num3 = ""; 	 // String to store user's input
	unsigned found3 = 0; // Variable used to detect non-numeric entries
	
	// Do/while loop ensures high only contains numbers
	do
	{
		cout << "Please enter your third number: ";	 
		getline (cin, num3);
		
		found3 = num3.find_first_not_of ("1234567890", 0);
		
		if (found3 != 4294967295)
		{
			cout << "That is not a valid entry. ";
		}  
	} 
	while (found3 != 4294967295 || num3.size() >= 20);
	
	// atoi converts string into an integer for use in rand_int function
	val3 = (atoi (num3.c_str()));
}
	
/**********************************************************************
 * This function takes user's vaules and sorts them from smallest to
 * largest.
 *********************************************************************/
void sort(int &val1, int &val2, int &val3, int &temp)
{	
	// Each if statement swaps the numbers if they are out of order
	if (val1 > val2)
	{
		temp = val1;
		val1 = val2;
		val2 = temp;
	}
	
	if (val1 > val3)
	{
		temp = val1;
		val1 = val3;
		val3 = temp;
	}
	
	if (val2 > val3)
	{
		temp = val2;
		val2 = val3;
		val3 = temp;
	}
}

/**********************************************************************
 * Program: randFun.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/21/14
 * Modified: 10/21/14
 * Description: This program will generate a random number by using a 
 * 				function.
 * Output: A random number  
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>    // strings 
#include <cstdlib>   // rand/srand
#include <ctime>     // time 

using namespace std;

int rand_int(int min, int max); // Prototype rand_int function

int main()
{
	string low = "", high = "";			// strings to store user's input
	int min = 0, max = 0, number = 0;   // variables to store min, max, and random number
	unsigned found1 = 0, found2 = 0;    // variables used to detect non-numeric entries
	
	// do/while loop ensures low is < high
	do
	{
		// do/while loop ensures low only contains numbers
		do 
		{
			cout << "Please enter the the minimum value for your random"
				 <<	" number range: ";
			getline (cin, low);
		
			found1 = low.find_first_not_of ("1234567890", 0); 
		}
		while (found1 != 4294967295 || low.size() >= 20);	
	
		// do/while loop ensures high only contains numbers
		do
		{
			cout << "Please enter the the maximum value for your random"
				 <<	" number range: ";	 
			getline (cin, high);
		
			found2 = high.find_first_not_of ("1234567890", 0); 
		} 
		while (found2 != 4294967295 || high.size() >= 20);
			
		cout << endl;
	}
	while (low >= high);
	
	// atoi converts string into an integer for use in rand function
	max = atoi (high.c_str());
	min = atoi (low.c_str());
	
	number = rand_int(min, max); // varible to store rand_int return value
	
	cout << "Your random number is " << number << endl;
	
	return 0;
}
	
/**********************************************************************
 * This function takes user's min and max vaules for the range of 
 * possible random numbers and returns a number within that range.
 *********************************************************************/
	
	int rand_int(int min, int max)
	{	
		srand(time(NULL)); // Initialize random generator seed using current time
		return (rand() % (max - min)) + min; // return random number b/w min and max
	
	}

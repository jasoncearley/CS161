/**********************************************************************
 * Program: randNum.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/15/14
 * Modified: 10/15/14
 * Description: This program will generate 10 random numbers.
 * Output: 10 random numbers  
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>   // rand/srand
#include <ctime>     // time
#include <string>    // string 

using namespace std;

int main()
{
	string spaces; // Create variable to print spaces between numbers
	
	srand(time(NULL)); // Initialize random generator seed using current time
	
	// Each for loop prints 5 random numbers
	for (int i = 0; i < 5; i++)
	{
		cout << rand() << spaces.assign(5, ' ');
	}
	
	cout << endl;
	
	for (int x = 0; x < 5; x++)
	{
		cout << rand() << spaces.assign(5, ' ');
	}
	
	cout << endl << endl;
	
	return 0;
}

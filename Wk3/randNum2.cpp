/**********************************************************************
 * Program: randNum2.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/16/14
 * Modified: 10/16/14
 * Description: This program will generate a random number between the 
 * 				user's min and max values.
 * Output: a random number  
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>   // rand/srand
#include <ctime>     // time
#include <string>

using namespace std;

int main()
{
	string min = "", max = "";
	int number = 0, high = 0, low = 0;
	unsigned found1 = 0, found2 = 0;
	
	do
	{
		do
		{
			cout << "Please enter the the minimum value for your random"
				 <<	" number range: ";
			getline (cin, min);
		
			found1 = min.find_first_not_of ("1234567890-", 0); 
		}
		while (found1 != 4294967295 || min.size() >= 20);	
	
	
		do
		{
			cout << "Please enter the the maximum value for your random"
				 <<	" number range: ";	 
			getline (cin, max);
		
			found2 = max.find_first_not_of ("1234567890-", 0); 
		} 
		while (found2 != 4294967295 || max.size() >= 20);
			
		cout << endl;
	}
	while (min >= max);
	
	high = atoi (max.c_str());
	low = atoi (min.c_str());
	
	srand(time(NULL)); // Initialize random generator seed using current time
	number = (rand() % (high - low)) + low;
	 
	cout << "Your random number is " << number << endl;
	
	return 0;
}

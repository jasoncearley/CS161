/**********************************************************************
 * Program: name.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/14/14
 * Modified: 10/14/14
 * Description: This program will take a user's input in the form of 
 * 				first name, then middle name or initial, and then 
 * 				last name. The program then outputs the name in the 
 * 				following format: Last Name, First Name, Middle Initial.
 * Output: user inputted name in the following format: Last Name, First
 * 		   Name, Middle Initial  
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>    // strings

using namespace std;

int main()
{
	string name;		// Create a string to hold users input
	char space (' '),   // Used to search name for first, middle, last
		 period ('.');  // Used to search name for a period
	unsigned found1 = 0, found2 = 0, found3 = 0; // initialize variable to find spaces
	
	cout << "Please enter your name in the following format: First name"
		 << " middle name or initial and last name. " << endl;
	
	getline(cin, name); // Store user's input to string name
		
	found1 = name.find(space, 0); // Search name for 1st space
	
	string first_name = name.substr (0, found1); // Create string for 1st name
	
	found2 = name.find_last_of (space, string::npos); // Search name for 2nd space
	
	string middle_name = name.substr (found1 + 1, (found2 - 1) - found1); // Create string for middle name
	
	string last_name = name.substr (found2 + 1, string::npos);  // Create string for last name
		
	found3 = name.find (period, 0); // Search name for a period
	
	// If name does not have a period and middle name is only 1 character long, print name w/ a period
	if ((found3 = -1) && (found2 - found1) == 2)
	{
		cout << last_name << ", " << first_name << ' ' << middle_name
			 << '.' << endl;
	}
	 
	else // Middle name is not an initial therefore no period is needed
	{
		cout << last_name << ", " << first_name << ' ' << middle_name
			 << endl;
	}

	cout << endl;
	
	return 0;
}

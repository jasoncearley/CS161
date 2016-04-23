/**********************************************************************
 * Program: strings.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/13/14
 * Modified: 10/13/14
 * Description: This program will create a string variable and print it 
 * 				one character at a time forwards and backwards and count
 * 				the number of letters.
 * Output: user inputted string and number of letters entered  
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>    // using strings
#include <cctype>    // using isaplha

using namespace std;

int main()
{
	string my_str; // Create string variable
	int count = 0; // Initialize count variable to 0 to count letters in name
	
	cout << "Please enter your name: ";
	getline(cin, my_str);
	
	cout << "You entered: ";
	
	// Print name one character at a time forwards and count each one
	for (unsigned int i = 0; i < my_str.length(); i++)
	{
		cout << my_str.at(i);
		
		if (isalpha(my_str.at(i)))
		{
			count++;
		}
	}
	
	cout << endl << "And backwards it is: ";
	
	// Print name one character at a time backwards
	for (int back = my_str.length()-1; back >= 0; back--)
	{
		cout << my_str.at(back);
	}
	
	cout << endl << "It contains " << count << " letters." << endl;
	  
	return 0;
}

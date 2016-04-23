/**********************************************************************
 * Program: loop.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/15/14
 * Modified: 10/15/14
 * Description: This program accepts two strings and returns whether
 * 			 	they have the same contents with the use of a loop to 
 * 				check each character individually.
 * Output: Whether two strings have the same contents 
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>    // using strings

using namespace std;

int main()
{
	string str1, str2; // Strings for users input
	unsigned count_same = 0;
	
	cout << "Please enter a word: ";
	getline (cin, str1);
	
	cout << "Please enter the same word or another word: ";
	getline (cin, str2);
	
	if (str1.length() == str2.length())
	{
		for (unsigned a = 0; a < str1.length(); a++)
		{
			if (str1.at(a) == str2.at(a))
			{
				count_same++;
			}
		}
		
		if (count_same == str1.length())
		{
			cout << endl << "You entered the same thing!" << endl;
		}
		
		else
		{
			cout << "You entered different things" << endl;
		}
	}
	
	else
	{
		cout << "You entered different things" << endl;
	}
	
	cout << endl;
	
	return 0;
}

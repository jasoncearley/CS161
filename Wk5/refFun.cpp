/**********************************************************************
 * Program: refFun.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/27/14
 * Modified: 10/27/14
 * Description: This program will compare two strings for equality
 * 				using a pass by reference function.
 * Output: If user inputted strigs are the same or not  
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>    // using strings

using namespace std;

// Prototype Functions
void get_str1(string &str1);
void get_str2(string &str2);
bool is_same(string &str1, string &str2); 

int main()
{
	// Strings for users input
	string str1 = "", str2 = ""; 
	
	// Use function to get string 1 from user.
	get_str1(str1);
	
	// Use function to get string 2 from user.
	get_str2(str2);
	
	// if/else statement to tell user if the entered same thing or not
	if (is_same(str1, str2))
	{
		cout << "You entered the same thing!" << endl;
	}
	else
	{
		cout << "You entered different things." << endl;
	}
	
	return 0;
}

/**********************************************************************
 * This funciton will get string 1 from the user.
***********************************************************************/
void get_str1(string &str1)
{
	cout << "Please enter a word: ";
	getline (cin, str1);
}

/**********************************************************************
 * This funciton will get string 2 from the user.
***********************************************************************/
void get_str2(string &str2)
{
	cout << "Please enter the same word or another word: ";
	getline (cin, str2);
}

/**********************************************************************
 * This funciton will compare srt1 and str2 to determine if they are 
 * equal using a loop to chech each character individually. If they 
 * are equal is_same will return true, otherwise it will return false.
***********************************************************************/
bool is_same(string &str1, string &str2)
{
	bool answer = false; // Sets return to false 
	unsigned count_same = 0;  // Used to count the number of same characters
	
	/* If str1 length does not == str2 length no need to check for each
	 * individual character you already know the strings are different*/
	if (str1.length() == str2.length())
	{
		// Loop to look at each character
		for (unsigned a = 0; a < str1.length(); a++)
		{
			if (str1.at(a) == str2.at(a))
			{
				count_same++; // Count number of same characters
			}
		}
		
		/* Since str1.length = str2.length, then if count_same is = to
		 * length then the strings are equal*/
		if (count_same == str1.length()) 
		{
			answer = true;
		}
	}
	
	return answer;  // Return true if same, otherwise return false
}

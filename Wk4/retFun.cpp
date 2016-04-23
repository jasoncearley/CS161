/**********************************************************************
 * Program: retFun.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/20/14
 * Modified: 10/20/14
 * Description: This program will compare two strings for equality
 * 				using a Function.
 * Output: If user inputted strigs are the same or not  
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>    // using strings

using namespace std;

bool is_same(string str1, string str2); // Prototype String Compare Function

int main()
{
	string str1, str2; // Strings for users input
	
	cout << "Please enter a word: "; // get user's input for str1
	getline (cin, str1);
	
	cout << "Please enter the same word or another word: "; // get user's input for str2
	getline (cin, str2);
	
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
 * This funciton will compare srt1 and str2 to determine if they are 
 * equal using a loop to chech each character individually. If they 
 * are equal is_same will return true, otherwise it will return false.
***********************************************************************/

bool is_same(string str1, string str2)
{
	bool answer = false; // sets return to false 
	unsigned count_same = 0;  // used to count the number of same characters
	
	
	/* if str1 length does not == str2 length no need to check for each
	 * individual character you already know the strings are different*/
	if (str1.length() == str2.length())
	{
		// loop to look at each character
		for (unsigned a = 0; a < str1.length(); a++)
		{
			if (str1.at(a) == str2.at(a))
			{
				count_same++; // count number of same characters
			}
		}
		
		/* since str1.length = str2.length, then if count_same is = to
		 * length then the strings are equal*/
		if (count_same == str1.length()) 
		{
			answer = true;
		}
	}
	
	return answer;  // return true if same, otherwise return false
}

/**********************************************************************
 * Program: firelaws.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/7/14
 * Modified: 10/7/14
 * Description: This program will will determine whether a meeting room 
 * 				is in violation of fire law regulations regarding the 
 * 				maximum room capacity.
 * Input: # of people attending meeting, max room capacity
 * Output: whether meeting meets fire code or not. 
 * *******************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int max, 			// Establish varible to hold room max occupancy
		attending;		// Establish varible to hold # attending meeting
	
	cout << "Please enter the total number of people attending the"
		 << " meeting: ";
	cin >> attending;
	cout << "Please enter the maximum room capacity: ";
	cin >> max;
	
	/* If/esle statement to determine if # of people attending is
	 * allowed based on max room occupancy */
	if (attending <= max)
	{
		cout << "Congratulations, your meeting meets fire code"
			 << " regulations." 
			 << max - attending // calculates how many more people can attend
			 << " more individuals may attend your meeting." << endl;
	 }
	else 
	{
		cout << "I'm sorry, your meeting does not meet fire code"
			 << " regulations."
			 << attending - max // calculates how many more people must be uninvited
			 << " people must be excluded from your meeting to meet"
			 << " fire code regulations" << endl; 
	 }
	 return 0;
 }

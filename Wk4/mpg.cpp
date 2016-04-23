/**********************************************************************
 * Program: mpg.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/22/14
 * Modified: 10/22/14
 * Description: This program will read in the number of liters of 
 * 				gasoline consumed by the user’s car and the number of 
 * 				miles traveled by the car and will then output the 
 * 				number of miles per gallon the car delivered.
 * Output: mpg user's car delivered  
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>	 // strtof conversion
#include <iomanip>	 // used to setprecision for displayed values

using namespace std;

// Global Constants
const float LITER_TO_GAL_CONVERSION = 0.264172;

// Function Prototypes 
float get_liters(); 
float get_miles();
float liters_gals(float liters);
bool go_again();

int main()
{	
	// variables to store values returned from their respective function
	float liters = 0, miles = 0, gallons = 0, mpg = 0;
	bool answer;

	// do/while loop to allow user to repeat program w/o exiting
	do
	{	
		// Setup so all numbers are shown to 2 decimal places
		cout << setprecision(2) << fixed << showpoint;
		
		liters = get_liters(); // get liters from appropriate function
		miles = get_miles(); // get miles from appropriate function
		gallons = liters_gals(liters); // get gallons from appropriate function
		mpg = miles/gallons; // ca;culate mpg
		
		cout << "You used " << liters << " liters, which converts to "
			 << gallons << " gallons. "
			 << "Since you drove " << miles << " miles, your"
			 << " miles per gallon efficiency equates to " << mpg
			 << " mpg." << endl
			 << endl;
			 
		answer = go_again();
	}
	while (answer == true);
	
	return 0;
}

/***********************************************************************
 * Function used to get user's liters consumed and prevent them from 
 * entering a non-numeric value.
***********************************************************************/

float get_liters()
{
	float liters = 0; // float to store liters once string is converted
	const int SIZE = 10; // constant to limit size of c-string 
	char liters_consumed[SIZE] = {}; // c-string to store user's input
	int val[SIZE] = {}, // array to hold character conversion to int
		count; // variable to count number of non-numeric characters
		
	// do/while loop ensures liters used is a + number
	do
	{
		count = 0;
		cout << "Please enter the amount of liters used: ";
		cin.getline (liters_consumed, SIZE);
			
		// loop to look at each character of string
		for (int a = 0; a < 10; a++)
		{
			// convert each character to ASCII number
			val[a] = static_cast<int>(liters_consumed[a]);
				
			// count number of illegal characters
			if ((val[a] >= 58) || (val[a] == 47) || ((val[a] <= 45) 
				&& val[a] != 0))
			{
				count++;
			}
		}
		
		if (count > 0)
		{
			cout << "That was not a vaild entry. ";
		}
	}
	while (count != 0);
		
	liters = strtof (liters_consumed, NULL); // convert string to float
		
	return liters;
}	
	
/***********************************************************************
 * Function used to get user's miles driven and prevent them from 
 * entering a non-numeric value.
***********************************************************************/
	
float get_miles()
{
	float miles = 0; // float to store miles once string is converted
	const int SIZE = 10; // constant to limit size of c-string 
	char miles_driven[SIZE] = {}; // c-string to store user's input
	int val[SIZE] = {}, // array to hold character conversion to int
		count; // variable to count number of non-numeric characters
		
	// do/while loop ensures miles driven is a + number
	do
	{
		count = 0;
		cout << "Please enter the miles driven: ";
		cin.getline (miles_driven, SIZE);
			
		// loop to look at each character of string
		for (int a = 0; a < 10; a++)
		{
			// convert each character to ASCII number
			val[a] = static_cast<int>(miles_driven[a]);
				
			// count number of illegal characters
			if ((val[a] >= 58) || (val[a] == 47) || ((val[a] <= 45) 
				&& val[a] != 0))
			{
				count++;
			}
		}
		
		if (count > 0)
		{
			cout << "That was not a vaild entry. ";
		}
	}
	while (count != 0);
		
	miles = strtof (miles_driven, NULL); // convert string to float
	
	return miles; 
}
	
/***********************************************************************
 * Function used to convert liters to gallons.
***********************************************************************/

float liters_gals(float liters)
{
	float gallons = 0.0;
		
	gallons = liters * (LITER_TO_GAL_CONVERSION);
		
	return gallons;
}

/***********************************************************************
 * Function used to ask user if they would like to go again.
***********************************************************************/

bool go_again()
{
	bool answer = false; // sets return to false 
	string user_answer;  // used to get users answer
	
	cout << "Would you like to calculate another mpg value? [y/n] ";
	getline (cin, user_answer);
	
	if (user_answer == "y" || user_answer == "Y" || user_answer == "yes"
		|| user_answer == "Yes")
	{
		answer = true;
	}
	
	return answer;
}

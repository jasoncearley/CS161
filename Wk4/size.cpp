/**********************************************************************
 * Program: size.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/23/14
 * Modified: 10/23/14
 * Description: This program will read in the user's height, weight,
 * 				and age and use that information to calculate their
 * 				hat size, jacket size, and waist in inches.
 * Output: hat size, jacket size, and waist in inches  
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>	 // strtof conversion
#include <iomanip>	 // used to setprecision for displayed values

using namespace std;

// Function Prototypes 
float get_height(); 
float get_weight();
int get_age();
float hat_size(float height, float weight);
float jacket_size(float height, float weight, int age);
float waist_size(float weight, int age);
bool go_again();

int main()
{	
	// variables to store values returned from their respective function
	float height = 0, weight = 0, hat = 0, jacket = 0, 
		  waist = 0;
	int age = 0;
	bool answer;

	// do/while loop to allow user to repeat program w/o exiting
	do
	{	
		// Setup so all numbers are shown to 2 decimal places
		cout << setprecision(2) << fixed << showpoint;
		
		height = get_height(); // get height from appropriate function
		weight = get_weight(); // get weight from appropriate function
		age = get_age(); // get age from appropriate function
		hat = hat_size(height, weight); // calculate hat size
		jacket = jacket_size(height, weight, age); // calculate jacket size
		waist = waist_size(weight, age); // calculate jacket size
		
		system("clear"); // Clear screen
		cout << "Because your weight is " << weight << " pounds and your"
			 << " height is " << height << " inches, your hat size is: "
			 << hat << endl
			 << "Because your height is " << height << " inches, your"
			 << " weight is " << weight << " pounds, and your"
			 << " age is " << age << " years, your jacket size is: "
			 << jacket << endl
			 << "Because your weight is " << weight << " pounds and your"
			 << " age is " << age << " years, your waist size is: "
			 << waist << endl
			 << endl;
			 
		answer = go_again();
	}
	while (answer == true);
	
	return 0;
}

/***********************************************************************
 * Function used to get user's height in inches and prevent them from 
 * entering a non-numeric value.
***********************************************************************/

float get_height()
{
	float height = 0.0; // float to store height once string is converted
	const int SIZE = 10; // constant to limit size of c-string 
	char user_height[SIZE] = {}; // c-string to store user's input
	int val[SIZE] = {}, // array to hold character conversion to int
		count; // variable to count number of non-numeric characters
		
	// do/while loop ensures height entered is a + number
	do
	{
		count = 0;
		cout << "Please enter your height in inches: ";
		cin.getline (user_height, SIZE);
			
		// loop to look at each character of string
		for (int a = 0; a < 10; a++)
		{
			// convert each character to ASCII number
			val[a] = static_cast<int>(user_height[a]);
				
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
		
	height = strtof (user_height, NULL); // convert string to float
		
	return height;
}

/***********************************************************************
 * Function used to get user's weight in pounds and prevent them from 
 * entering a non-numeric value.
***********************************************************************/

float get_weight()
{
	float weight = 0.0; // float to store weight once string is converted
	const int SIZE = 10; // constant to limit size of c-string 
	char user_weight[SIZE] = {}; // c-string to store user's input
	int val[SIZE] = {}, // array to hold character conversion to int
		count; // variable to count number of non-numeric characters
		
	// do/while loop ensures weight entered is a + number
	do
	{
		count = 0;
		cout << "Please enter your weight in pounds: ";
		cin.getline (user_weight, SIZE);
			
		// loop to look at each character of string
		for (int a = 0; a < 10; a++)
		{
			// convert each character to ASCII number
			val[a] = static_cast<int>(user_weight[a]);
				
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
		
	weight = strtof (user_weight, NULL); // convert string to float
		
	return weight;
}

/***********************************************************************
 * Function used to get user's age in years and prevent them from 
 * entering a non-numeric value.
***********************************************************************/

int get_age()
{
	int age = 0; // int to store age once string is converted
	const int SIZE = 10; // constant to limit size of c-string 
	char user_age[SIZE] = {}; // c-string to store user's input
	int val[SIZE] = {}, // array to hold character conversion to int
		count; // variable to count number of non-numeric characters
		
	// do/while loop ensures height entered is a + number
	do
	{
		count = 0;
		cout << "Please enter your age in years: ";
		cin.getline (user_age, SIZE);
			
		// loop to look at each character of string
		for (int a = 0; a < 10; a++)
		{
			// convert each character to ASCII number
			val[a] = static_cast<int>(user_age[a]);
				
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
		
	age = strtof (user_age, NULL); // convert string to float
		
	return age;
}

/***********************************************************************
 * This function takes a user's height and weight and calculates their
 * hat size.
***********************************************************************/
float hat_size(float height, float weight)
{
	float hat = 0.0;
	hat = (weight / height) * 2.9;
	
	return hat;
}

/***********************************************************************
 * This function takes a user's height, weight, and age and calculates 
 * their jacket size.
***********************************************************************/
float jacket_size(float height, float weight, int age)
{
	float jacket = 0.0;
	jacket = ((height * weight) / 288);
	
	if (age >=40)
	{
		jacket = jacket + (((age - 30) / 10) * 0.125);
	}
		
	return jacket;
}

/***********************************************************************
 * This function takes a user's weight and age and calculates 
 * their waist size.
***********************************************************************/
float waist_size(float weight, int age)
{
	float waist = 0.0;
	waist = ( weight / 5.7);
	
	if (age >= 30)
	{
		waist = waist + (((age - 28) / 2) * 0.1);
	}
		
	return waist;
}
/***********************************************************************
 * Function used to ask user if they would like to go again.
***********************************************************************/

bool go_again()
{
	bool answer = false; // sets return to false 
	string user_answer;  // used to get users answer
	
	cout << "Would you like to go again? [y/n] ";
	getline (cin, user_answer);
	
	if (user_answer == "y" || user_answer == "Y" || user_answer == "yes"
		|| user_answer == "Yes")
	{
		answer = true;
	}
	
	return answer;
}

/**********************************************************************
 * Program: recConvert.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 10/29/14
 * Modified: 10/29/14
 * Description: This program will allow the user to convert between 
 * 				binary and base 10.
 * Output: Base 10 # in Base 2 or Base 2 # in Base 10  
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>   // needed for srand/rand
#include <string>    // needed to use strings
#include <cmath>

using namespace std;

// Prototype Function(s)
void menu();
int user_selection();
int get_decimal();
string get_binary();
int convert_dec_bin(int decimal, int base);
int convert_bin_dec(char one, string binary, unsigned position);
bool go_again();

int main()
{
	int choice = 0,		// Variable to hold user's menu choice
		decimal = 0,	// Variable to hold user's decimal value
		base = 0;		// Variable to hold base value
	string binary = "";	// Variable to hold user's binary value
	string reverse = "";	// Variable to hold user's binary value
	bool answer; 		// Holds Go again answer
	
	// do/while loop to allow user to repeat program w/o exiting
	do
	{	
		menu();							// Display menu choices
		choice = user_selection(); 		// Assign choice the value 
										// returned by the user_selection
										// funcition
		
		// If/else to perform user's choice								
		if (choice == 1)
		{
			base = 2;
			
			decimal = get_decimal();
			
			cout << decimal << " converted to binary is "
				 << convert_dec_bin(decimal, base) << endl;
		}
		
		else if (choice == 2)
		{
			binary = get_binary();
			
			reverse = string(binary.rbegin(), binary.rend());
			
			cout << binary << " converted to decimal is " 
				 << convert_bin_dec('1', reverse, 0)
				 << endl;
		}
			
		else if (choice == 3)
		{
			goto end;
		}

		answer = go_again(); // Allow user to go again w/o exiting
	}
	while (answer == true);
	
	end:	
	return 0;
}

/***********************************************************************
 * This function displays the selection menu for user to choose from.
 **********************************************************************/
void menu()
{	
	cout << "What can I help you with?" << endl;
	cout << "1. Convert a Base 10 number to Binary"  << endl;
	cout << "2. Convert a Binary number to Base 10" << endl;
	cout << "3. Exit" << endl;
}

/***********************************************************************
 * This function gets the user's menu choice, validates it, and returns
 * it back to main.
***********************************************************************/
int user_selection()
{
	string number = ""; 	 // String to store user's input
	unsigned found1 = 0; // Variable used to detect invalid entries
	
	// Do/while loop ensures only valid entries
	do
	{	 
		getline (cin, number);
		
		found1 = number.find_first_not_of ("123", 0);
		
		if (found1 != 4294967295)
		{
			cout << "That is not a valid entry. Please select "
				 << "either 1, 2, or 3. ";
		}  
	} 
	while (found1 != 4294967295 || number.size() >= 5);
	
	// atoi converts string into an integer for use in rand_int function
	return (atoi (number.c_str()));
}
	
/***********************************************************************
 * Function used to ask user if they would like to go again.
***********************************************************************/

bool go_again()
{
	bool answer = false; // Sets return to false 
	string user_answer;  // Used to get user's answer
	
	cout << "Would you like to go again? [y/n] ";
//	cin.ignore();
	getline (cin, user_answer);
	
	if (user_answer == "y" || user_answer == "Y" || user_answer == "yes"
		|| user_answer == "Yes")
	{
		answer = true;
	}
	
	return answer;
}

/***********************************************************************
 * This function gets the user's base 10 number to convert, validates
 * it, and returns it back to main.
***********************************************************************/
int get_decimal()
{
	string number = ""; 	 // String to store user's input
	unsigned found1 = 0; 	 // Variable used to detect invalid entries
	
	do
	{
		cout << "Please enter the number you would like to"
			<< " convert: "; 
		getline (cin, number);
		
		found1 = number.find_first_not_of ("1234567890", 0);
		
		if (found1 != 4294967295 || number.size() >= 20)
		{
			cout << "That is not a valid entry. ";
		}  
	}
	while (found1 != 4294967295 || number.size() >= 20);
	
	// atoi converts string into an integer for use in rand_int function
	return (atoi (number.c_str()));
}

/***********************************************************************
 * This function gets the user's base 2 number to convert, validates
 * it, and returns it back to main.
***********************************************************************/
string get_binary()
{
	string number = ""; 	 // String to store user's input
	unsigned found1 = 0; 	 // Variable used to detect invalid entries
	
	do
	{
		cout << "Please enter the number you would like to"
			<< " convert: "; 
		getline (cin, number);
		
		found1 = number.find_first_not_of ("10", 0);
		
		if (found1 != 4294967295 || number.size() >= 20)
		{
			cout << "That is not a valid entry. ";
		}  
	}
	while (found1 != 4294967295 || number.size() >= 20);
	
	return number;
}

/***********************************************************************
 * This function converts the user's base 10 number to base 2 using 
 * recusion and returns it back to main.
***********************************************************************/
int convert_dec_bin(int decimal, int base)
{	
	if (decimal > 0)
	{
		return (decimal % base) + 
		10 * convert_dec_bin(decimal / base, base);
	}
	
	return 0;
}


/***********************************************************************
 * This function converts the user's base 2 number to base 10 using 
 * recusion and returns it back to main.
***********************************************************************/
int convert_bin_dec(char one, string binary, unsigned position)
{
	if (position == binary.length())
	{
		return 0;
	}
	if (binary[position] == one)
	{
		return pow(2, position) + 
		convert_bin_dec(one, binary, position + 1);
	}
	else 
	{
		return convert_bin_dec(one, binary, position + 1);
	}
	
	return 0;
}

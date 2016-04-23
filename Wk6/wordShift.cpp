/**********************************************************************
 * Program: wordShift.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/08/14
 * Modified: 11/08/14
 * Description: This program takes a string from the user and allows 
 * 				them to rearrange the string by reversing it or shifting
 * 				it right or left by a certain number of spaces.
 * Output: Rearranged string
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <cstdlib>	 // Strings
#include <cstring>	 // C-style strings

using namespace std;

// Prototype Function(s)
string get_input();
void menu();
int user_selection();
void shift_num(int*);
void reverse(char*, char*, unsigned int);
void left(char*, char*, int, int, unsigned int); 
void right(char*, char*, int, int, unsigned int); 

int main()
{
	string str = "";		// Holds user's string
	int menu_choice = 0, 	// Holds the user's menu choice
		num = 0;			// Used for left/right shift
	
	// Establish pointers to appropriate variables
	int *num_ptr;
	num_ptr = &num;
	
	cout << "Enter a string upto 30 characters long." << endl;
	
	
	// Call to function to get users string
	str = get_input();
	
	// Convert string to a C-Style String
	char *cstr = new char [str.length() + 1];
	strcpy (cstr, str.c_str());
	
	// Create temporary array to perform left/right shifts
	char temp[str.length() + 1];
	
	// Do/while loop to allow user to continue w/o exiting
	do
	{
		menu();							// Display menu choices
		menu_choice = user_selection(); // Assign word_choice the value 
										// returned by the user_selection
										// funcition
	
	
		// If/else to perform user's choice								
		if (menu_choice == 1)
		{
			reverse(cstr, temp, str.size());
			
			cout << "Your string reversed is \"";
			
			for (unsigned a = 0; a < str.size(); a++)
			{
				cout << *(cstr + a);
			}
			
			cout << "\"" << endl;
		}
		
		else if (menu_choice == 2)
		{
			cout << "How many spaces would you like to shift your"
				 << " string to the left? ";
			shift_num(num_ptr);
			
			if (num > str.size())
			{
				cout << "That is larger than your string size. Please"
					 << " enter a number < " << str.size() << ": ";
				shift_num(num_ptr);
			}
			
			int break_point = 0;
			
			break_point = str.size() - num;
			
			left(cstr, temp, break_point, num, str.size());
			
			cout << "Your string shifted left is \"";
			
			for (unsigned a = 0; a < str.size(); a++)
			{
				cout << *(cstr + a);
			}
			
			cout << "\"" << endl;
		}
		
		else if (menu_choice == 3)
		{
			cout << "How many spaces would you like to shift your"
				 << " string to the right? ";
			shift_num(num_ptr);
			
			if (num > str.size())
			{
				cout << "That is larger than your string size. Please"
					 << " enter a number < " << str.size() << ": ";
				shift_num(num_ptr);
			}
			
			int break_point = 0;
			
			break_point = str.size() - num;
			
			right(cstr, temp, break_point, num, str.size());
			
			cout << "Your string shifted right is \"";
			
			for (unsigned a = 0; a < str.size(); a++)
			{
				cout << *(cstr + a);
			}
			
			cout << "\"" << endl;
		}
	}
	while (menu_choice != 4);
	
	return 0;
}
	
/***********************************************************************
 * This function gets the user's input value and validates it.
 **********************************************************************/
string get_input()
{
	 string input = "";   // Variable to hold user's input
	
	// Do/while loop ensures only numbers are entered
	do 
	{
		getline(cin, input);
		
		if (input.size() > 30)
		{
			cout << "Your string is too long. Please try again. ";
		} 
	}
	while (input.size() > 30);
	
	return input;
}

/***********************************************************************
 * This function displays the selection menu for the user to choose 
 * from.
 **********************************************************************/
void menu()
{	
	cout << "Please choose a command from the following list:" << endl;
	cout << "1. Reverse your string." << endl;
	cout << "2. Left shift your string." << endl;
	cout << "3. Right Shift your string" << endl;
	cout << "4. Quit." << endl;
}

/***********************************************************************
 * This function gets the user's menu choice, validates it, and returns
 * it back to main.
***********************************************************************/
int user_selection()
{
	string number = "";  // Variable to hold user's input
	unsigned found1 = 0; // Variable used to detect non-numeric entries
	 
	// Do/while loop ensures only contains valid numbers
	do 
	{
		getline (cin, number);
	
		found1 = number.find_first_not_of ("1234", 0);
		
		if (found1 != 4294967295 || number.size() > 1)
		{
			cout << "That is not a valid entry. Please select a number "
				 << "between 1 and 4: " 
				 << endl;
		}
	}
	while (found1 != 4294967295 || number.size() > 1);
	
	// atoi converts string into an integer
	return atoi (number.c_str());	
}

/***********************************************************************
 * This function gets the user's input value and validates it.
 **********************************************************************/
void shift_num(int *num)
 {
	 string value = "";   // Variable to hold user's input
	 unsigned found1 = 0; // Variable used to detect non-numeric entries
	 
	// Do/while loop ensures only numbers are entered
	do 
	{
		getline (cin, value);
		
		found1 = value.find_first_not_of ("1234567890", 0);
		
		if (found1 != 4294967295)
		{
			cout << "That is not a valid entry. Please try again. ";
		}  
	}
	while (found1 != 4294967295 || value.size() >= 20);
	
	// atoi converts string into an integer for use in rand_int function
	*num = (atoi (value.c_str()));
}

/***********************************************************************
 * This function reverses the user's string.
***********************************************************************/
void reverse(char *cstr, char *temp, unsigned int size)
{	
	for (int a = (size - 1), b = 0; a >= 0; a--, b++)
	{
		*(temp + a) = *(cstr + b);
	}
	
	for (unsigned c = 0; c < size; c++)
	{
		*(cstr + c) = *(temp + c);
	}
}

/***********************************************************************
 * This function shifts the user's string to the left.
***********************************************************************/
void left(char *cstr, char *temp, int break_point, int num, unsigned
int size)
{		
	for (int a = (size - 1); a >= num; a--)
	{
		*(temp + (a - num)) = *(cstr + a);
	}
	
	for (int b = 0; b < num; b++)
	{
		*(temp + (b + break_point)) = *(cstr + b);
	}
	
	for (unsigned c = 0; c < size; c++)
	{
		*(cstr + c) = *(temp + c);
	}
}

/***********************************************************************
 * This function shifts the user's string to the right.
***********************************************************************/
void right(char *cstr, char *temp, int break_point, int num, unsigned
int size)
{		
	for (int a = 0; a < break_point; a++)
	{
		*(temp + (a + num)) = *(cstr + a);
	}
	
	for (signed b = (size - 1); b >= break_point; b--)
	{
		*(temp + (b - break_point)) = *(cstr + b);
	}
	
	for (unsigned c = 0; c < size; c++)
	{
		*(cstr + c) = *(temp + c);
	}
}

/**********************************************************************
 * Program: menu.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 12/01/14
 * Modified: 12/01/14
 * Description: This program will emulate a library using classes.
 * Output: Various.
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>	 // strings
#include <cstdlib>	 // atoi
#include "Book.h"
#include "Library.h"
#include "Patron.h"

using namespace std;

// Prototype Function(s)
void menu();
int user_selection();
double user_selection_d();

int main()
{
	int menu_choice = 0, 	// Holds the user's menu choice
		num_books = 0,		// Keep track of total # of books in Library
		num_members = 0;	// Keep track of total # of members in Library
	
	// Create a Library object to use class functions/variables 
	Library Evans;
	
	// Do/while loop to allow user to continue w/o exiting
	do
	{
		menu();							// Display menu choices
		menu_choice = user_selection(); // Assign menu_choice the value 
										// returned by the user_selection
										// function
	
	
		// If/else to perform user's choice								
		if (menu_choice == 1)
		{
			Evans.addBook(num_books);
			num_books++;
		}
		
		else if (menu_choice == 2)
		{
			Evans.addMember(num_members);
			num_members++;
		}
		
		else if (menu_choice == 3)
		{
			string tempString1 = "", tempString2 = "";
			
			cout << "Enter Patron ID#: ";
			getline(cin, tempString1);
			
			cout << "Enter Book ID#: ";
			getline(cin, tempString2);
			
			Evans.checkOutBook(tempString1, tempString2);
		}
		
		else if (menu_choice == 4)
		{
			string tempString1 = "";
			
			cout << "Enter Book ID#: ";
			getline(cin, tempString1);
			
			Evans.returnBook(tempString1);
		}
		
		else if (menu_choice == 5)
		{
			string tempString1 = "", tempString2 = "";
			
			cout << "Enter Patron ID#: ";
			getline(cin, tempString1);
			
			cout << "Enter Book ID#: ";
			getline(cin, tempString2);
			
			Evans.requestBook(tempString1, tempString2);
		}
		
		else if (menu_choice == 6)
		{
			string tempString1 = "";
			
			cout << "Enter Patron ID#: ";
			getline(cin, tempString1);
			
			cout << "Enter amount paid: ";
			double paid = user_selection_d();
			
			Evans.payFine(tempString1, -paid);
		}
		
		else if (menu_choice == 7)
		{
			Evans.incrementCurrentDate();
		}
		
		else if (menu_choice == 8)
		{
			string tempString = "";
	
			cout << "Enter Patron ID#: ";
			getline(cin, tempString);
			Evans.viewPatronInfo(tempString);	
		}
		
		else if (menu_choice == 9)
		{
			string tempString = "";
	
			cout << "Enter Book ID#: ";
			getline(cin, tempString);
			Evans.viewBookInfo(tempString);
		}
		
		else if (menu_choice == 10)
		{
			Evans.listPatrons(num_members);
		}
		
		else if (menu_choice == 11)
		{
			Evans.listBooks(num_books);
		}
	}
	while (menu_choice != 12);

	return 0;
}

/***********************************************************************
 * This function displays the selection menu for the user to choose 
 * from.
 **********************************************************************/
void menu()
{	
	cout << "Please choose a command from the following list:" << endl;
	cout << "1. Add Book." << endl;
	cout << "2. Add Member." << endl;
	cout << "3. Check Out A Book." << endl;
	cout << "4. Return A Book." << endl;
	cout << "5. Request A Book." << endl;
	cout << "6. Pay Fine." << endl;
	cout << "7. Increment Current Date." << endl;
	cout << "8. View Patron Information." << endl;
	cout << "9. View Book Information." << endl;
	cout << "10. List Patrons." << endl;
	cout << "11. List Books." << endl;
	cout << "12. Exit." << endl;
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
	
		found1 = number.find_first_not_of ("1234567890", 0);
		
		if (found1 != 4294967295 || (atoi (number.c_str()) > 12))
		{
			cout << "That is not a valid entry. Please select a number "
				 << "between 1 and 10: " 
				 << endl;
		}
	}
	while (found1 != 4294967295 || (atoi (number.c_str()) > 12));
	
	// atoi converts string into an integer
	return atoi (number.c_str());	
}

/***********************************************************************
 * This function gets the user's input, validates it, and returns
 * it as a double.
***********************************************************************/
double user_selection_d()
{
	string number = "";  // Variable to hold user's input
	unsigned found1 = 0; // Variable used to detect non-numeric entries
	 
	// Do/while loop ensures only contains valid numbers
	do 
	{
		getline (cin, number);
	
		found1 = number.find_first_not_of ("1234567890-.", 0);
		
		if (found1 != 4294967295 || number.size() > 20)
		{
			cout << "That is not a valid entry. Please try again: "
				 << endl;
		}
	}
	while (found1 != 4294967295 || number.size() > 20);
	
	// atoi converts string into a double
	return atof (number.c_str());	
}		

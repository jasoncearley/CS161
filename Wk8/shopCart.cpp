/**********************************************************************
 * Program: shopCart.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/18/14
 * Modified: 11/18/14
 * Description: This program program emulates a shopping cart by using 
 * 				structures.
 * Output: Shopping cart items & total price of items in cart.
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <limits> 	 // limits
#include <string>    // strings 
#include <cstdlib>   // atoi
#include <iomanip>	 // setpricision

using namespace std;

// Define Structures
struct Item
{
	string name;
	double price;
	int quantity;
};

// Prototype Function(s)
void menu();
int user_selection();
double user_selection_d();
void add_item(Item [], int);
void view_items(Item [], int);
void view_total(Item [], int);

int main()
{
	int menu_choice = 0,			// Holds the user's menu choice
		item_num = 0;				// Keep track of # of items in cart
	Item shoppingCart[100];			// Create array of structs for cart
	
	// Do/while loop to allow user to continue w/o exiting
	do
	{
		// Display User Menu
		menu();
	
		menu_choice = user_selection(); // Assign menu_choice the value 
										// returned by the user_selection
										// function
		
		if (menu_choice == 1)
		{
			add_item(shoppingCart, item_num);
			
			// Increment Items in cart by one
			item_num++;
		}
		
		else if (menu_choice == 2)
		{
			view_items(shoppingCart, item_num);
		}
		
		else if (menu_choice == 3)
		{
			view_total(shoppingCart, item_num);
		}
		
	}
	while (menu_choice != 4);
	
	
	return 0;
}

/***********************************************************************
 * This function displays the selection menu for the user to choose 
 * from.
 **********************************************************************/
void menu()
{		
	cout << endl << endl;
	cout << "Please choose a command from the following list:" << endl;
	cout << "1. Add Item To Your Cart." << endl;
	cout << "2. View Items In Cart." << endl;
	cout << "3. View Total Price Of Items In Cart." << endl;
	cout << "4. Quit." << endl << endl;
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
			cout << "That is not a valid entry. Please enter a number "
				 << "between 1 and 4: " 
				 << endl;
		}
	}
	while (found1 != 4294967295 || number.size() > 1);
	
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

/***********************************************************************
 * This function gets the user's input, validates it, and returns
 * it as an integer.
***********************************************************************/
int user_selection_i()
{
	string number = "";  // Variable to hold user's input
	unsigned found1 = 0; // Variable used to detect non-numeric entries
	 
	// Do/while loop ensures only contains valid numbers
	do 
	{
		getline (cin, number);
	
		found1 = number.find_first_not_of ("1234567890", 0);
		
		if (found1 != 4294967295 || number.size() > 20)
		{
			cout << "That is not a valid entry. Please try again: "
				 << endl;
		}
	}
	while (found1 != 4294967295 || number.size() > 20);
	
	// atoi converts string into an integer
	return atoi (number.c_str());	
}

/***********************************************************************
 * This function allows the user to add an item to their shopping cart 
 * using pass by reference.
***********************************************************************/
void add_item(Item cart[], int num)
{
	cout << "Enter the name of your Item: ";
	getline(cin, cart[num].name);
	
	cout << endl << "Enter the price of your Item (ex. 1.25): $";
	cart[num].price = user_selection_d();
	
	cout << endl << "Enter the quantity: ";
	cart[num].quantity = user_selection_i();	
}

/***********************************************************************
 * This function displays the items in the user's shopping cart.
***********************************************************************/
void view_items(Item cart[],int num)
{
	// Setup so all numbers are shown to 2 decimal places
	cout << setprecision(2) << fixed << showpoint;
	
	if (num == 0)
	{
		cout << "There are no items in your cart to display." << endl;
	}
	
	else
	{
		for (int a = 0; a < num; a++)
		{
			cout << "Item " << a + 1 << " of " << num << ":" << endl;
		
			cout << cart[a].name << endl
				<< "Price: " << cart[a].price << endl
				<< "Quantity: " << cart[a].quantity << endl << endl;
		}
	}
}

/***********************************************************************
 * This function displays the total price of all items in the user's 
 * shopping cart.
***********************************************************************/
void view_total(Item cart[],int num)
{
	double total = 0.0;
	
	// Setup so all numbers are shown to 2 decimal places
	cout << setprecision(2) << fixed << showpoint;
	
	if (num == 0)
	{
		cout << "There are no items in your cart to display." << endl;
	}
	
	else
	{
		cout << "The Total price of all items in your cart is: ";
		
		for (int a = 0; a < num; a++)
		{
			total += (cart[a].price * cart[a].quantity);
		}
		
		cout << total;
	}
}

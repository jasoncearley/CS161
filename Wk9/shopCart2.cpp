/**********************************************************************
 * Program: shopCart2.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/18/14
 * Modified: 11/18/14
 * Description: This program emulates a shopping cart by using classes.
 * Output: Shopping cart items & total price of items in cart.
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <limits> 	 // limits
#include <string>    // strings 
#include <cstdlib>   // atoi
#include <iomanip>	 // setpricision
#include <vector>	 // vectors

using namespace std;

// Define Classes
class Item
{
	private:
	string name;
	double price;
	int quantity;
	
	public:
	Item() 
	{
		name = "";
		price = 0.0;
		quantity = 0;
	}
	
	string get_name()
	{return name;}
	
	double get_price()
	{return price;}
	
	int get_quantity()
	{return quantity;}
	
	void set_name (string n)
	{name = n;}
	
	void set_price (double p)
	{price = p;}
	
	void set_quantity (int q)
	{quantity = q;}
	
};

class ShoppingCart
{
	private:
	vector <Item> cart;
	
	public:
	void addItem (int);
	void listItems (int);
	void totalPrice (int);
};

// Prototype Function(s)
void menu();
int user_selection();
int user_selection_i();
double user_selection_d();

// Class Functions

/***********************************************************************
 * This function allows the user to add an item to their shopping cart.
***********************************************************************/
void ShoppingCart::addItem (int index)
{
	string tempName = "";
	double tempPrice = 0.0;
	int tempQuantity = 0;
	
	cart.push_back(Item());
	
	cout << "Enter the name of your Item: ";
	getline(cin, tempName);
	cart[index].set_name(tempName);
	
	cout << endl << "Enter the price of your Item (ex. 1.25): $";
	tempPrice = user_selection_d();
	cart[index].set_price(tempPrice);
	
	cout << endl << "Enter the quantity: ";
	tempQuantity = user_selection_i();
	cart[index].set_quantity(tempQuantity);
}

/***********************************************************************
 * This function displays the items in the user's shopping cart.
***********************************************************************/
void ShoppingCart::listItems (int num)
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
		
			cout << cart[a].get_name() << endl
				<< "Price: " << cart[a].get_price() << endl
				<< "Quantity: " << cart[a].get_quantity() << endl << endl;
		}
	}
}

/***********************************************************************
 * This function displays the total price of all items in the user's 
 * shopping cart.
***********************************************************************/
void ShoppingCart::totalPrice(int num)
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
			total += (cart[a].get_price() * cart[a].get_quantity());
		}
		
		cout << total;
	}
}	
	
	
int main()
{
	int menu_choice = 0;			// Holds the user's menu choice
	int index = 0;					// Keep track of total items in cart
	ShoppingCart buggy;				// ShoppingCart class object
	
	
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
			buggy.addItem(index);
			index++;
		}
		
		else if (menu_choice == 2)
		{
			buggy.listItems(index);
		}
		
		else if (menu_choice == 3)
		{
			buggy.totalPrice(index);
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

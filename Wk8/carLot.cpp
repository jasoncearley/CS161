/**********************************************************************
 * Program: carLot.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/22/14
 * Modified: 11/21/14
 * Description: This program consists of  a struct called Date that 
 * 				consists of an int called day, an int called month and 
 * 				an int called year; a struct called Car that consists of 
 * 				a string called make, a string called model, an int 
 * 				called year, a Date called datePurchased, a double 
 * 				called purchasePrice, a bool called isSold, a Date 
 * 				called dateSold, and a double called salePrice; & a 
 * 				vector of Car. 
 * 
 * 	A menu gives the following options:
• 		Add entry: this allows the user to enter the information for a 
* 				   car, which is then added to the vector. The user is 
* 				   prompted for dateSold and salePrice if and only if 
* 				   isSold is true.
* 
• 		List current inventory: this lists the data for all Cars that 
* 								have been purchased, but not yet sold, 
* 								and then prints out the count of how 
* 								many cars that is.
* 
• 		Profit for a month: this asks the user for a month and year and 
* 							displays the total profit for sales in that 
* 							month.
* 
• 		Quit: exits the program.
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <string>    // strings 
#include <cstdlib>   // atoi
#include <vector>	 // vectors
#include <iomanip>   // setprecision and showpoint

using namespace std;

// Define Structures
struct Date
{
	int month, day, year;
	
	// Constructor
	Date(int a = 0)
	{
		month = a;
		day = a;
		year = a;
	}
};

struct Car
{
	string make;
	string model;
	int year;
	Date datePurchased, dateSold;
	double purchasePrice,
		   salePrice;
	bool isSold;
	
	
	// Constructor
	Car(string a = "", int i = 0, double d = 0.0)
	{
		make = a;
		model = a;
		year = i;
		purchasePrice = d;
		salePrice = d;
		datePurchased.day = i;
		datePurchased.month = i;
		datePurchased.year = i;
		dateSold.day = i;
		dateSold.month = i;
		dateSold.year = i;
	}
};


// Prototype Function(s)
void menu();
int user_selection();
int get_date(int);
double get_price();
bool get_sold();
bool check_date(int, int);
void add_vehicle(vector <Car> &);
void list_inventory(const vector <Car> &);
void list_profit(const vector <Car> &);

int main()
{
	int menu_choice = 0; 	// Holds the user's menu choice
	
	// Create a vector of Car structs called vehicle to hold info
	vector <Car> vehicle;
	
	// Do/while loop to allow user to continue w/o exiting
	do
	{
		menu();							// Display menu choices
		menu_choice = user_selection(); // Assign menu_choice the value 
										// returned by the user_selection
										// funcition
	
	
		// If/else to perform user's choice								
		if (menu_choice == 1)
		{
			// Call to add function
			add_vehicle(vehicle);
		}
		
		else if (menu_choice == 2)
		{
			// Call to list function
			list_inventory(vehicle);
		}
		
		else if (menu_choice == 3)
		{
			// Call to profit function
			list_profit(vehicle);
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
	cout << "Please choose a command from the following list:" << endl;
	cout << "1. Add Entry To Inventory." << endl;
	cout << "2. List Current Inventory." << endl;
	cout << "3. Get Profit For A Specified Month & Year." << endl;
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
 * This function gets the user's year, validates it, and returns
 * it back to the calling function.
***********************************************************************/
int get_date(int use)
{
	string number = "";  // Variable to hold user's input
	unsigned found1 = 0; // Variable used to detect non-numeric entries
	 
	// This if statement is used for Months
	if (use == 1)
	{
		// Do/while loop ensures only contains valid numbers
		do 
		{
			getline (cin, number);
	
			found1 = number.find_first_not_of ("1234567890", 0);
		
			if (found1 != 4294967295 || atoi(number.c_str()) < 1 ||
				atoi(number.c_str()) > 12)
			{
				cout << "That is not a valid entry. Please try again. " 
					 << endl;
			}
		}
		while (found1 != 4294967295 || atoi(number.c_str()) < 1 ||
				atoi(number.c_str()) > 12);
	
		// atoi converts string into an integer
		return atoi (number.c_str());
	}
	
	// This if statement is used for Days
	if (use == 2)
	{
		// Do/while loop ensures only contains valid numbers
		do 
		{
			getline (cin, number);
	
			found1 = number.find_first_not_of ("1234567890", 0);
		
			if (found1 != 4294967295 || atoi(number.c_str()) < 1 ||
				atoi(number.c_str()) > 31)
			{
				cout << "That is not a valid entry. Please try again. " 
					 << endl;
			}
		}
		while (found1 != 4294967295 || atoi(number.c_str()) < 1 ||
				atoi(number.c_str()) > 31);
	
		// atoi converts string into an integer
		return atoi (number.c_str());
	}
	
	// This if statement is used for Years
	if (use == 3)
	{
		// Do/while loop ensures only contains valid numbers
		do 
		{
			getline (cin, number);
	
			found1 = number.find_first_not_of ("1234567890", 0);
		
			if (found1 != 4294967295 || number.size() > 4)
			{
				cout << "That is not a valid entry. Please try again. " 
					 << endl;
			}
		}
		while (found1 != 4294967295 || number.size() > 4);
	
		// atoi converts string into an integer
		return atoi (number.c_str());
	}
	
	return 0;
}

/***********************************************************************
 * This function gets the user's input, validates it, and returns
 * it as a double.
***********************************************************************/
double get_price()
{
	string number = "";  // Variable to hold user's input
	unsigned found1 = 0; // Variable used to detect non-numeric entries
	 
	// Do/while loop ensures only contains valid numbers
	do 
	{
		getline (cin, number);
	
		found1 = number.find_first_not_of ("1234567890.", 0);
		
		if (found1 != 4294967295 || number.size() > 20)
		{
			cout << "That is not a valid entry. Please try again: "
				 << endl;
		}
	}
	while (found1 != 4294967295 || number.size() > 20);
	
	// atoi converts string into an integer
	return atof (number.c_str());	
}

/***********************************************************************
 * This function gets the user's input, validates it, and returns
 * it as a bool.
***********************************************************************/
bool get_sold()
{
	string number = "";  // Variable to hold user's input
	unsigned found1 = 0; // Variable used to detect non-numeric entries
	 
	// Do/while loop ensures only contains valid numbers
	do 
	{
		getline (cin, number);
	
		found1 = number.find_first_not_of ("yn", 0);
		
		if (found1 != 4294967295 || number.size() > 1)
		{
			cout << "That is not a valid entry. Please try again: "
				 << endl;
		}
	}
	while (found1 != 4294967295 || number.size() > 1);
	
	if (number == "y")
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

/***********************************************************************
 * This function validates the user's date to ensure it is correct.
***********************************************************************/
bool check_date(int m, int d)
{	
	if ((d <= 31 && m == 1) || (d <= 31 && m == 3) || 
		(d <= 31 && m == 5) || (d <= 31 && m == 7) || 
		(d <= 31 && m == 8) || (d <= 31 && m == 10) ||
		(d <= 31 && m == 12))
	{
		return true;
	}
	
	if ((d <= 30 && m == 4) || (d <= 30 && m == 6) || 
		(d <= 30 && m == 9) || (d <= 30 && m == 11))
	{
		return true;
	}
	
	if (d <= 28 && m == 2)
	{
		return true;
	}
	
	cout << "That is not a valid date. Try again. ";
	
	return false;
}

/***********************************************************************
 * This function gets the user's info for the car structure vehicle 
 * passed to it by reference. 
***********************************************************************/
void add_vehicle(vector <Car> &vehicle)
{
	static int index = 0;
	
	// Add a Car struct to the vector vehicle
	vehicle.push_back(Car());
	
	cout << "Enter the Make: ";
	getline(cin, vehicle[index].make);
	
	cout << endl << "Enter the Model: ";
	getline(cin, vehicle[index].model);
	
	cout << endl << "Enter the Year (ex 2011): ";
	vehicle[index].year = get_date(3);
	
	cout << endl << "Enter The Purchase Price: $";
	vehicle[index].purchasePrice = get_price();
	
	do
	{
		cout << endl << "Enter The Month Purchased: ";
		vehicle[index].datePurchased.month = get_date(1);

		cout << endl << "Enter The Day Purchased: ";
		vehicle[index].datePurchased.day = get_date(2);

	}
	while(!check_date(vehicle[index].datePurchased.month, 
					  vehicle[index].datePurchased.day));
			  
	cout << endl << "Enter The Year Purchased: ";
	vehicle[index].datePurchased.year = get_date(3);
	
	
	cout << endl << "Has this vehicle been sold (y or n)? ";
	vehicle[index].isSold = get_sold();
	
	if (vehicle[index].isSold)
	{
		cout << endl << "What Was The Sale Price? $";
		vehicle[index].salePrice = get_price();
		
		do
		{
			cout << endl << "Enter The Month Sold: ";
			vehicle[index].dateSold.month = get_date(1);
		
			cout << endl << "Enter The Day Sold: ";
			vehicle[index].dateSold.day = get_date(2);
		}
		while(!check_date(vehicle[index].dateSold.month, 
			  vehicle[index].dateSold.day));
		
		cout << endl << "Enter The Year Sold: ";
		vehicle[index].dateSold.year = get_date(3);
		
	}
	
	index++;
}

/***********************************************************************
 * This function lists the data for all cars currently in inventory.  
***********************************************************************/
void list_inventory(const vector <Car> &vehicle)
{
	cout << fixed << showpoint << setprecision(2) << endl;
	int count = 0;
	
	for (unsigned a = 0; a < vehicle.size(); a++)
	{
		if (!vehicle[a].isSold)
		{
			cout << "Make: " << vehicle[a].make << endl
				 << "Model: " << vehicle[a].model << endl
				 << "Year: " << vehicle[a].year << endl
				 << "Purchase Price: $" << vehicle[a].purchasePrice 
				 << endl
				 << "Date Purchased (mm/dd/yyyy): " 
				 << vehicle[a].datePurchased.month << "/" 
				 << vehicle[a].datePurchased.day << "/" 
				 << vehicle[a].datePurchased.year << endl;
			
			count++;
		}
		
		cout << endl;
	}
	
	cout << "There are currently " << count << " cars in inventory."
		 << endl << endl;
}

/***********************************************************************
 * This function lists the profit from all cars sold in a given month
 * of the year.  
***********************************************************************/
void list_profit(const vector <Car> &vehicle)
{
	cout << fixed << showpoint << setprecision(2) << endl;
	double profit = 0.0;
	int m = 0, y = 0;
	
	cout << "Enter The Month For Which You Would Like To See The"
		 << " Profits: ";
	m = get_date(1);
	
	cout << "Enter The Year For Which You Would Like To See The"
		 << " Profits: ";
	y = get_date(3);
	
	for (unsigned a = 0; a < vehicle.size(); a++)
	{
		if (vehicle[a].isSold && vehicle[a].dateSold.month == m 
			&& vehicle[a].dateSold.year == y)
		{
			profit += (vehicle[a].salePrice - vehicle[a].purchasePrice);
		}
	}
	
	cout << "The profit for the Month/Year requested is $" 
		 << profit << endl << endl;
}

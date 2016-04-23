/**********************************************************************
 * Program: carLot2.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/27/14
 * Modified: 11/27/14
 * Description: This program consists of  a class called Date that 
 * 				consists of an int called day, an int called month and 
 * 				an int called year; a class called Car that consists of 
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
#include <math.h>	 // NAN special value

using namespace std;

// Define Classes
class Date
{
	private:
	int month, day, year;
	
	public:
	Date()
	{
		month = 0;
		day = 0;
		year = 0;
	}
	
	int get_month()
	{return month;}
	
	int get_day()
	{return day;}
	
	int get_year()
	{return year;}
	
	void set_month (int m)
	{month = m;}
	
	void set_day (int d)
	{day = d;}
	
	void set_year (int y)
	{year = y;}
};

class Car
{
	private:
	string make;
	string model;
	int year;
	Date datePurchased, dateSold;
	double purchasePrice,
		   salePrice;
	bool isSold;
	
	public:
	Car()
	{
		string a = "";
		int i = 0; 
		double d = 0.0;
		
		make = a;
		model = a;
		year = i;
		purchasePrice = d;
		salePrice = d;
		datePurchased.set_day(i);
		datePurchased.set_month(i);
		datePurchased.set_year(i);
		dateSold.set_day(i);
		dateSold.set_month(i);
		dateSold.set_year(i);
	}
	
	string get_make()
	{return make;}
	
	string get_model()
	{return model;}
	
	int get_year()
	{return year;}
	
	int get_datePurchased_day()
	{return datePurchased.get_day();}
	
	int get_datePurchased_month()
	{return datePurchased.get_month();}
	
	int get_datePurchased_year()
	{return datePurchased.get_year();}
	
	int get_dateSold_day()
	{return dateSold.get_day();}
	
	int get_dateSold_month()
	{return dateSold.get_month();}
	
	int get_dateSold_year()
	{return dateSold.get_year();}
	
	double get_purchasePrice()
	{return purchasePrice;}
	
	double get_salePrice()
	{return salePrice;}
	
	bool get_isSold()
	{return isSold;}
	
	void set_make(string ma)
	{make = ma;}
	
	void set_model(string mod)
	{model = mod;}
	
	void set_year(int y)
	{year = y;}
	
	void set_datePurchased_day(int dp)
	{datePurchased.set_day(dp);}
	
	void set_datePurchased_month(int mp)
	{datePurchased.set_month(mp);}
	
	void set_datePurchased_year(int yp)
	{datePurchased.set_year(yp);}
	
	void set_dateSold_day(int ds)
	{dateSold.set_day(ds);}
	
	void set_dateSold_month(int ms)
	{dateSold.set_month(ms);}
	
	void set_dateSold_year(int ys)
	{dateSold.set_year(ys);}
	
	void set_purchasePrice(double p)
	{purchasePrice = p;}
	
	void set_salePrice(double s)
	{salePrice = s;}
	
	void set_isSold(bool sold)
	{isSold = sold;}
	
	double getProfit()
	{
		return (get_salePrice() - get_purchasePrice());
	}
};

class CarLot
{
	private:
	vector <Car> vehicle;
	
	public:
	void addCar(int);
	void listCurrentInv(int);
	void getMonthProfit(int);
};

// Prototype Function(s)
void menu();
int user_selection();
int get_date(int);
double get_price();
bool get_sold();
bool check_date(int, int);

// Class Functions

/***********************************************************************
 * This function gets the user's info for the car. 
***********************************************************************/
void CarLot::addCar(int num)
{
	string tempString = "";
	int tempValue = 0;
	double tempPrice = 0.0;
	bool tempSold = false;
	
	// Add a Car class to the vector vehicle
	vehicle.push_back(Car());
	
	cout << "Enter the Make: ";
	getline(cin, tempString);
	vehicle[num].set_make(tempString);
	
	cout << endl << "Enter the Model: ";
	getline(cin, tempString);
	vehicle[num].set_model(tempString);
	
	cout << endl << "Enter the Year (ex 2011): ";
	tempValue = get_date(3);
	vehicle[num].set_year(tempValue);
	
	cout << endl << "Enter The Purchase Price: $";
	tempPrice = get_price();
	vehicle[num].set_purchasePrice(tempPrice);
	
	do
	{
		cout << endl << "Enter The Month Purchased: ";
		tempValue = get_date(1);
		vehicle[num].set_datePurchased_month(tempValue);

		cout << endl << "Enter The Day Purchased: ";
		tempValue = get_date(2);
		vehicle[num].set_datePurchased_day(tempValue);

	}
	while(!check_date(vehicle[num].get_datePurchased_month(), 
					  vehicle[num].get_datePurchased_day()));
			  
	cout << endl << "Enter The Year Purchased: ";
	tempValue = get_date(3);
	vehicle[num].set_datePurchased_year(tempValue);
	
	cout << endl << "Has this vehicle been sold (y or n)? ";
	tempSold = get_sold();
	vehicle[num].set_isSold(tempSold);
	
	if (vehicle[num].get_isSold())
	{
		cout << endl << "What Was The Sale Price? $";
		tempPrice = get_price();
		vehicle[num].set_salePrice(tempPrice);
		
		do
		{
			cout << endl << "Enter The Month Sold: ";
			tempValue = get_date(1);
			vehicle[num].set_dateSold_month(tempValue);
		
			cout << endl << "Enter The Day Sold: ";
			tempValue = get_date(2);
			vehicle[num].set_dateSold_day(tempValue);
		}
		while(!check_date(vehicle[num].get_dateSold_month(), 
			  vehicle[num].get_dateSold_day()));
		
		cout << endl << "Enter The Year Sold: ";
		tempValue = get_date(3);
		vehicle[num].set_dateSold_year(tempValue);
	}
}

/***********************************************************************
 * This function lists the data for all cars currently in inventory.  
***********************************************************************/
void CarLot::listCurrentInv(int num)
{
	cout << fixed << showpoint << setprecision(2) << endl;
	int count = 0;
	
	for (int a = 0; a < num; a++)
	{
		if (!vehicle[a].get_isSold())
		{
			cout << "Make: " << vehicle[a].get_make() << endl
				 << "Model: " << vehicle[a].get_model() << endl
				 << "Year: " << vehicle[a].get_year() << endl
				 << "Purchase Price: $" << vehicle[a].get_purchasePrice() 
				 << endl
				 << "Date Purchased (mm/dd/yyyy): " 
				 << vehicle[a].get_datePurchased_month() << "/" 
				 << vehicle[a].get_datePurchased_day() << "/" 
				 << vehicle[a].get_datePurchased_year() << endl;
			
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
void CarLot::getMonthProfit(int num)
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
	
	for (int a = 0; a < num; a++)
	{
		if (vehicle[a].get_isSold() && 
			vehicle[a].get_dateSold_month() == m &&
			vehicle[a].get_dateSold_year() == y)
		{
			profit += (vehicle[a].get_salePrice() - 
					   vehicle[a].get_purchasePrice());
		}
	}
	
	cout << "The profit for the Month/Year requested is $" 
		 << profit << endl << endl;
}

int main()
{
	int menu_choice = 0; 	// Holds the user's menu choice
	int index = 0;			// Keep track of number of cars added
	
	// Create a CarLot object to use class functions/variables 
	CarLot lot;
	
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
			// Call to add function
			lot.addCar(index);
			
			index++;
		}
		
		else if (menu_choice == 2)
		{
			// Call to list function
			lot.listCurrentInv(index);
		}
		
		else if (menu_choice == 3)
		{
			// Call to profit function
			lot.getMonthProfit(index);
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
 * This function gets the user's date variable, validates it, and returns
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

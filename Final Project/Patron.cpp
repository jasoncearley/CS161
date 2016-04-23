#include <iostream>  // cin/cout
#include <string>	 // strings
#include <iomanip>	 // setprecision and showpoint
#include "Book.h"
#include "Library.h"
#include "Patron.h"

using namespace std;

// Patron Constructor
Patron::Patron()
{
	idNum = "";
	name = "";
	vector <Book*> checkedOutBooks;
	fineAmount = 0.0;
}

Patron::Patron(string idn, string n)
{
	idNum = idn;
	name = n;
}

void Patron::set_name(string n)
{
	name = n;
}

void Patron::set_idNum(string idn)
{
	idNum = idn;
}

string Patron::getIdNum()
{
	return idNum;
}

string Patron::getName()
{
	return name;
}

vector <Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}

void Patron::addBook(Book* b)
{
	// Add a Book ptr to the checkedout book vector
	checkedOutBooks.push_back(b);
}

void Patron::removeBook(Book* b)
{
	// Find the book ptr in the vector and remove it
	for (unsigned a = 0; a < checkedOutBooks.size(); a++)
	{
		if (checkedOutBooks[a] == b)
		{
			checkedOutBooks.erase(checkedOutBooks.begin() + a);
		}
	}
}

double Patron::getFineAmount()
{
	// Only show 2 decimal places for fineAmount
	cout << setprecision(2) << fixed << showpoint;
	
	return fineAmount;
}

void Patron::amendFine(double amount)
{
	// + value increases fineAmount, a - value decreases it
	fineAmount += amount;
}

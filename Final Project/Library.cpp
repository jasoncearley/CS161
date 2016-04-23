#include <iostream>  // cin/cout
#include <string>
#include <vector>
#include "Book.h"
#include "Library.h"
#include "Patron.h"

using namespace std;

// Library Constructor
Library::Library()
{
	currentDate = 0;
	
	vector<Book> holdings;
    vector<Patron> members;
    
    holdings.reserve(100);
    members.reserve(100);
}

void Library::addMember(int index)
{
	string tempName = "",
		   tempID = "";
	int count;
	
	// Add a Patron to the members vector
	members.push_back(Patron());
	
	cout << "Enter Patron's Name: ";
	getline (cin, tempName);
	members[index].set_name(tempName);
	
	// Ensure a unique ID # is given
	do
	{
		cout << "Enter Patrons ID Number: ";
		getline (cin, tempID);
		members[index].set_idNum(tempID);
		
		// Set/reset count to 0
		count = 0;
		
		// Search members vector for ID #
		for (unsigned a = 0; a < members.size(); a++)
		{
			if (tempID == members[a].getIdNum())
			{
				count++;
			}
		}
		
		if (count > 1)
		{
			cout << "That ID Number is already taken. Please try"
				 << " again. " << endl;
		}
	}
	while(count > 1);	
}
	
void Library::listPatrons(int index)
{
	if (index == 0)
	{
		cout << "There are no Patrons to display." << endl;
	}
	
	else
	{
		for (int a = 0; a < index; a++)
		{
			cout << "Patron " << a + 1 << " of " << index << ":" << endl;
		
			cout << members[a].getName() << endl
				 << "ID Number: " << members[a].getIdNum() << endl
				 << endl;
		}
	}
}

void Library::addBook(int index)
{
	string tempTitle = "",
		   tempAuthor = "",
		   tempID = "";
	int count;
	
	// Add a Book to the holdings vector
	holdings.push_back(Book());
	
	cout << "Enter Title: ";
	getline (cin, tempTitle);
	holdings[index].set_title(tempTitle);
	
	cout << "Enter Author: ";
	getline (cin, tempAuthor);
	holdings[index].set_author(tempAuthor);
	
	// Ensure a unique ID# is given
	do
	{
		cout << "Enter Book's ID Number: ";
		getline (cin, tempID);
		holdings[index].set_IdCode(tempID);
		
		// Set/reset count to 0
		count = 0;
		
		// Search holdings vector for ID#
		for (unsigned a = 0; a < holdings.size(); a++)
		{
			if (tempID == holdings[a].getIdCode())
			{
				count++;
			}
		}
		
		if (count > 1)
		{
			cout << "That ID Number is already taken. Please try"
				 << " again. " << endl;
		}
	}
	while(count > 1);
}

void Library::listBooks(int index)
{
	if (index == 0)
	{
		cout << "There are no Books to display." << endl;
	}
	
	else
	{
		for (int a = 0; a < index; a++)
		{
			cout << "Book " << a + 1 << " of " << index << ":" << endl;
		
			cout << holdings[a].getTitle() << endl
				 << "Author: " << holdings[a].getAuthor() << endl
				 << "ID Number: " << holdings[a].getIdCode() << endl
				 << "Location: ";
				 
				 if (holdings[a].getLocation() == 0)
				 {
					 cout << "On Shelf" << endl << endl;
				 }
				 
				 else if (holdings[a].getLocation() == 1)
				 {
					 cout << "On Hold" << endl << endl;
				 }
				 
				 else
				 {
					 cout << "Checked Out" << endl << endl;
				 }
		}
	}
}

void Library::incrementCurrentDate()
{
	cout << endl << "Current Date is: " << currentDate << endl;
	
	currentDate++;
	
	cout << "Current Date is now: " << currentDate << endl << endl;
	
	// Find all checked out books and increment their date checked out
	for (unsigned a = 0; a < holdings.size(); a++)
	{
		if (holdings[a].getLocation() == CHECKED_OUT)
		{
			holdings[a].setDateCheckedOut(holdings[a].getDateCheckedOut() + 1);
			
			// Apply fine if book overdue 
			if ((Book::CHECK_OUT_LENGTH - holdings[a].getDateCheckedOut()) < 0)
			{	
				holdings[a].getCheckedOutBy() -> amendFine(Library::DAILY_FINE);
			}
		}
	}
}

void Library::viewPatronInfo(std::string patronID)
{
	int count = 0;
	
	// Find patron in members vector & dispaly info
	for (unsigned a = 0; a < members.size(); a++)
	{
		if (members[a].getIdNum() == patronID)
		{
			cout << endl << members[a].getName() << endl
				 << "ID#: " << members[a].getIdNum() << endl 
				 << "Books Checked Out: " << endl;
				 
			if (!members[a].getCheckedOutBooks().empty())
			{
			for (unsigned b = 0; b < members[a].getCheckedOutBooks().size();
				 b++)
			{
				cout << members[a].getCheckedOutBooks()[b] -> getTitle()
					 << endl;
			} 
			}
			cout << "Fines Due: $" << members[a].getFineAmount() << endl;
				 	 
			count++;
		}
	}
	
	if (count == 0)
	{
		cout << "Sorry, I can't find a Patron with that ID#." << endl;
	}
}	

void Library::viewBookInfo(std::string bookID)
{
	int count = 0;
	
	// find book in holdings vector & display info
	for (unsigned a = 0; a < holdings.size(); a++)
	{
		if (holdings[a].getIdCode() == bookID)
		{
			cout << holdings[a].getTitle() << endl
				 << "Author: " << holdings[a].getAuthor() << endl
				 << "ID Number: " << holdings[a].getIdCode() << endl;
				 
				 if (holdings[a].getLocation() == 0)
				 {
					 cout << "Location: On Shelf" << endl << endl;
				 }
				 
				 else if (holdings[a].getLocation() == 1)
				 {
					 cout << "On Hold By: " 
						  << holdings[a].getRequestedBy() -> getName()
						  << endl << endl;
				 }
				 
				 else if (holdings[a].getLocation() == 2)
				 {
					 cout << "Checked Out By: " 
						  << holdings[a].getCheckedOutBy() -> getName()
						  << endl
						  << "It is due within the next " 
						  << Book::CHECK_OUT_LENGTH - holdings[a].getDateCheckedOut() 
						  << " days." << endl << endl;
				 }
				 
			count++;
		}
	}
	
	if (count == 0)
	{
		cout << "Sorry, I can't find a Book with that ID#." << endl;
	}
}

void Library::checkOutBook(std::string patronID, std::string bookID)
{
	int count = 0;
	Book* book_ptr;
	Patron* patron_ptr;
	string bookName = "", patronName = "";
	
	// Find patron in members vector 
	for (unsigned a = 0; a < members.size(); a++)
	{
		if (members[a].getIdNum() == patronID)
		{
			count++;
			
			// Set pointer to member
			patron_ptr = &members[a];
		}
	}
	
	// If patron not found return to main
	if (count == 0)
	{
		cout << "Sorry, I can't find a Patron with that ID#." << endl;
		return;
	}
	
	// Reset count to 0
	count = 0;
	
	// Find book in holdings vector
	for (unsigned a = 0; a < holdings.size(); a++)
	{
		if (holdings[a].getIdCode() == bookID)
		{
			count++;
			
			// Set pointer to book
			book_ptr = &holdings[a];
		}
		
		// If book already checked out return to main
		if ((holdings[a].getLocation() == 2) && 
			(holdings[a].getIdCode() == bookID))
		{
			cout << "Sorry, that Book is already checked out." << endl;
			return;
		}
		
		// If on hold for another patron return to main
		if ((holdings[a].getLocation() == 1) && 
			(holdings[a].getIdCode() == bookID) &&
			(holdings[a].getRequestedBy() != patron_ptr))
		{
			cout << "Sorry, that Book is on hold for another patron." 
				 << endl;
			return;
		}
	}
	
	// Return to main if book was not found
	if (count == 0)
	{
		cout << "Sorry, I can't find a Book with that ID#." << endl;
		return;
	}
	
	// Find book in holdings vector to check it out 
	for (unsigned a = 0; a < holdings.size(); a++)
	{
		if (holdings[a].getIdCode() == bookID)
		{
			holdings[a].setCheckedOutBy(patron_ptr);
			holdings[a].setLocation(CHECKED_OUT);
			bookName = holdings[a].getTitle();
		}
		
		// If book was on hold by requesting patron reset requested by to NULL
		if (holdings[a].getRequestedBy() == patron_ptr)
		{
			holdings[a].setRequestedBy(NULL);
		}
	}
	
	// Find patron in members vector to add book to their checked out books vector
	for (unsigned a = 0; a < members.size(); a++)
	{
		if (members[a].getIdNum() == patronID)
		{
			members[a].addBook(book_ptr);
			patronName = members[a].getName();
		}
	}
	
	cout << bookName << " has been checked out by " << patronName
		 << endl << endl;
}

void Library::returnBook(std::string bookID)
{
	int count = 0;
	Book* book_ptr;
	string patron = "", book = "";
	
	// Find book in holdings vector
	for (unsigned a = 0; a < holdings.size(); a++)
	{
		// Return to main if book is not checked out
		if ((holdings[a].getLocation() != CHECKED_OUT) && 
			(holdings[a].getIdCode() == bookID))
		{
			cout << "Sorry, that Book is not checked out." << endl;
			return;
		}
		
		if (holdings[a].getIdCode() == bookID)
		{
			count++;
			
			// Set pointer to book
			book_ptr = &holdings[a];
			
			// Get book title
			book = holdings[a].getTitle();
			
			// Get who checked book out
			patron = holdings[a].getCheckedOutBy()-> getName();
		}
		
		// Set Data for returning book
		if (holdings[a].getIdCode() == bookID)
		{
			holdings[a].setCheckedOutBy(NULL);
			holdings[a].setDateCheckedOut(0);
			
			if (holdings[a].getRequestedBy() == NULL)
			{
				holdings[a].setLocation(ON_SHELF);
			}
			
			else
			{
				holdings[a].setLocation(ON_HOLD);
			}
		}
	}
	
	// Return to main if book was not found
	if (count == 0)
	{
		cout << "Sorry, I can't find a Book with that ID#." << endl;
		return;
	}
	
	// Find patron in members vector to remove book from their checked out books vector
	for (unsigned a = 0; a < members.size(); a++)
	{
		if (members[a].getName() == patron)
		{
			members[a].removeBook(book_ptr);
		}
	}
	
	cout << "Thank you " << patron << " for returning " << book << endl;
}

void Library::payFine(std::string patronID, double payment)
{
	// Find patron in members vector to amend fine
	for (unsigned a = 0; a < members.size(); a++)
	{
		if (members[a].getIdNum() == patronID)
		{			
			members[a].amendFine(payment);
			
			cout << members[a].getName() << "'s Fines are now: $" 
				 << members[a].getFineAmount() << endl;
		}
	}
}

void Library::requestBook(std::string patronID, std::string bookID)
{
	int count = 0;
	Patron* patron_ptr;
	string bookName = "", patronName = "";
	
	// Find patron in members vector 
	for (unsigned a = 0; a < members.size(); a++)
	{
		if (members[a].getIdNum() == patronID)
		{
			count++;
			
			// Set pointer to member
			patron_ptr = &members[a];
			
			// Save patron name
			patronName = members[a].getName();
		}
	}
	
	// Return to main if patron was not found
	if (count == 0)
	{
		cout << "Sorry, I can't find a Patron with that ID#." << endl;
		return;
	}
	
	// Reset count to 0
	count = 0;
	
	// Find book in holdings vector 
	for (unsigned a = 0; a < holdings.size(); a++)
	{
		if (holdings[a].getIdCode() == bookID)
		{
			count++;
			
			// Save book title
			bookName = holdings[a].getTitle();
		}
		
		// Return to main if book already on hold
		if (holdings[a].getRequestedBy() != NULL &&
			holdings[a].getIdCode() == bookID)
		{
			cout << "Sorry, that Book is already on hold." << endl;
			return;
		}
		
		// Set data for requesting book
		if (holdings[a].getIdCode() == bookID)
		{
			holdings[a].setRequestedBy(patron_ptr);
			
			if (holdings[a].getLocation() == ON_SHELF)
			{
				holdings[a].setLocation(ON_HOLD);
			}
		}
	}
	
	// Return to main if book was not found
	if (count == 0)
	{
		cout << "Sorry, I can't find a Book with that ID#." << endl;
		return;
	}
	
	cout << bookName << " is on hold for " << patronName << endl;
}

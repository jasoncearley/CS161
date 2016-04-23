#include <iostream>  // cin/cout
#include <string>
#include "Book.h"
#include "Library.h"
#include "Patron.h"

using namespace std;

// Book constructor
Book::Book()
{
	idCode = "";
	title = "";
	author = "";
	location = ON_SHELF;
	checkedOutBy = NULL;
	requestedBy = NULL;
	dateCheckedOut = 0;
}

Book::Book(string idc, string t, string a)
{
	idCode = idc;
	title = t;
	author = a;
}

string Book::getIdCode()
{
	return idCode;
}

string Book::getTitle()
{
	return title;
}

string Book::getAuthor()
{
	return author;
}

void Book::set_IdCode(string idc)
{
	idCode = idc;
}

void Book::set_title(string t)
{
	title = t;
}

void Book::set_author(string a)
{
	author = a;
}

Locale Book::getLocation()
{
	if (location == 0)
	{
		return ON_SHELF;
	}
	
	else if (location == 1)
	{
		return ON_HOLD;
	}
	
	else
	{
		return CHECKED_OUT;
	}
}

void Book::setLocation(Locale lo)
{
	location = lo;
}

Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
}

void Book::setCheckedOutBy(Patron* p)
{
	checkedOutBy = p;
}

Patron* Book::getRequestedBy()
{
	return requestedBy;
}

void Book::setRequestedBy(Patron* p)
{
	requestedBy = p;
}

int Book::getDateCheckedOut()
{
	return dateCheckedOut;
}

void Book::setDateCheckedOut(int d)
{
	dateCheckedOut = d;
}

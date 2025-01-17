//
//  Book.h
//  examples
//
//  Created by Tim Alcon on 11/25/14.
//  Copyright (c) 2014 Tim Alcon. All rights reserved.
//

#ifndef examples_Book_h
#define examples_Book_h
#include "Book.h"
#include "Library.h"
#include "Patron.h"

using namespace std;

class Patron;

enum Locale {ON_SHELF, ON_HOLD, CHECKED_OUT};

class Book
{
private:
    std::string idCode;
    std::string title;
    std::string author;
    Locale location;
    Patron* checkedOutBy;
    Patron* requestedBy;
    int dateCheckedOut;
public:
    static const int CHECK_OUT_LENGTH = 21;
    Book();
    Book(std::string idc, std::string t, std::string a);
    std::string getIdCode();
    void set_IdCode(string idc);
    std::string getTitle();
    void set_title(string t);
    std::string getAuthor();
    void set_author(string a);
    Locale getLocation();
    void setLocation(Locale lo);
    Patron* getCheckedOutBy();
    void setCheckedOutBy(Patron* p);
    Patron* getRequestedBy();
    void setRequestedBy(Patron* p);
    int getDateCheckedOut();
    void setDateCheckedOut(int d);
};

#endif

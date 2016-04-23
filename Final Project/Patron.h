//
//  Patron.h
//  examples
//
//  Created by Tim Alcon on 11/25/14.
//  Copyright (c) 2014 Tim Alcon. All rights reserved.
//

#ifndef __examples__Patron__
#define __examples__Patron__

#include <stdio.h>
#include <vector>
#include "Book.h"
#include "Library.h"
#include "Patron.h"

using namespace std;

class Book;

class Patron
{
private:
    std::string idNum;
    std::string name;
    std::vector<Book*> checkedOutBooks;
    double fineAmount;
public:
    Patron();
    Patron(std::string idn, std::string n);
    std::string getIdNum();
    void set_idNum(string idn);
    std::string getName();
    void set_name(string n);
    std::vector <Book*> getCheckedOutBooks();
    void addBook(Book* b);
    void removeBook(Book* b);
    double getFineAmount();
    void amendFine(double amount);
};

#endif /* defined(__examples__Patron__) */

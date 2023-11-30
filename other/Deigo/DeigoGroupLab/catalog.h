/*
 * catalog.h
 *
 *  Created on: Nov 13, 2023
 *      Author: JuanDiego Vargas
 *      Description : CSC-155-OC-C++ Computer Science I - Group Project - Library Management System - Catalog Class Header File
 *                    Catalog stores up to MAX_ITEMS (50) books in an array. You can check in, check out, add, and remove books.
 *                    As well as, get the total number of books in the catalog, check if a certain book is in the catalog, and 
 *                    check if the catalog is full.
 */

// catalog.h

#ifndef CATALOG_H
#define CATALOG_H

#include "book.h"
#include <string>
#include <iostream>

//definition of the Catalog class
const int MAX_ITEMS = 50; // max number of books that catalog will contain
const Book emptyBook; // an empty book (default constructor)
class Catalog {
public:
    Catalog();
    // default constructor
    void addBook(Book book);
    // function will add new book to catalog
    void removeBook(Book book);
    // remove book from catalog
    void checkIn(Book book);
    // check in book
    void checkOut(Book book);
    // check out book
    int getNumBooks();
    // return number of books in catalog
    bool isFull();
    // returns true if catalog is fool
    bool hasBook(Book book);
    // Check if book is in catalog
    std::string getBooks();
    // print all books in catalog
private:
    Book books[MAX_ITEMS]; 
    // store all books in array
    int numBooks;
    // store total number of books in catalog
};

#endif // CATALOG_H

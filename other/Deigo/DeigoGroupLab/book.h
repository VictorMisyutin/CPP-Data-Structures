/*
 * book.h
 *
 *  Created on: Nov 13, 2023
 *      Author: Nicholas Linnen
 *      Description : CSC-155-OC-C++ Computer Science I - Group Project - Library Management System - Book Class Header File
 *
 */

// Book.h

#ifndef BOOK_H
#define BOOK_H

#include <string>


//definition of the Book class
class Book {
public:
    std::string ISBN; //stores the the International Standard Book Number
    std::string title; //stores the title of the book
    std::string author; //stores the name of the author of the book
    std::string publisher; //stores the name of the publisher of the book
    //flag indicating whether the book is available (true)
    bool available;


    //constructor declaration
    //initializes the Book object with the given ISBN, title, author, and publisher.
    Book();
    Book(std::string isbn, std::string title, std::string author, std::string publisher);
    void CheckBookOut(); //function to mark as checked in
    void CheckBookIn(); //function to mark the book as checked out
    bool equals(Book otherBook); // check if two books are equal
    std::string GetBookDetails() const; //function to get book details as string
};

#endif // BOOK_H
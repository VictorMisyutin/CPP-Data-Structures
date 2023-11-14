//============================================================================
// Name        : Book.cpp
// Author      : Nicholas Linnen
// Description : CSC-155-OC-C++ Computer Science I - Group Project - Library Management System - Book Class CPP File
//
//============================================================================

// Book.cpp

#include "Book.h"
//default constructor definition
//initializes the member variables when a Book object is created
Book::Book(){
   ISBN = "";
   title = "";
   author = "";
   publisher = "";
   available = true; 
}

//constructor definition
//initializes the member variables with the values provided when a Book object is created
Book::Book(std::string isbn, std::string t, std::string a, std::string p)
    : ISBN(isbn), title(t), author(a), publisher(p), available(true) {}

//BookCheckOut function definition
//marks the book as checked out by setting 'available' to false

void Book::CheckBookOut() {
    available = false;
}


//BookCheckIn function definition
//marks the book as available again by setting 'available' to true
void Book::CheckBookIn() {
    available = true;
}

//BookEquals function definition 
//returns true if the two books are equal
bool Book::equals(Book otherBook){
    return (ISBN == otherBook.ISBN);
}

//GetBookDetails function definition
//returns a string containing the book's details
std::string Book::GetBookDetails() const {
    return "ISBN: " + ISBN + ", Title: " + title + ", Author: " + author + ", Publisher: " + publisher + ", Available: " + (available ? "Yes" : "No");
}


#include "catalog.h"

Catalog::Catalog(){
    numBooks = 0;
}

void Catalog::addBook(Book book){
    books[numBooks] = book;
    numBooks++;
}

void Catalog::removeBook(Book book){
    if(!hasBook(book)){
        std::cout << "Book is not in catalog" << std::endl;
        return;
    }
    for(int i = 0; i < MAX_ITEMS ; i++){
        if(books[i].equals(book)){
            books[i] = emptyBook;
            numBooks--;
            return;
        }
    }
}

void Catalog::checkIn(Book book){
    for(int i = 0; i < MAX_ITEMS; i++){
        if(books[i].equals(book)){
            books[i].CheckBookIn();
        }
    }
}

void Catalog::checkOut(Book book){
    for(int i = 0; i < MAX_ITEMS; i++){
        if(books[i].equals(book)){
            books[i].CheckBookOut();
        }
    }
}

bool Catalog::isFull(){
    return(MAX_ITEMS-1 == numBooks);
}

bool Catalog::hasBook(Book book){
    for(int i = 0; i < MAX_ITEMS ; i++){
        if(books[i].equals(book)){
            return true;
        }
    }
    return false;
}

std::string Catalog::getBooks(){
    std::string totalString = "";
    for(int i = 0; i < MAX_ITEMS; i++){
        if(!books[i].equals(emptyBook)){
            totalString += books[i].GetBookDetails() + "\n";
        }
    }
    return totalString;
}

int Catalog::getNumBooks(){
    return numBooks;
}
#include "catalog.h"
#include <iostream>

using namespace std;

int main(){
    Book book1("1", "Catcher In The Rye", "J.D Salinger", "Little, Brown and Company");
    Book book2("2", "The Great Gatsby", "F. Scott Fitzgerald", "Simon & Schuster");
    Book book3("3", "The Hobbit", "John Ronald Reuel Tolkien", "Houghton Mifflin Harcourt");
    Book book4("4" , "The Lord of the Rings" , "John Ronald Reuel Tolkien", "HarperCollins");

    Catalog library;
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);

    cout << library.getBooks() << endl;
    cout << "--------------" << endl;
    library.removeBook(book2);
    cout << library.getBooks() << endl;
    cout << "--------------" << endl;
    library.checkOut(book1);
    library.checkOut(book3);
    cout << library.getBooks() << endl;
    cout << "--------------" << endl;
    library.checkIn(book1);
    cout << library.getBooks() << endl;
    cout << "--------------" << endl;
    cout << "Total number of Book in Catalog: " << library.getNumBooks() << endl;

    return 0;

}
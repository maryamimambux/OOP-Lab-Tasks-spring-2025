// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;

public:
    Book(string t, string a, string i) : title(t), author(a), ISBN(i) {}
 
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
};

#endif

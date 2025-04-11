#include <iostream>
using namespace std;

class Librarian;
class Book {
    string title; 
    double price; 

    public:
    Book (string t = "Unknown", double p = 0.0 ) : title(t), price(p) {}
    friend class Librarian;
};

class Librarian {

    public:
    void display(const Book& book) {
        cout << book.title << " is for " << book.price << "$." << endl;
    }

    void apply_discount(Book& book, double discount) {
        book.price -= discount;
        cout << "Discounted Price: " << book.price <<"$" << endl; 
    }

};

int main() {

    Book book ("Book Theif", 23.5);
    Librarian librarian;

    librarian.display(book);
    librarian.apply_discount(book, 5.67);
  
    return 0;
}
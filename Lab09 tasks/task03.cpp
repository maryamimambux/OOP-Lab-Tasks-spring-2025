#include <iostream>
#include "Book.h"
using namespace std;

int main() {

    Book b1("The Alchemist", "Paulo Coelho", "9780061122415");
 
    cout << "Title: " << b1.getTitle() << endl;
    cout << "Author: " << b1.getAuthor() << endl;
    cout << "ISBN: " << b1.getISBN() << endl;

    return 0;
}

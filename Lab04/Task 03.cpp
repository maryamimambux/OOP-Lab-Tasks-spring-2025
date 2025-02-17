#include <iostream>
#include <limits> // For numeric_limits
#include <string>
using namespace std;

class Book {
public:
    // Parameters
    string title;
    double price;
    int *stock; // Pointer STOCK

    // Default Constructor
    Book() : title("Unknown"), price(0.0), stock(new int(30)) {}

    // Parameterized Constructor
    Book(string title, double price, int stock)
        : title(title), price(price), stock(new int(stock)) {}

    // Deep Copy Constructor (Fixed Syntax)
    Book(const Book& b)  
        : title(b.title), price(b.price), stock(new int(*b.stock)) {
        cout << "\nDeep Copy Constructor is called!" << endl;
    }

    // Destructor
    ~Book() {
        delete stock;
        cout << "\nThe Object is Destroyed!\n";
    }

    // Apply Discount Function
    void applyDiscount(int copies) {
        double totalPrice = price * copies;
        totalPrice -= (totalPrice * 0.05);
        cout << "5% discount has been applied.\nTotal Price is " << totalPrice << endl;

        if (copies > 5) {
            totalPrice -= (totalPrice * 0.1);
            cout << "10% discount has been applied.\nTotal Price is " << totalPrice << endl;
        }
    }

    // Purchase Member Function
    void purchase(int quantity) {
        if (*stock <= 0) {
            cout << "Stock is empty! Update the book details.\n";
            updateDetails();
        } else if (*stock < quantity) {
            cout << "Warning: Low Stock! Only " << *stock << " copies available.\n";
            updateDetails();
        } else {
            *stock -= quantity;
            cout << "Purchase successful. Remaining stock: " << *stock << endl;
            if (*stock <= 0) {
                cout << "Stock is empty! Update the book details.\n";
                updateDetails();
            }
        }
    }

    // Display Member Function
    void displayDetails() {
        cout << "\nDetails: " << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << *stock << endl;
    }

    // Update Member Function
    void updateDetails() {
        cout << "\nUpdate Details: " << endl;
        cout << "Price: ";
        cin >> price;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cout << "Title: ";
        getline(cin, title);
        cout << "Stock: ";
        cin >> *stock;
    }
 
};

int main() {
    // Dynamically allocate a Book object
    Book* b1 = new Book("Book Thief", 450.0, 50); 
    b1->displayDetails();
    
    // Create a deep copy using the copy constructor
    Book b2 = *b1;

    b1->updateDetails();
    cout << "\nOriginal Book:";
    b1->displayDetails();  

 
    cout << "\nCopied Book:";
    b2.displayDetails();   
    
     
    delete b1;
    b1 = nullptr; // Avoid dangling pointer 

    return 0;
}
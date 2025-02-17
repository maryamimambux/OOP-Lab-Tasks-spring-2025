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
    Book() : title("Unknown"), price(0.0), stock(new int (30)) {}

    // Parameterized Constructor
    Book(string title, double price, int stock) : title(title), price(price), stock(new int (stock)) {} 

    // Destructor
    ~Book() {
        delete stock;
    } 

    // Purchase Member Function
    void purchase(int quantity) {
    	double totalPrice = price * quantity;
        if (*stock <= 0) {
            cout << "Stock is empty! Update the book details.\n";
            updateDetails();
        } else if (*stock < quantity) {
        	*stock -= quantity;
            cout << "Warning: Low Stock! Only " << *stock << " copies available.\n";
            updateDetails();
        } else if (quantity > 0 && quantity <= 5) {
            *stock -= quantity;
            
            cout << "Purchase successful on base price.\n";
            cout << "Total price is " <<  totalPrice << endl;
            cout << "Remaining stock: " << *stock << endl;
            if (*stock <= 0) {
                cout << "Stock is empty! Update the book details.\n";
                updateDetails();
            }
        }
        else if (quantity > 5 && quantity <= 20) {
            *stock -= quantity;
            totalPrice -= (totalPrice * 0.05);
            cout << "Purchase successful on 5% discount.\n";
            cout << "Total price is " <<  totalPrice << endl;
			cout << "Remaining stock: " << *stock << endl;
            if (*stock <= 0) {
                cout << "Stock is empty! Update the book details.\n";
                updateDetails();
            }
        }
        else if (quantity > 20) {
            *stock -= quantity;
            totalPrice -= (totalPrice * 0.15);
            cout << "Purchase successful on bulk purchase discount.\n";
            cout << "Total price is " <<  totalPrice << endl;
            cout << "Remaining stock: " << *stock << endl;
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
    b1->purchase(20);

    b1->updateDetails();
    b1->displayDetails();

    b1->purchase(45);
    b1->displayDetails();

    b1->purchase(45);
    b1->displayDetails(); 
    // Properly delete dynamically allocated object
    delete b1;

    return 0;
}

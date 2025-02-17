#include <iostream>
#include <string>
using namespace std;

class Book {
	
    public:
    	// Parameters
        string title;
        double price;
        int *stock; // pointer STOCK
	
	// Default Contructor
    Book() {
        title = "Unknown";
        price = 0.0;
        stock = new int (30); // dynamic memory allocation of STOCK
    }

	// Parametrized Contructor
    Book(string title, double price, int stock) {
        this->title = title;
        this->price = price;
        this->stock = new int (stock);  
    }

	// Purchase Member Functions
    void purchase(int amount) {
        if (*stock > 0) {
            if (*stock < 5) {
                cout << "Warning: Low Stock!";
            }
            *stock -= amount;
        }
    } 

	// Display Member Function
    void displayDetails () {
        cout << "\nDetails: " << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << *stock << endl;

    } 

	// Update Member Function
    void updateDetails () { 
        cout << "\nUpdate Details: " << endl;
        cout << "Title: "; 
        getline(cin, title);
        cout << "Price: ";
        cin >> price;
        cout << "Stock: " ;
        cin >> *stock;
    }

};

int main() {

    Book b1( "Booktheif", 450.0, 50 );
    b1.purchase(20);
    b1.displayDetails();

    b1.updateDetails();

    b1.displayDetails();

    b1.purchase(45);
    b1.displayDetails(); 
    b1.purchase(45);


    return 0;
}
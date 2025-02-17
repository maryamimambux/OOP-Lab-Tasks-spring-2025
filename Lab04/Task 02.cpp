#include <iostream>
#include <limits> // For numeric_limits
#include <string>
using namespace std;

class Book {
	
    public:
    	
    // Parameters
    string title;
    double price;
    int *stock; // pointer STOCK
	
	// Default Contructor
    Book() : title ("Unknown"), price(0.0), stock(new int(30)) {}

	// Parametrized Contructor
    Book(string title, double price, int stock)  
    	: title(title), price(price), stock(new int(stock)) {}
    
    ~Book() {
    delete stock;
	}
    
    // Apply Discount Function 
    void applyDiscount(int copies) {
    	
    	double totalPrice = price*copies;
    	
    	if (copies > 5 && copies < 10) {
	    	totalPrice -= (totalPrice * 0.05);
	    	cout << "5% discount is been applied.\nFinal Price after discount:  " << totalPrice << endl;
    	}
    	
    	if (copies > 5 && copies > 10) {
    		totalPrice -= (totalPrice * 0.1);
    		cout << "10% discount is been applied.\nFinal Price after discount:  " << totalPrice << endl;	
    	} 
	}

	// Purchase Member Functions
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
            applyDiscount(quantity);
            if (*stock <= 0) {
                cout << "Stock is empty! Update the book details.\n";
                updateDetails();
            }
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
        cout << "Price: ";
        cin >> price;
        cin.ignore();
        cout << "Title: "; 
        getline(cin, title); 
        cout << "Stock: " ;
        cin >> *stock;
    } 

};

int main() {
	int quantity = 0;
    Book b1( "Booktheif", 450.0, 50 );
    b1.purchase(20);
    b1.displayDetails(); 
    
	cout << "\nEnter the quantity of Books you want to purchase: ";
	cin >> quantity;
	
    b1.purchase(quantity);
    //b1.applyDiscount(quantity);
    b1.displayDetails(); 
    
    cout << "\nEnter the quantity of Books you want to purchase: ";
	cin >> quantity;
    b1.purchase(quantity);
    //b1.applyDiscount(quantity);
    b1.displayDetails();  

    return 0;
}
 
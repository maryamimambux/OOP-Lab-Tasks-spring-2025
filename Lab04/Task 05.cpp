#include <iostream> 
#include <string>
using namespace std;

class Book {
public:
    // Parameters
    string title;
    double price;
    int *stock; // Pointer STOCK
    static inline int count = 0;
    static inline int* id = new int(100); 

    // Default Constructor
    Book() : title("Unknown"), price(0.0), stock(new int (30)) {
    	id = new int((*id)+1);
		count++;
	}

    // Parameterized Constructor
    Book(string title, double price, int stock) : title(title), price(price), stock(new int (stock)) {
		id = new int((*id)+1);
		count++;
	} 

    // Destructor
    ~Book() {
        delete stock;
        delete id;
    } 

    // Display Member Function
    void displayDetails() {
        cout << "\nDetails: " << endl;
        cout << "Book " << count << " ID: " << *id << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << *stock << endl;
    }
 
};

int main() {
	Book b1("The Lightning Thief", 450.76, 6465); 
	b1.displayDetails(); 
	
	Book b2("The Forty Rules of Love", 657.93, 3742); 
	b2.displayDetails(); 
	
	Book b3("The Flea Palace", 764.37, 3865); 
	b3.displayDetails(); 
	
	Book b4("Kite Runner", 923.18, 1786); 
	b4.displayDetails(); 
	
	Book b5("Lord of the Rings", 1525.45, 653); 
	b5.displayDetails(); 
	
	cout << "\nTotal No. of Books: " << Book :: count << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Product {
	public:
	    int id;
	    string name;
	    double price;
    
    Product(int id = 0, string name = "", double price = 0.0) : id(id), name(name), price(price) {}
    
    void productDetail() {
    	cout << "ID: ";
		cin >> id ;
		cin.ignore();
		cout << "Name: ";
		getline(cin,name); 
		cout << "Price: "; 
		cin >> price ; 
		cout << endl;
	}
    
    void display() {
    	cout << "ID: " << id << endl << "Name: " << name << endl << "Price: " << price << " $" << endl;
	}

};

class Inventory { 

	public:
		Product* product;
		int size;
		Inventory (int size) : size(size) {
			product = new Product [size];
		}
		
	void addProducts() {
		cout << "\nEnter Product Details: " << endl;
		for (int i = 0; i < size; i++) {
			cout << "Product " << i+1 << " :" << endl;
			product[i].productDetail(); 
		}
	} 
		
	void displayInventory() {
		cout << "\nInventory Details: " << endl;
		for (int i = 0; i < size; i++) {
			cout << "Product " << i+1 << " :" << endl;
			product[i].display();
			cout << endl;
		}
	}
		
	void sortInAscending() {
	    for (int i = 0; i < size - 1; i++) {  // Outer loop for passes
	        for (int j = 0; j < size - i - 1; j++) {  // Inner loop for comparisons
	            if (product[j].price > product[j + 1].price) {
	                Product temp = product[j];
	                product[j] = product[j + 1];
	                product[j + 1] = temp;
	            }
	        }
	    }
	}

		
	void searchProduct(string searchName) {
        for (int i = 0; i < size; i++) {
            if (product[i].name == searchName) {
                cout << "\nProduct Found:\n";
                product[i].display();
                return;
            }
        }
        cout << "\nProduct not found!\n\n";
    }	
	
};

int main() {
	
	Inventory store (4);
	
	store.addProducts();
	 // store.displayInventory();
	
	string name;
	cout << "Srearch Product (by name) : ";
	cin >> name;
	
	store.searchProduct(name);
	
	store.sortInAscending();
	cout << "\nProducts Sorted in Ascending Order by Price: " << endl;
	store.displayInventory();
	
}
 

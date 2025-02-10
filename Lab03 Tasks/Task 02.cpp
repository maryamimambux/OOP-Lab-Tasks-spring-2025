// Task 02
#include <iostream>
#include <string>
using namespace std;

class TeaMug {
public:
    string brand;
    string color;
    int capacity;
    int currentfillLevel;

    // Constructor
    TeaMug(string brand, string color, int capacity, int currentfillLevel) {
        this->brand = brand;
        this->color = color;
        this->capacity = capacity;
        this->currentfillLevel = currentfillLevel;
    }
    
    TeaMug() {
    	
	}

    // Sip tea method
    void sip_tea(int amount) {
        if (currentfillLevel >= amount) {
            currentfillLevel -= amount;
            cout << "Sip from " << color << " mug. Remaining level: " << currentfillLevel << "%." << endl;
        } else if (currentfillLevel > 0) {
            cout << "Not enough tea! You can only sip " << currentfillLevel << "%." << endl;
            currentfillLevel = 0;
        } else {
            cout << "Cup is empty! Please refill." << endl;
        }
    }

    // Refill method
    void refill() {
        if (currentfillLevel < capacity) {
            currentfillLevel = capacity;
            cout << "Mug refilled to full capacity: " << capacity << "%." << endl;
        } else {
            cout << "The mug is already full!" << endl;
        }
    }

    // Check mug status
    void check_status() {
        cout << "Mug Brand: " << brand << endl;
        cout << "Mug Color: " << color << endl;
        cout << "Current Fill Level: " << currentfillLevel << "%" << endl;
        cout << "Capacity: " << capacity << "%" << endl;
    }
    
    void enterDetails() {
    	cout << "Brand: ";
    	getline (cin, brand);
    	cout << "Color: ";
    	getline (cin, color);
    	cout << "Capacity: ";
    	cin >> capacity;
    	cout << "Current Level: ";
    	cin >> currentfillLevel;
	}
	
	void menu() {
		int choice = 0;
		while(1) {
			cout << endl;
			cout << "Enter Choice: " << endl;
			cout << "0. Exit" << endl;
			cout << "1. Sip Tea" << endl;
			cout << "2. Refill" << endl;
			cout << "3. Check Status" << endl << endl;
			cin >> choice; 
			
			switch (choice) {
				case 0:
					exit(0);
					break;
				case 1:
					int amount;
					cout << "Enter amount of sip: ";
					cin >> amount;
					sip_tea(amount);
					break;
				case 2:
					refill();
					break;
				case 3:
					check_status();
					break;
				default:
					cout <<"Invalid choice" << endl;	
			}
			
		} 
		
	}
    
};

int main() {
    //TeaMug mug("Yeti Rambler", "Black", 100, 40);
    TeaMug mug1;
    mug1.enterDetails();
    
    mug1.menu();
	

    return 0;
}


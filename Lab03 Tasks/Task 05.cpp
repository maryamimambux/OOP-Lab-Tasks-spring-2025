// Task 05

#include <iostream>
using namespace std;

class GroceryStore {
public:
    string items[10];  // Store up to 10 items
    double prices[10];
    int itemCount;

    // Constructor to initialize item count
    GroceryStore() {
        itemCount = 0;
    }

    // Method to add new items
    void addItem() {
        if (itemCount < 10) {
            cout << "Enter item name: ";
            cin >> items[itemCount];
            cout << "Enter price: ";
            cin >> prices[itemCount];
            itemCount++;
            cout << "Item added successfully!\n";
        } else {
            cout << "Inventory is full!\n";
        }
    }

    // Method to update item price
    void updatePrice() {
        string name;
        cout << "Enter item name to update price: ";
        cin >> name;

        for (int i = 0; i < itemCount; i++) {
            if (items[i] == name) {
                cout << "Enter new price: ";
                cin >> prices[i];
                cout << "Price updated successfully!\n";
                return;
            }
        }
        cout << "Item not found!\n";
    }

    // Method to view inventory
    void viewInventory() {
        if (itemCount == 0) {
            cout << "Inventory is empty!\n";
            return;
        }

        cout << "\n--- Inventory ---\n";
        for (int i = 0; i < itemCount; i++) {
            cout << items[i] << " - Rs." << prices[i] << "\n";
        }
    }

    // Method to generate receipt
    void generateReceipt() {
        double total = 0;
        int qty;
        string name;
        
        cout << "\n--- Generate Receipt ---\n";
        cout << "Enter number of items to buy: ";
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> qty;

            bool found = false;
            for (int j = 0; j < itemCount; j++) {
                if (items[j] == name) {
                    double cost = prices[j] * qty;
                    cout << name << " x " << qty << " = Rs." << cost << "\n";
                    total += cost;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Item not found in inventory!\n";
            }
        }

        cout << "Total Amount: Rs." << total << "\n";
    }
};

int main() {
    GroceryStore store;
    int choice;

    while (true) {
        cout << "\n--- Grocery Store Menu ---\n";
        cout << "1. Add Item\n2. Update Price\n3. View Inventory\n4. Generate Receipt\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: store.addItem(); break;
            case 2: store.updatePrice(); break;
            case 3: store.viewInventory(); break;
            case 4: store.generateReceipt(); break;
            case 5: cout << "Exiting..."; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}

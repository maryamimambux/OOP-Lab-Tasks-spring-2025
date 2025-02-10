// Task 04

#include <iostream>
using namespace std;

class Laptop {
public:
    string brand, model, processor;
    double ram, storage;
    bool isOn;  

    // Default Constructor
    Laptop() {
        isOn = false;  
    }

    // Parameterized Constructor
    Laptop(string brand, string model, string processor, double ram, double storage) {
        this->brand = brand;
        this->model = model;
        this->processor = processor;
        this->ram = ram;
        this->storage = storage;
        isOn = false;  
    }

    // Method to turn on the laptop
    void turnOn() { 
        if (!isOn) { // Change state only if it's OFF
            isOn = true;
            cout << brand << " " << model << " is now ON.\n";
        } else {
            cout << brand << " " << model << " is already ON.\n";
        }
    }

    // Method to turn off the laptop
    void turnOff() { 
        if (isOn) { // Change state only if it's ON
            isOn = false;
            cout << brand << " " << model << " is now OFF.\n";
        } else {
            cout << brand << " " << model << " is already OFF.\n";
        }
    }

    // Method to check laptop state
    void state() {
        if (isOn) 
            cout << brand << " " << model << " is ON.\n";
        else 
            cout << brand << " " << model << " is OFF.\n";
    }

    // Method to run a program
    void runProgram() {  
        if (!isOn) { // Check if laptop is ON
            cout << "Error: " << brand << " " << model << " is OFF. Please turn it ON first.\n";
            return;
        }

        if (ram < 4 || storage < 100) { // Check system requirements
            cout << "Error: " << brand << " " << model << " does not meet the minimum requirements to run the program.\n";
            return;
        }

        cout << brand << " " << model << " is running the program successfully!\n";
    }

    // Method to enter laptop details
    void enterDetails() {
        cin.ignore();
        cout << "Enter Brand: ";
        getline(cin, brand);
        cout << "Enter Model: ";
        getline(cin, model);
        cout << "Enter Processor: ";
        getline(cin, processor);
        cout << "Enter RAM (GB): ";
        cin >> ram;
        cout << "Enter Storage (GB): ";
        cin >> storage;
    }

    // Method to display specifications
    void displaySpecifications() {
        cout << "\nLaptop Specifications:\n";
        cout << "Brand: " << brand << "\nModel: " << model << "\nProcessor: " << processor
             << "\nRAM: " << ram << " GB\nStorage: " << storage << " GB\n";
    }
};

// Function to compare two laptops
void compareLaptops(Laptop L1, Laptop L2) {
    cout << "\nComparison Results:\n";

    // RAM Comparison
    if (L1.ram > L2.ram)
        cout << L1.brand << " " << L1.model << " has more RAM.\n";
    else if (L2.ram > L1.ram)
        cout << L2.brand << " " << L2.model << " has more RAM.\n";
    else
        cout << "Both laptops have the same RAM size.\n";

    // Storage Comparison
    if (L1.storage > L2.storage)
        cout << L1.brand << " " << L1.model << " has more Storage.\n";
    else if (L2.storage > L1.storage)
        cout << L2.brand << " " << L2.model << " has more Storage.\n";
    else
        cout << "Both laptops have the same Storage.\n";
}

int main() {
    Laptop bilalsLaptop, ayeshasLaptop;

    // Entering laptop details
    cout << "Bilal, enter details of your laptop:\n";
    bilalsLaptop.enterDetails();
    cout << "\nAyesha, enter details of your laptop:\n";
    ayeshasLaptop.enterDetails();

    // Turning on laptops
    bilalsLaptop.turnOn(); 
    ayeshasLaptop.turnOn();  

    // Running programs
    bilalsLaptop.runProgram(); 
    ayeshasLaptop.runProgram();  

    // Comparing laptops
    compareLaptops(bilalsLaptop, ayeshasLaptop);

    return 0;
}
 
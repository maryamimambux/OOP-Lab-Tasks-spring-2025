#include <iostream>
using namespace std;
 
class Vehicle {
protected:
    string model;
    double rate;

public:
    Vehicle(string m = "Unknown", double r = 0.0) : model(m), rate(r) {} 

    virtual double getDailyRate() const = 0;   
    virtual void displayDetails() const = 0;    

    virtual ~Vehicle() {}
};

 
class Car : public Vehicle {
public:
    Car(string m, double r) : Vehicle(m, r) {}

 
    double getDailyRate() const override {
        return rate;
    }

 
    void displayDetails() const override {
        cout << "Car Details:\n";
        cout << "Model: " << model << endl;
        cout << "Rate: $" << getDailyRate() << endl;  
    }
};

 
class Bike : public Vehicle {
public:
    Bike(string m, double r) : Vehicle(m, r) {}

  
    double getDailyRate() const override {
        return rate;
    }

 
    void displayDetails() const override {
        cout << "Bike Details:\n";
        cout << "Model: " << model << endl;
        cout << "Rate: $" << getDailyRate() << endl;  
    }
};

int main() {
    Vehicle* vehicle1;
    Vehicle* vehicle2;

    Car car("Toyota", 50);
    Bike bike("Yamaha", 65);

    vehicle1 = &car;
    vehicle1->displayDetails();
    
 
    double currentRate1 = vehicle1->getDailyRate(); 
    cout << "Daily Rate: $" << currentRate1 << endl;

    cout << endl;

    vehicle2 = &bike;
    vehicle2->displayDetails();
    

    double currentRate2 = vehicle2->getDailyRate(); 
    cout << "Daily Rate: $" << currentRate2 << endl;

    return 0;
}

// Task 01
#include <iostream>
using namespace std;

class Markerpens {

 public:
 string brand;
 string color;
 int inkLevel;
 bool refillability;
 
 Markerpens () {}
 
 Markerpens (string brand, string color, int inkLevel, bool refillability) {
 this->brand = brand;
 this->color = color;
 this->inkLevel = inkLevel;
 this->refillability = refillability;
 }


 void write(int amount) {
        if (inkLevel >= amount) {
            inkLevel -= amount;
            cout << "Wrote with " << color << " pen. Remaining ink level: " << inkLevel << "%" << endl;
        } else {
            cout << "Not enough ink! Please refill the pen." << endl;
        }
    }
    
    void refill () {
     if (refillability) {
     if (inkLevel < 100) {
     inkLevel = 100;
 }
 else {
 cout << "The pen is already filled!" << endl;
 }
 }
 else {
 cout << "The pen is not refillable!" << endl;
 }
 }

 void check_status () {
 cout << "\nPen Brand: " << brand << endl;
 cout << "Pen Color: " << color << endl;
 cout << "Pen Ink level: " << inkLevel << endl;
 cout << "Refillable: " << (refillability?"Yes.": "No.") << endl;

 }
 
 void penDetails (Markerpens &pen) {
 	cout << "Brand: ";
 	getline (cin, pen.brand);
 	cout << "Color: ";
 	getline (cin, pen.color);
 	cout << "Ink Level: ";
 	cin >> pen.inkLevel;
 	cout << "Refillability (0 or 1): ";
 	cin >> pen.refillability;
 }
 
};


int main() {

 int amount;	
 Markerpens pen1;
 cout << "Enter pen details: \n" << endl;
 pen1.penDetails(pen1); 
 
 
 pen1.check_status();
 cout << endl;

 cout << "Enter amount of ink level used: ";
 cin >> amount;
 pen1.write(amount);
 cout << endl;

 // Checking status after writing
 pen1.check_status();
 cout << endl;

 // Refilling the marker
 pen1.refill(); 
 
 // Checking status after refilling
 pen1.check_status();
 

 pen1.refill();
 cout << endl;

 return 0;
}


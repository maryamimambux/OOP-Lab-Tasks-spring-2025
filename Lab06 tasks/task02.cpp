#include <iostream>
using namespace std;

class Vehicle {
	protected:
		string brand;
		int speed;
		
	public: 
		Vehicle (string brand, int speed) : brand(brand), speed(speed) {}
		
		virtual void displayDetails() {
			cout << "Brand: " << brand << endl;
			cout << "Speed: " << speed << endl;
		}
};

class Car : public Vehicle {
	public:
		int seats; 
		
		Car (string brand, int speed, int seats)
		: Vehicle (brand, speed), seats(seats) {}
		
		void displayDetails() override {
			cout << "Brand: " << brand << endl;
			cout << "Speed: " << speed << endl;
			cout << "Seats: " << seats << endl;
		}
		
};

class  ElectricCar : public Car {
	public:
		int batteryLife; 
		
		ElectricCar (string brand, int speed, int seats, int batteryLife)
		: Car (brand, speed, seats), batteryLife(batteryLife) {}
		
		void displayDetails() override {
			cout << "Brand: " << brand << endl;
			cout << "Speed: " << speed << " mph" << endl;
			cout << "Seats: " << seats << endl;
			cout << "Battery Life: " << batteryLife << " hr"<< endl;
		}
		
};

int main() {
	
	ElectricCar ev ("Tesla", 120, 5, 48);  
	
	ev.displayDetails(); 
	
	return 0;
}
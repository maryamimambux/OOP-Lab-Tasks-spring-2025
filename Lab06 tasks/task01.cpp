#include <iostream>
using namespace std;

class Employee {
	public:
		string name;
		float salary;
	
		Employee (string n, float s) : name(n), salary(s) {}
		
		virtual void displayDetails() {
			cout << "Name: " << name << endl;
			cout << "Salary: " << salary << " $" << endl;
		}
		
};

class Manager : public Employee {
	public:
		float bonus; 
		
		Manager (string n, float s, float b)
		: Employee (n, s), bonus(b) {}
		
		void displayDetails() override {
			Employee :: displayDetails();
			cout << "Bonus: " << bonus << " $"  << endl;
		} 
};

int main() {

	Manager m ("Maryam", 12450.98, 500.45);
 
	m.displayDetails();

	return 0;
}
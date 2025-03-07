#include <iostream>
using namespace std;

class Account { // Parent Class  
		
	public: 
		int accountNumber;
		float balance;
		
		Account (int accountNumber, float balance)
		: accountNumber(accountNumber), balance(balance) {}
		
		virtual void displayDetails() {
			cout << "Account Number: " << accountNumber << endl;
			cout << "Balance: " << balance << endl;
		}
};

class SavingsAccount : public Account { // Child Class 01
	public:
		float interestRate; 
		
		SavingsAccount (int accountNumber, float balance, float interestRate)
		: Account (accountNumber, balance), interestRate(interestRate) {}
		
		void displayDetails() override {
			cout << "Account Number: " << accountNumber << endl;
			cout << "Balance: " << balance << endl;
			cout << "Interest Rate: " << interestRate << " %" << endl; 
		}
		
};

class CheckingAccount : public Account { // Child Class 02
	public:
		float overdraftLimit; 
		
		CheckingAccount (int accountNumber, float balance, float overdraftLimit)
		: Account (accountNumber, balance), overdraftLimit(overdraftLimit) {}
		
		void displayDetails() override {
			cout << "Account Number: " << accountNumber << endl;
			cout << "Balance: " << balance << " USD" << endl;
			cout << "Overdraft Limit: " << overdraftLimit << " USD" << endl; 
		}
		
}; 

int main() {
	
	SavingsAccount sa (45522, 125000, 0.61);
	
	CheckingAccount ca (45533, 136000, 55); 
	
	Account* acc1 = &sa;
	Account* acc2 = &ca;
	
	acc1->displayDetails();
	cout << endl;
	acc2->displayDetails();
	
	
	return 0;
}
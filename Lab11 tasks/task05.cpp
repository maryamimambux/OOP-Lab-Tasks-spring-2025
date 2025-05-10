/*
============================== Task 05 ==============================
 
Create a template class BankAccount<T> where T is the currency type
(e.g., double, int). Throw an Insufficient FundsException (class) if
a withdrawal exceeds the balance. Include the deficit amount in the
exception message. 

Requirements: 
withdraw(T amount) throws the exception if amount > balance. 
Catch the exception and display the deficit. 

Sample Input/Output: 
Balance: $500.00 
Withdraw $600: Insufficient Funds Exception 
Deficit: $100.00

=====================================================================
*/ 

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <type_traits>
#include <string>

using namespace std;

class InsufficiantFundException : public exception {
	string msg;
	public:
	InsufficiantFundException (string s) : msg(s) {}
	const char* what() const noexcept override {
		return msg.c_str();
	} 
};

template <typename T>
class BankAccount {
	T balance;
	
	public:
	BankAccount(T balance=0) : balance(balance) {}
	
	void setBalance() {cout << "Balance: $"; cin >> balance;}
	T getBalance() { return balance; }
	
	void withdraw(T amount) {
		if (amount > balance) {
			throw InsufficiantFundException ("InsufficiantFundException - Deficit: $");
		}
		balance -= amount;
	}	
};

int main() {
	
	BankAccount<double> account;
	account.setBalance();
	
	double amount;
	cout << "Withdraw: ";
	cin >> amount;
		
	try {
		account.withdraw(amount);
	}
	catch(InsufficiantFundException& ex) {
		cout << "Withdraw $" << amount << ": " << ex.what() << amount-account.getBalance() << endl;
	}
	
	return 0;
}

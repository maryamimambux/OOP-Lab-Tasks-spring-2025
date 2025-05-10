/*
============================== Task 04 ==============================

Write a template function sqrt(T num) that computes the square root. 
Throw:
NegativeNumberException (class) if num is negative (for 
InvalidTypeException (class) if T is not numeric (e.g., string)

Requirements: 
Use typeid or template specialization for type checks. Handle both
exceptions in main(). 

Sample Input/Output: 
sqrt(-4): Negative NumberException Input must be non-negative! -
sqrt("hello"): InvalidTypeException Non-numeric type detected!

=====================================================================
*/

#include <iostream>
#include <stdexcept>
#include <exception>
#include <fstream>
#include <string>
#include <cmath>

using namespace std; 

class NegativeNumberException : public exception {
	private:
	string str;
	public:
	NegativeNumberException(const string& s) : str(s) {}
	
	const char* what() const noexcept override {
		return str.c_str(); // converts std::string into the required const char* .
	} 
};

class InvalidTypeException : public exception {
	private:
	string str;
	public:
	InvalidTypeException(const string& s) : str(s) {}
	
	const char* what() const noexcept override {
		return str.c_str();  
	} 
}; 

template <typename T>
void sqrrt (T num) {
	
	if (!cin) {
		throw NegativeNumberException("InvalidTypeException - Non-numeric type detected!");
	}
	if (num < 0) {
		throw InvalidTypeException("NegativeNumberException - Input must be non-negative!");
	}
	cout << "Square Root: " << sqrt(num) << endl;

}

// Helper function to get input and handle exceptions
void handleSquareRoot() {
    cout << "Enter a number to find its square root: ";
	double number;
	cin >> number;
	
	try {
		sqrrt(number);
	}
	catch (const NegativeNumberException& e) {
		cerr << e.what() << endl;	
	}
	catch (const InvalidTypeException& e) {
		cerr << e.what() << endl;	
	}
}

int main() {
    handleSquareRoot();
    handleSquareRoot(); // Reuse
    return 0;
}

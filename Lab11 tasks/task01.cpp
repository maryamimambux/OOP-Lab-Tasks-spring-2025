/*
============================== Task 01 ==============================

Create a custom exception class InvalidValueException that inherits
from std::exception. Override the what() method to return a meaningful
error message. Use this exception in a function validateAge (int age)
that throws it if age is negative or greater than 120. 

Requirements: 
Inherit from sto::exception. 
Use const char* what() const noexcept override to provide error messages. 
Handle the exception in main(). 

Sample Input/Output: 
Enter age: -5 
Error: InvalidValueException Age cannot be negative or exceed 120.

=====================================================================
*/

#include <iostream>
#include <stdexcept>
#include <exception>

class InvalidValueException : public std::exception {
	private:
	std::string str;
	public:
	InvalidValueException(const std::string& s) : str(s) {}
	
	const char* what() const noexcept override {
		return str.c_str(); // converts std::string into the required const char* .
	} 
};

class AgeValidator {
public:

    static void validate(int age) {
        if (age < 0 || age > 120) {
            throw InvalidValueException("InvalidValueException - Age cannot be negative or exceed 120.");
        }
    }

};


int main() {
	int age;
    std::cout << "Enter your age: ";

    if (!(std::cin >> age)) {
        std::cerr << "Invalid input. Please enter a numeric age value.\n";
        return 1;
    }
	
	try {
        AgeValidator::validate(age);
        std::cout << "Age is valid: " << age << " years.\n";
    }
    catch (const InvalidValueException& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    } 
    
	return 0;
}
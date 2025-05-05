//=================== TASK 05 =================

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
	
	void setBalance() {cout << "Balance: "; cin >> balance;}
	T getBalance() { return balance; }
	
	void withdraw(T amount) {
		if (amount > balance) {
			throw InsufficiantFundException ("InsufficiantFundException - Deficit: ");
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
		cout << "Withdraw " << amount << ": " << ex.what() << amount-account.getBalance() << endl;
	}
	
	return 0;
}


/*
//=================== TASK 04 =================

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <type_traits>
#include <string>

using namespace std;

class NegativeNumberException : public exception {
    string message;
public:
    NegativeNumberException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidTypeException : public exception {
    string message;
public:
    InvalidTypeException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
void computeSqrt(T num) {
if constexpr (!is_arithmetic<T>::value) {
        throw InvalidTypeException("sqrt(???) : InvalidTypeException - Non-numeric type detected!");
    } else {
        if (num < 0) {
            throw NegativeNumberException("sqrt(" + to_string(num) + "): NegativeNumberException - Input must be non-negative!");
        }
        cout << "Square Root: " << sqrt(static_cast<double>(num)) << endl;
    }
}

int main() {
    try {
        computeSqrt(-4);  // negative int
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    try {
        computeSqrt(string("hello"));  // non-numeric
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    try {
        computeSqrt(16.0);  // valid double
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
*/

/*
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

int main() { 

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
	
	return 0;
}
*/

/*
//=================== TASK 03 =============================

#include <iostream>
#include <stdexcept>
#include <exception>
#include <fstream>
#include <string>

using namespace std;

class FileException : public exception {
	private:
	string str;
	
	public:
	FileException(string s) : str(s) {}
	
	virtual const char* what() const noexcept override {
		return str.c_str();
	}
	
};

class FileNotFoundException : public FileException { 
	public:
	FileNotFoundException(string& filename)
	: FileException( "FileNotFoundException - File " + filename + " not found.") {}
 	
};

class PermissionDeniedException : public FileException { 
	public:
	PermissionDeniedException(string& filename)
	: FileException( "PermissionDeniedException - Access denied to file" + filename + ".") {}
 			
}; 
		
void readFile(string filename) {
	
	if (filename == "missing.txt") {
        throw FileNotFoundException(filename);
    } else if (filename == "secret.txt") {
        throw PermissionDeniedException(filename);
    } else {
        ifstream file(filename);
        if (!file.is_open()) {
            throw FileException("FileException - Unknown error opening file '" + filename + "'.");
        }
        
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
			 
}

int main() {
	
	string fileToRead = "secret.txt"; // Try "missing.txt", "data.txt"

    try {
        cout << "Reading '" << fileToRead << "':\n";
        readFile(fileToRead);
    }
    catch (const FileNotFoundException& e) {
        cerr << e.what() << endl;
    }
    catch (const PermissionDeniedException& e) {
        cerr << e.what() << endl;
    }
    catch (const FileException& e) {
        cerr << e.what() << endl;
    } 
	return 0;
}
*/


/*
//=================== TASK 02 =============================

#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

class StackOverflowException : public exception {
	private:
	string str;
	
	public:
	StackOverflowException(string s) : str(s) {}
	
	const char* what() const noexcept override {
		return str.c_str();
	}	
	
};

class StackUnderflowException : public exception {
	
	private:
	string str;
	
	public:
	StackUnderflowException(string s) : str(s) {}
	
	const char* what() const noexcept override {
		return str.c_str();
	}
	
};

template <typename T, int SIZE=2>

class Stack {
	private:
	T data[SIZE];
	int index;
		
	public:
	Stack(): index(-1) {}
	
	int getIndex() { return index; }	
	
	void push(const T& value) { 
		if(index >= SIZE-1) {
			throw StackOverflowException("StackOverflowException - Stack is full!");
		}
		data[++index] = value; 
	}
	
	void pop() { 
		if (index < 0) {
			throw StackUnderflowException("StackUnderflowException - Stack is empty!");
		}
		--index; 
	}	
};

int main() {
	
	Stack<int> stack;
	
	try {
		// stack.pop();  
		stack.push(0);  
		stack.push(5);  
		stack.push(73);  
	}                           
	
	catch(const StackUnderflowException& under) {
		cerr << "Popping from an empty stack: " << under.what() << endl;
	}
	
	catch(const StackOverflowException& over) {
		cerr << "Popping from an empty stack: " << over.what() << endl;
	}
	
	return 0;
}
*/

/*
//=================== TASK 01 =============================

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


*/




/*

#include <iostream>
#include <stdexcept>
#include <limits>

//std::exception
//  +-- std::logic_error
//        +-- std::invalid_argument

class AgeValidator {
public:
    static void validate(int age) {
        if (age < 0) {
            throw std::invalid_argument("Age cannot be negative.");
        }
        if (age == 0) {
            throw std::invalid_argument("Age cannot be zero.");
        }
        if (age > 120) {
            throw std::out_of_range("Age exceeds realistic human limits.");
        }
    }
};

int main() {
    std::cout << "=== Age Validation System ===\n";

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
    catch (const std::invalid_argument& ex) {
        std::cerr << "Input Error: " << ex.what() << "\n";
    }
    catch (const std::out_of_range& ex) {
        std::cerr << "Range Error: " << ex.what() << "\n";
    }
    catch (...) {
        std::cerr << "An unexpected error occurred.\n";
    }

    std::cout << "==============================\n";
    return 0;
}

*/

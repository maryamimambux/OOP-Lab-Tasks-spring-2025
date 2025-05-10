/*
============================== Task 02 ==============================

Create a template class Stack<T> with methods push() and poo().
Throw: a fixed capacity. Implement 
StackOverflowException (class) if pushing to a full stack. 
StackUnderflowException (class) if popping from an empty stack. 

Requirements: 
Both exceptions inherit from std::exception and override what(). 
Include error details (e.g., "Stack is full!"). 
Demonstrate exceptions in main(). 

Sample Input/Output: 
Pushing to a full stack: StackOverflowException - Stack is full! 
Popping from an empty stack: StackUnderflowException Stack is empty!

=====================================================================
*/

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
		stack.pop(); 
	}                           
	catch(const StackUnderflowException& under) {
		cerr << "Popping from an empty stack: " << under.what() << endl;
	}
	
    try {  
		stack.push(0);  
		stack.push(5);  
		stack.push(73);  
	} 
	catch(const StackOverflowException& over) {
		cerr << "Pushing to a full stack: " << over.what() << endl;
	}
	
	return 0;
}
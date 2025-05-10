/*
============================== Task 03 ==============================

Create an exception hierarchy: 
Base class: FileException (with what()). 
Derived classes: FileNotFoundException, PermissionDeniedException. 
Write a function readFile(const string& filename) that throws these 
exceptions based on file issues. 

Requirements: 
Use polymorphism to catch base class FileException. 
Handle specific exceptions in separate catch blocks. 

Sample Input/Output: 
Reading 'secret.txt': PermissionDeniedException Access denied!

=====================================================================
*/

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
	: FileException( "FileNotFoundException - File not found!") {}
 	
};

class PermissionDeniedException : public FileException { 
	public:
	PermissionDeniedException(string& filename)
	: FileException( "PermissionDeniedException - Access denied!") {}
 			
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
	
	string file1ToRead = "secret.txt"; // Try "missing.txt", "data.txt"
    string file2ToRead = "missing.txt";

    try {
        cout << "Reading '" << file1ToRead << "':";
        readFile(file1ToRead);
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

    try {
        cout << "Reading '" << file2ToRead << "':";
        readFile(file2ToRead);
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
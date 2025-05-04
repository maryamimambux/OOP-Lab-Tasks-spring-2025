/*
============================================================

" Task 01: Reading the Data File "
Open the provided data file (named "vehicles.txt") 
and read through it line by line. 

Task: Write C++ code to declare an input file stream object
(ifstrean), open the specified file. Include a check to make
sure the file opened successfully. If it fails, print
an error message. Then, use a loop with getline to read each
full line from the file into a std::string variable.
(For simplicity, you can skip comment lines starting with '' and
empty lines if desired, but the core task is opening and
reading line by line). 

Concepts Covered: File 1/0 (ifstream, open, is open, getline), 
std::string

============================================================
*/


#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

class File_Reader {
    private:
    ifstream fin;
    string fileName;

    public:
    File_Reader(string name) : fileName(name) {
        fin.open(fileName);
        if (!fin.is_open()) {
            throw runtime_error ("Error: Unable to open file " + name);
        }
    }

    void read() {
        if (!fin.is_open()) {
            throw runtime_error ("Error: Unable to open file");
            return;
        }
        
        string line;
        cout << endl;
        while(getline(fin, line)) {

            // Skip empty lines
            if(line.empty()) {
                continue;
            }

            // Skip comment lines starting with "//"
            if (line.substr(0, 2) == "//") {
                continue;
            }

            cout << line << endl;
        }

        cout << endl;
    }

};

int main() {
    
    File_Reader file ("vehicles.txt");
    file.read();

    return 0;
}

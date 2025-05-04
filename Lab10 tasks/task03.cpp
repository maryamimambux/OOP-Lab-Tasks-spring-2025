/*
============================================================

" Task 03: Converting String Data to Numbers "
Goal: Convert the string representation of the vehicle's
year into an integer. 

Task: Take the std::string variable holding the Year value
(extracted in Scenario 2). Use the stoi function to convert
this string into an integer. Declare an int variable to store
the result. If the conversion fails (though the problem
simplifies error handling, mention the function's purpose),
stoi would normally throw an exception, but for this task,
assume valid input for conversion or simply note that stoi
performs this conversion. Print the resulting integer value. 

Concepts Covered: stoi, std::string, int.

============================================================
*/


#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
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
            return;
        }
    }

    void read() {
        if (!fin.is_open()) {
            throw runtime_error ("Error: Unable to open file"); 
        }
        
        string line;
        cout << endl;
        while(getline(fin, line)) {
            if (line.empty() || line.substr(0, 2) == "//") {
                continue; // Skip empty lines or comment lines
            }

            istringstream iss(line);
            
            string field;
            int fieldNumber = 0;

            while (std::getline(iss, field, ',')) {
                if (fieldNumber == 3) {
                    int year = stoi(field);
                    std::cout << "Year: " << year << std::endl;
                }
                fieldNumber++;
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    
    File_Reader file ("vehicles.txt");
    file.read();

    return 0;
}

 
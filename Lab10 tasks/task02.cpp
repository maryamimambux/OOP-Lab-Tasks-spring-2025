/*
============================================================

" Task 02: Basic Data Extraction with sstream "
 
Take a single line that has been read from the file and split
it into its main parts using sstream. 

Task: Inside the loop from Scenario 1, after reading a line into
a std::string variable, create an istringstream object initialized
with that line. Use getline repeatedly on the istringstream with
the comma character (,) as the delimiter to extract the values
for Type, ID, Name, Year (as a string), ExtraData (as a string),
and Certification into separate std::string variables. Print
these extracted string values to verify your parsing. 

Concepts Covered: sstream (istringstream), getline (with sstream
and delimiter), std::string.

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

            istringstream extractData(line);
            string Type, ID, Name, Year, extraData, Certification;

            getline(extractData, Type, ',');
            getline(extractData, ID, ',');
            getline(extractData, Name, ',');
            getline(extractData, Year, ',');
            getline(extractData, extraData, ',');
            getline(extractData, Certification, ','); 

            cout << " Type: " <<Type << endl << " ID: " << ID << endl << " Name: " << Name << endl << " Year: " << Year << endl << " Extra Data: " << extraData << endl << " Certification: " << Certification << endl;
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

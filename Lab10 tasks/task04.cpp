
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

        while(getline(fin,line)) {
            
            if(!line.empty() && line[0] != '/') {

                istringstream extract(line);
                string Type, ID, Name, Year, extraData, Certification;
                getline(extract, Type, ',');
                getline(extract, ID, ',');
                getline(extract, Name, ',');
                getline(extract, Year, ',');
                getline(extract, extraData, ',');
                getline(extract, Certification, ',');

                int intYear = stoi(Year);

                cout << "Type: " <<Type << ", ID: " << ID << ", Name: " << Name << ", Year: " << intYear << ", Extra Data: " << extraData << ", Certification: " << Certification << endl;

                if(Type == "AutonomousCar") {

                    size_t pos = extraData.find(':');
                    if (pos != string::npos) {
                        float num = stof(extraData.substr(pos + 1));
                        cout << "SW: " << num << endl;
                    }
                    

                } else if (Type == "ElectricVehicle") {

                    size_t pos = extraData.find(':');
                    if(pos != string::npos) {
                        int batteryCapacity = stoi(extraData.substr(pos + 1));
                        cout << "Battery Capacity : " << batteryCapacity << endl;
                    }
                } 

            }
            
        }
    }

};

int main() {
    
    File_Reader file ("vehicles.txt");
    file.read();

    return 0;
}

 

// #include <iostream>
// #include <fstream>
// #include <sstream>
// using namespace std;

// int main() {


//     ifstream file;

//     file.open("vehicles.txt");

//     if(!file.is_open()) {
//         cout << "Failed to open file"<< endl;
//         return 1;
//     }

//     string line;
//     while(getline(file,line)) {
//         if(!line.empty() && line[0] != '/') {

//             istringstream extract(line);
//             string Type, ID, Name, Year, extraData, Certification;
//             getline(extract, Type, ',');
//             getline(extract, ID, ',');
//             getline(extract, Name, ',');
//             getline(extract, Year, ',');
//             getline(extract, extraData, ',');
//             getline(extract, Certification, ',');

//             int intYear = stoi(Year);

//             cout << "Type: " <<Type << ", ID: " << ID << ", Name: " << Name << ", Year: " << intYear << ", Extra Data: " << extraData << ", Certification: " << Certification << endl;

//             if(Type == "AutonomousCar") {

//                 size_t pos = extraData.find(':');
//                 if (pos != string::npos) {
//                     float num = stof(extraData.substr(pos + 1));
//                     cout << "SW: " << num << endl;
//                 }
                

//             } else if (Type == "ElectricVehicle") {

//                 size_t pos = extraData.find(':');
//                 if(pos != string::npos) {
//                     int batteryCapacity = stoi(extraData.substr(pos + 1));
//                     cout << "Battery Capacity : " << batteryCapacity << endl;
//                 }
//             } 

//         }
        
//     }

//     file.close();

// }
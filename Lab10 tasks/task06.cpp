#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem {

    public:
        int itemId;
        char itemName[20];
        InventoryItem(int id, string name) : itemId(id) {
            strcpy(itemName, name.c_str()); 
        }

};

int main() {

    ofstream fout;
    fout.open("inventory.dat", ios::binary);

    InventoryItem item = {1, "Milk"};

    fout.write((char*)&item, sizeof(item));

    fout.close();

    ifstream fin;
    fin.open("inventory.dat", ios::binary);

    InventoryItem readItem(0, ""); 
    
    fin.read((char*)&item, sizeof(item));

    cout << "ID: " << item.itemId << ", Name: " << item.itemName << endl;

    fin.close();

}
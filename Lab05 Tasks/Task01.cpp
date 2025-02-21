#include <iostream>
using namespace std;

class CarRental
{
public:
    int *regNo;
    string modelName;
    string ownerName;

    CarRental()
    {
        regNo = new int(0);
        modelName = "Unknown";
        ownerName = "Unknown";
    }

    CarRental(int regNo, string modelName, string ownerName)
    {
        this->modelName = modelName;
        this->ownerName = ownerName;
        this->regNo = new int(regNo);
    }

    CarRental(const CarRental &obj)
    {
        regNo = new int(*obj.regNo);
        modelName = obj.modelName;
        ownerName = obj.ownerName;  
    }

    void getName(string name)
    {
        ownerName = name;
    }

    void displayCarDetails()
    {
        cout << "\nCar Details: " << endl;
        cout << "Registration Number: " << *regNo << endl;
        cout << "Model Name: " << modelName << endl;
        cout << "Owner Name: " << ownerName << endl;
    }
    
    ~CarRental() {
	    delete regNo;
	}
    
};

int main()
{
    CarRental *car1 = new CarRental(101, "Sedan", "Imam Bux");

    CarRental car2(*car1);

    car2.getName("Hamid");

    car1->displayCarDetails();
    car2.displayCarDetails();

    return 0;
}
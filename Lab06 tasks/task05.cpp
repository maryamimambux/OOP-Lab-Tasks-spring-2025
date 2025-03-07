#include <iostream>
using namespace std;

class Device { // Parent Class  
public: 
    int deviceID;
    bool status;

    Device(int deviceID, bool status)
        : deviceID(deviceID), status(status) {}

    virtual void displayDetails() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : public Device { // Child Class 01
public:
    float screenSize; 

    SmartPhone(int deviceID, bool status, float screenSize)
        : Device(deviceID, status), screenSize(screenSize) {}

    void displayDetails() override {
        cout << "--------------------" << endl;
        cout << "SmartPhone Details:\n";
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : public Device { // Child Class 02
public:
    bool heartRateMonitor; 

    SmartWatch(int deviceID, bool status, bool heartRateMonitor)
        : Device(deviceID, status), heartRateMonitor(heartRateMonitor) {}

    void displayDetails() override {
        cout << "--------------------" << endl;
        cout << "SmartWatch Details:\n";
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "On" : "Off") << endl;
    }
};

class SmartWearable : public Device { // Combined SmartPhone + SmartWatch
public:
    float screenSize;
    bool heartRateMonitor;
    int stepCounter; 

    SmartWearable(int deviceID, bool status, float screenSize, bool heartRateMonitor, int stepCounter)
        : Device(deviceID, status), screenSize(screenSize), heartRateMonitor(heartRateMonitor), stepCounter(stepCounter) {}

    void displayDetails() override {
        cout << "--------------------" << endl;
        cout << "SmartWearable Details:\n";
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "On" : "Off") << endl;
        cout << "Step Counter: " << stepCounter << " steps" << endl   << endl;
    }
};

int main() {
    SmartWearable wearable(1001, true, 6.5, true, 15000);

    wearable.displayDetails();

    return 0;
}
 
#include <iostream> 
using namespace std;

class SmartDevice {
    protected:
    bool currentStatus;

    public:
     
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool getStatus() = 0;

    virtual ~SmartDevice() {}

};

class LightBulb : public SmartDevice {
    private: 
    bool isOn;
    int brightness;

    public:
    LightBulb (bool on, int bright ) : isOn(on), brightness(bright) {}

    void turnOn() { 
        if (isOn) {
            cout << "Bulb Turned On." << endl;
        }
        else {
            isOn = true;
            cout << "Bulb Turned On." << endl;
        }
    }
    void turnOff() {
        if (isOn) {
            isOn = false;
            cout << "Bulb Turned Off." << endl;
        }
        else {
            cout << "Bulb Turned Off." << endl;
        }
    }

    bool getStatus() {
        if (isOn) { return true; }
        else { return false; } 
    }
};

class Thermostat : public SmartDevice {
    private: 
    bool isOn;
    double temperature;

    public:
    Thermostat (bool on, int temp ) : isOn(on), temperature(temp) {}

    void turnOn() { 
        if (isOn) {
            cout << "Thermostat Turned On." << endl;
        }
        else {
            isOn = true;
            cout << "Thermostat  Turned On." << endl;
        }
    }
    void turnOff() {
        if (isOn) {
            isOn = false;
            cout << "Thermostat  Turned Off." << endl;
        }
        else {
            cout << "Thermostat  Turned Off." << endl;
        }
    } 

    bool getStatus() {
        if (isOn) { return true; }
        else { return false; } 
    }

};
 

int main() { 

    LightBulb bulb(true, 20);
    Thermostat thermo (false, 50); 

    bulb.turnOff();
    if (bulb.getStatus()) {cout <<"Bulb is On.\n";}
    else {cout <<"Bulb is Off.\n";}

    thermo.turnOn();
    if (thermo.getStatus()) {cout <<"Thermostat is On\n";}
    else {cout <<"Thermostat is Off.\n";}
    
    return 0;
}
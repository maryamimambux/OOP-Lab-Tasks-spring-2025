// Transport Management System without STL (vector/map)
// Uses file handling, OOP concepts, custom data structures, exceptions

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>
using namespace std;

// ---------------------- Exception Classes ----------------------------
class BookingException : public exception {
    string message;
public:
    BookingException(const string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

// ---------------------- Abstract User ----------------------------
class User {
protected:
    string name;
    int userID;
    bool paymentStatus;

public:
    User(string name = "", int id = 0, bool paid = false) : name(name), userID(id), paymentStatus(paid) {}
    virtual string getRole() const = 0;
    bool hasPaid() const { return paymentStatus; }
    int getID() const { return userID; }
    virtual float calculateFare(bool isAC) const = 0;
    virtual ~User() {}
};

class Faculty : public User {
public:
    Faculty(string name = "", int id = 0, bool paid = false) : User(name, id, paid) {}
    string getRole() const override { return "Faculty"; }
    float calculateFare(bool isAC) const override {
        return isAC ? 7000 : 5000;
    }
};

class Student : public User {
public:
    Student(string name = "", int id = 0, bool paid = false) : User(name, id, paid) {}
    string getRole() const override { return "Student"; }
    float calculateFare(bool isAC) const override {
        return isAC ? 5000 : 3000;
    }
};

// ---------------------- Driver Class ----------------------------
class Driver {
    string name;
    string license;
public:
    Driver(string n = "", string l = "") : name(n), license(l) {}
    string getName() const { return name; }
    string getLicense() const { return license; }
};

// ---------------------- Route Class ----------------------------
class Route {
    string start;
    string end;
    int distance;
public:
    Route(string s = "", string e = "", int d = 0) : start(s), end(e), distance(d) {}
    bool isLongDistance() const { return distance > 20; }
    string getRouteInfo() const { return start + " to " + end + " (" + to_string(distance) + " km)"; }
};

// ---------------------- Vehicle Class ----------------------------
class Vehicle {
    string vehicleID;
    int capacity;
    bool isAC;
    Driver driver;
    Route route;
    User* seats[52];
    string assignedFor;

public:
    Vehicle(string id = "", int cap = 0, bool ac = false, Driver d = Driver(), Route r = Route(), string role = "") :
        vehicleID(id), capacity(cap), isAC(ac), driver(d), route(r), assignedFor(role) {
        for (int i = 0; i < 52; i++) seats[i] = nullptr;
    }

    string getID() const { return vehicleID; }
    string getAssignedFor() const { return assignedFor; }
    bool getACStatus() const { return isAC; }

    void bookSeat(int seatNo, User* user) {
        if (user->getRole() != assignedFor) throw BookingException("Seat reserved for " + assignedFor);
        if (!user->hasPaid()) throw BookingException("Payment not completed.");
        if (seatNo >= capacity || seats[seatNo] != nullptr) throw BookingException("Seat unavailable.");
        seats[seatNo] = user;
    }

    void displayBookingDetails() const {
        cout << "Vehicle: " << vehicleID << " (" << (isAC ? "AC" : "Non-AC") << ")\n";
        cout << "Driver: " << driver.getName() << ", Route: " << route.getRouteInfo() << "\n";
        cout << "Seats Booked:\n";
        for (int i = 0; i < capacity; ++i) {
            if (seats[i]) cout << "  Seat " << i << " -> User ID: " << seats[i]->getID() << " (" << seats[i]->getRole() << ")\n";
        }
        cout << endl;
    }
};

// ---------------------- Transport Management System ----------------------------
class TransportSystem {
    User* users[100];
    int userCount;
    Vehicle* vehicles[10];
    int vehicleCount;

public:
    TransportSystem() : userCount(0), vehicleCount(0) {}

    void registerUser(User* user) {
        users[userCount++] = user;
    }

    void addVehicle(Vehicle* vehicle) {
        vehicles[vehicleCount++] = vehicle;
    }

    User* findUserByID(int id) {
        for (int i = 0; i < userCount; ++i)
            if (users[i]->getID() == id) return users[i];
        throw BookingException("User not found");
    }

    Vehicle* findVehicleByID(const string& id) {
        for (int i = 0; i < vehicleCount; ++i)
            if (vehicles[i]->getID() == id) return vehicles[i];
        throw BookingException("Vehicle not found");
    }

    void makeBooking(int userID, const string& vehicleID, int seatNo) {
        User* user = findUserByID(userID);
        Vehicle* vehicle = findVehicleByID(vehicleID);
        vehicle->bookSeat(seatNo, user);
        float fare = user->calculateFare(vehicle->getACStatus());
        cout << "Booking successful! Fare: Rs. " << fare << endl;
    }

    void showAllBookings() {
        for (int i = 0; i < vehicleCount; ++i) {
            vehicles[i]->displayBookingDetails();
        }
    }

    ~TransportSystem() {
        for (int i = 0; i < userCount; ++i) delete users[i];
        for (int i = 0; i < vehicleCount; ++i) delete vehicles[i];
    }
};

// ---------------------- Main ----------------------------
int main() {
    TransportSystem system;

    // Drivers
    Driver d1("Ali", "L1234");
    Driver d2("Zain", "Z5678");

    // Routes
    Route r1("Gulshan", "FAST", 15);
    Route r2("Malir", "FAST", 30);

    // Vehicles
    system.addVehicle(new Vehicle("V001", 52, true, d1, r1, "Faculty"));
    system.addVehicle(new Vehicle("V002", 32, false, d2, r2, "Student"));

    // Users
    system.registerUser(new Faculty("Dr. Ahmad", 1, true));
    system.registerUser(new Student("Ali Raza", 2, true));

    try {
        system.makeBooking(1, "V001", 10); // Faculty
        system.makeBooking(2, "V002", 5);  // Student
    } catch (const BookingException& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    system.showAllBookings();

    return 0;
}

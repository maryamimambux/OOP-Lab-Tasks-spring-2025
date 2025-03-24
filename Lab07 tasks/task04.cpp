#include <iostream>
#include <vector>
using namespace std;

class Person {
    protected:
    string name;
    int id;
    string address;
    string phoneNumber;
    string gmail;

    public:
    Person() {}
    Person (string name, int id, string address, string phoneNumber, string gmail)
    : name(name), id(id), address(address), phoneNumber(phoneNumber), gmail(gmail) {};

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Gmail: " << gmail << endl;
    }

    virtual void updateInfo() {
        cout << "New ID: ";
        cin >> id;
        
        cout << "New Name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "New Phone Number: ";
        cin >> phoneNumber;
        
        cout << "New Address: ";
        cin.ignore();  // Fix: Clear the newline before reading address
        getline(cin, address);

        cout << "New Gmail: ";
        cin >> gmail;
    }

    virtual ~Person() {}

};

class Student : public Person {
    private:
    int coursesEnrolled;
    int enrollmentYear;
    double gpa;

    public:
    Student() {}
    Student (string name, int id, string address, string phoneNumber, string gmail, double gpa, int coursesEnrolled, int enrollmentYear )
    : Person(name, id, address, phoneNumber, gmail), gpa(gpa), coursesEnrolled(coursesEnrolled), enrollmentYear(enrollmentYear) {};
    
    string getName() {return name;}

    void displayInfo() {
        Person::displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "GPA: " << gpa << endl;
    }

    void updateInfo() {
        Person::updateInfo();
        cout << "New GPA: " ;
        cin >> gpa;
        cout << "New Courses Enrolled: " ;
        cin >> coursesEnrolled;
        cout << "New Enrollment Year: " ;
        cin >> enrollmentYear;
    }

};


class Professor : public Person {
    private:
    string department;
    vector<string> coursesTaught;
    double salary;

    public:
    Professor (string name, int id, string address, string  phoneNumber, string gmail, string department, vector<string> coursesTaught, double salary )
    : Person(name, id, address, phoneNumber, gmail), department(department), coursesTaught(coursesTaught), salary(salary) {};
    
    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Cources Taught: ";
        for (const string& course : coursesTaught)
            cout << course << "  ";
            cout << endl;
        cout << "Salary: " << salary << endl;
    }

    void updateInfo() {
        Person::updateInfo();
        cout << "New Department: " ;
        cin >> department; 
        cout << "New Salary: " ;
        cin >> salary;
    }

};

class Staff : public Person {
    private:
    string department;
    string position;
    double salary;

    public:
    Staff (string name, int id, string address, string phoneNumber, string gmail, string department, string position, double salary )
    : Person(name, id, address, phoneNumber, gmail), department(department), position(position), salary(salary) {};
    
    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }

    void updateInfo() {
        Person::updateInfo();
        cout << "New Department: " ;
        cin >> department;
        cout << "New Position: " ;
        cin >> position;
        cout << "New Salary: " ;
        cin >> salary;
    }

};
 
class Course {
    private:
    int courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule; 

    public:

    Course (int courseId, string courseName, int credits, string instructor, string schedule )
    : courseId(courseId), courseName(courseName), credits(credits), instructor(instructor), schedule(schedule) {}

    void registerStudent(Student &s) {
        cout << s.getName() << " is registered for " << courseName << " course." << endl;
    }

    void calculateGrades() {

    }

};

int main() {

    Student student ("Maryam", 3011, "Shah Latif Town", "3101654887", "maryamimambux@gmail.com", 3.98, 6, 2024);
    Professor professor ("Dr.Rahim", 2312, "Korangi Karachi", "123-456-888", "muhammad.rahim@gmail.com", "Humanities and Social Sciences", {"DLD", "AP"}, 202500);
    Staff staff("Ali", 2001, "Street-9876 4B Sader Lahore", "777-123-098", "ali.mallah@gmail.com", "Admin", "Manager", 150000);

    Course dld (101, "Digital Logic Design", 3, "Muhammad Rahim", "Monday, Thursday, Friday");
    cout << endl;
    dld.registerStudent(student);

    Person* stuPtr = &student;
    Person* proPtr = &professor;
    Person* staPtr = &staff;


    cout << "\n--- Student Info ---\n";
    stuPtr->displayInfo();

    cout << "\n--- Professor Info ---\n";
    proPtr->displayInfo();

    cout << "\n--- Staff Info ---\n";
    staPtr->displayInfo();

    cout << "\n--- Updating Student Info ---\n";
    stuPtr->updateInfo();

    cout << "\n--- Updated Student Info ---\n";
    stuPtr->displayInfo();

    return 0;
}
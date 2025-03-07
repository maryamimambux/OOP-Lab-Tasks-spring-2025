#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}

    virtual void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : virtual public Person {
public:
    string subject;

    Teacher(string name, int age, string subject)
        : Person(name, age), subject(subject) {}

    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : virtual public Person {
public:
    string researchArea;

    Researcher(string name, int age, string researchArea)
        : Person(name, age), researchArea(researchArea) {}

    void displayDetails() override {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
public:
    int publications;

    Professor(string name, int age, string subject, string researchArea, int publications)
        : Person(name, age), Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}

    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    Professor p("Ali", 34, "Social Sciences", "History", 23);
    p.displayDetails();

    return 0;
}

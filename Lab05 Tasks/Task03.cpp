#include <iostream>
using namespace std;

class Professors{
	
	string name;
	string department;
	
	public:	
	Professors(string name, string department)
		: name(name), department(department) {}	
	void getName(string name){
        this->name = name;
    }
    void getDept(string department){
        this->department = department;
    }
    void display() { 
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
	}
	
};

class University{
	 
	Professors* p1[10]; // AGGRIGATION - Professor can exit depite University
	string uniName;
	int count = 0;
	
	public:
	University(string uniName)
		: uniName(uniName) {}
		
	void addProfessor(Professors *p) {
        if (count < 10) { p1[count++] = p; }
        else { cout << "University is full!" << endl; }
    }
	
	void display() { 
		cout << uniName << " University Detail: \n" << endl;
        for (int i = 0; i < count; i++) {
            cout << "Professor " << i + 1 << ": " << endl;
            p1[i]->display();
            cout << endl;
        }
	}
};


int main() {
	
	Professors p1("Baber", "CS"), p2("Ali", "SE"), p3("Hamid", "DS");
	
	University uni ("FAST NUCES"); 
	
	uni.addProfessor(&p1);
    uni.addProfessor(&p2);
    uni.addProfessor(&p3);
	
	uni.display();
	
	return 0;
}
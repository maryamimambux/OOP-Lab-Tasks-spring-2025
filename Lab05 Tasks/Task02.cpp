#include <iostream>
using namespace std;

class Patient {
	public:
		int id;
		string name;
		string* testResults;  // Dynamically allocated array of strings
    	int numTests;
		
	Patient (int id, string name, int numTests, string results[])
		: id(id), name(name), numTests(numTests) {
			testResults = new string[numTests]; 
			
	        for (int i = 0; i < numTests; i++) {
	            testResults[i] = results[i];
	        } 
	}
	
	Patient (const Patient &p) {
		id = p.id;
		name = p.name;
		numTests = p.numTests;
		testResults = new string[numTests]; 
		for (int i = 0; i < numTests; i++) {
	            testResults[i] = p.testResults[i];
	    } 
	}
	
	void displayPatientDetails () {
		cout << "Patient ID: " << id << endl;
		cout << "Patient Name: " << name << endl;
		cout << "Test Results: " << endl;
		for (int i = 0; i < numTests; i++) {
			cout << "Test " << i+1 << ": " << *(testResults+i) << endl;
		}
		cout << endl;	
	}
	
	void inputDetails() {
		cout << "Enter Details: " << endl;
		cout << "Patient ID: ";
		cin >> id;
		cin.ignore();
		cout << "Patient Name: ";
		getline(cin, name);
		for (int i = 0; i < numTests; i++) {
			cout << "Test " << i+1 << ": " ;
			cout << *(testResults+i) << endl;
		}	
	}
	
	~Patient() {
        delete[] testResults;
    }
	
}; 

class MedicalLab{
	private:
	Patient* patient;
	
	public:
	MedicalLab (Patient* p) : patient(p) {}
	
	MedicalLab (const Patient &p) {
		patient->id = p.id;
		patient->name = p.name;
		patient->numTests = p.numTests;
		patient->testResults = new string(*p.testResults); 
	}
	
	void patientRecord() {
		patient->displayPatientDetails(); 
	}
	
	void updatePatientRecord(int id, string name, int numTests, string results[]) {
		patient->id = id;
		patient->name = name;
		patient->numTests = numTests;
		
		delete[] patient->testResults;
        patient->testResults = new string[numTests];
        
		for (int i = 0; i < numTests; i++) {
	            patient->testResults[i] = results[i];
	    } 
		
	}
	
};

int main() {
	string testResults[] = {"Malaria: -ve", "Diabetes: +ve", "TB: -ve"}; 
	
    Patient p1(101, "Maryam", 3, testResults);
    
    cout << "Original Patient Record:" << endl;
	p1.displayPatientDetails(); 
	
    MedicalLab cityLab1 (&p1);
    cout << "Copied Patient Record in Medical Lab:" << endl;
    cityLab1.patientRecord();
	 
	string newResults[] = {"COVID: +ve", "Blood Pressure: Normal"};
    cityLab1.updatePatientRecord(102, "Ali", 2, newResults);
    cout << "Updated Patient in Medical Lab:" << endl;
    cityLab1.patientRecord();
 
    cout << "Original Patient Record After Update :" << endl;
    p1.displayPatientDetails();
	
	return 0;
}
 
 // ✅   

#include <iostream>
using namespace std;

class TourGuide {
	public:
		string name;
		int yearsOfExperience;
		string specialization;
		
	TourGuide() {}
	
	TourGuide(string name, int yearsOfExperience, string specialization)
		: name(name), yearsOfExperience(yearsOfExperience), specialization(specialization) {}		
	
 	
	void display() {
		cout << "Name: " << name << endl;
		cout << "Year of Experience: " << yearsOfExperience << endl;
		cout << "Specialization: " << specialization << endl;	
	}
	
};

class TravelAgency{
	public:
		TourGuide* guides [15]; // Aggregation
		string agencyName;
		string headquater;
		int guideCount = 0;
		
	TravelAgency () {}
	
	TravelAgency (string agencyName, string headquater)
		: agencyName(agencyName), headquater(headquater) {
		for (int i = 0; i < 15; i++) {
			guides [i] = nullptr;
		}	
	}
	
	void getDetails() { 
		cout << "Enter Details of Tour Guides\n";
		cout <<  "____________________________________________________\n\n";
		while (guideCount < 15) { 
		    cout << "Year of Experience (-1 to exit): "; 
		    cin >> guides[ guideCount ]->yearsOfExperience;  
		    if (guides[ guideCount ]->yearsOfExperience == -1) break;
		    cin.ignore();
		    cout << "Name: ";
		    getline(cin, guides[ guideCount ]->name);
		    cout << "Specialization: ";
		    getline(cin, guides[ guideCount ]->specialization); 
		    guides[ guideCount ] = new TourGuide(guides[ guideCount ]->name, guides[ guideCount ]->yearsOfExperience, guides[ guideCount ]->specialization);
		    guideCount++;
		    cout << endl;
		} 
	}
	
	void display() {
		cout <<  "____________________________________________________\n";
		cout << "\nTour Agency: " << agencyName << endl;
		cout << "Headquater: " << headquater << endl; 
		cout <<  "____________________________________________________\n\n";
		for (int j = 0; j < guideCount; j++) {
			cout << "Tour Guide " << j+1 << ": " << endl;
			guides[j]->display();
			cout << endl;
		}
	}
	
	~TravelAgency() {
        for (int j = 0; j < guideCount; j++) {
            delete guides[j];
        }
    }
	
};


int main() {
	
	TravelAgency t("Adventure Quest Tours", "Daulatpur, Sindh"); 
	 
    t.getDetails();                               
	t.display();
	
	
	return 0;
}
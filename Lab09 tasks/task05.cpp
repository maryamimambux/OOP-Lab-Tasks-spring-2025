#include <iostream> 
using namespace std;

class Activity {

    public:
    virtual double calculateCaloriesBurned(double weight) = 0; 

    virtual ~Activity() {}

};

class Runnimg : public Activity {
    private: 
    double distance; // in km
    double time; // in min

    public:
    Runnimg  (double d, double t ) : distance(d), time(t) {}
    double calculateCaloriesBurned(double weight) { return distance*weight; }

};

class Cycling : public Activity {
    private: 
    double speed; // in km/h
    double time; // in hr

    public:
    Cycling  (double s, double t ) : speed(s), time(t) {}
    double calculateCaloriesBurned(double weight) { 
        double distance = speed*time;
        return distance*weight; 
    }
    
};
 

int main() {
    Runnimg run (12, 180);
    Cycling cyc (5, 3);

    double runcalories = run.calculateCaloriesBurned(55);
    double cyclingcalories = cyc.calculateCaloriesBurned(65);   
    cout << "Calories Burned in Runing: " << runcalories << endl;
    cout << "Calories Burned in Cycling: " << cyclingcalories << endl;

}
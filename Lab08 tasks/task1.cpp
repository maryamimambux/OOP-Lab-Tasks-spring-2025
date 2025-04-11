#include <iostream>
using namespace std;
class Humidity;
class Temperature {
    double temperature; // in Celcius

    public:
    Temperature (double temperature = 0.0) : temperature(temperature) {}
    friend double calculateHeatIndex(Temperature, Humidity);
};

class Humidity {
    double humidity; // in percentage
    double windSpeed;

    public:
    Humidity(double humidity, double windSpeed = 0.0) : humidity(humidity), windSpeed(windSpeed) {}
    friend double calculateHeatIndex(Temperature, Humidity);
};

double calculateHeatIndex( Temperature t, Humidity h ) {
    return (t.temperature + (0.33*h.humidity) - (0.7*h.windSpeed) - 4);

}

int main() {
  
    Temperature temp (32.0);
    Humidity hum (70);

    double heatIndex = calculateHeatIndex(temp, hum);
    cout << "Heat Index: " << heatIndex << endl;
    
    return 0;
}
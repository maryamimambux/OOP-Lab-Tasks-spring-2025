#include <iostream>
using namespace std;

class Currency {
    private:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

    public:
    Currency (double amount, string currencyCode, string currencySymbol, double exchangeRate) 
    : amount(amount), currencyCode(currencyCode), currencySymbol(currencySymbol), exchangeRate(exchangeRate) {};

    virtual void convertToBase() {
        if (currencyCode != "USD") {   
            amount *= exchangeRate;   
            currencyCode = "USD";      
        }
        else {
            cout << "Already in base currency." << endl;
        }
    }

    virtual double convertTo(Currency &target) {
        return (amount * exchangeRate) / target.exchangeRate;
    }
    
    virtual void displayCurrency() {
        cout << "Amount: " << amount << endl;
        cout << "Currency Code: " << currencyCode << endl;
        cout << "Currency Symbol: " << currencySymbol << endl;
        cout << "Exchange Rate: " << exchangeRate << endl;
    }
};

class Dollar : public Currency {

    public:
    Dollar (double amount, string currencyCode, string currencySymbol, double exchangeRate) 
    : Currency (amount, currencyCode, currencySymbol, exchangeRate) {};

    void displayCurrency() {
        Currency::displayCurrency();
    }

};

class Euro : public Currency {

    public:
    Euro (double amount, string currencyCode, string currencySymbol , double exchangeRate) 
    : Currency (amount, currencyCode, currencySymbol, exchangeRate) {};

    void convertToBase() { 
        cout << "Conversion to Base is not possible!" << endl; 
    }

    void convertTo(string targetCurrency) { cout << "Conversion to Other Curreny is not possible!" << endl; }

    void displayCurrency() {
        Currency::displayCurrency();
    }

};

class Rupee : public Currency {

    public:
    Rupee (double amount, string currencyCode , string currencySymbol  , double exchangeRate) 
    : Currency (amount, currencyCode, currencySymbol, exchangeRate) {};
 
    void displayCurrency() {
        Currency::displayCurrency();
    }

};

int main() {
    Currency* usd;
    Currency* eur;
    Currency* pkr; 
    
    Dollar dollar (100, "USD", "$", 1.0);
    Euro euro (2, "EUR", "C=", 1.1);
    Rupee rupee (3, "PKR", "Rs", 2.5);

    usd = &dollar;
    usd->displayCurrency();
    usd->convertToBase();
    cout << "Dollar to Euro: " << usd->convertTo(euro) << endl;
    cout << endl;

    eur = &euro;
    eur->displayCurrency();
    cout << "Euro to Rupee: " <<  eur->convertTo(rupee)  << endl;
    cout << endl;
    
    pkr = &rupee;
    pkr->displayCurrency();
    cout << "Rupee to Dollar: " <<  pkr->convertTo(dollar) << " $" << endl;
    cout << endl;

    return 0;
}
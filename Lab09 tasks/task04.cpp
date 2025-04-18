#include <iostream> 
using namespace std;

class PaymentMethod {

    public:
    virtual void processPayment(double amount) = 0; 

    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
    private: 
    string cardNumber; 

    public:
    CreditCard (string cNo ) : cardNumber(cNo) {}
    void processPayment(double amount) {
        cout << "Processing Credit Card Payment of $ " << amount << "---" << endl;
        if (cardNumber.length() == 16) { cout << "Payment Processing Successful\n";}
        else { cout << "Invalid Credit Card Number\n"; }
    }
};

class DigitalWallet : public PaymentMethod {
    private: 
    double balance; 

    public:
    DigitalWallet (double b ) : balance(b) {}
    void processPayment(double amount) {
        cout << "Processing Digital Wallet Payment of $ " << amount << "---" << endl;
        if (amount <= balance) { cout << "Payment Processing Successful\n";}
        else { cout << "Insufficaint Amount.\n"; }    
    }
};

int main() { 

    CreditCard card ( "1234567890125649" );
    DigitalWallet wallet ( 12345.54 );

    card.processPayment(1200);
    wallet.processPayment(200000);

}
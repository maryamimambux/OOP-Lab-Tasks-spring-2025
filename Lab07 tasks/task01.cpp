#include <iostream> 
using namespace std;

class Account {
    protected:
    int accountNumber;
    string name;
    double balance; 
    string accountType;

    public:

    Account (int accountNumber,  string name, double balance, string accountType)
    : accountNumber(accountNumber),  name(name), balance(balance), accountType(accountType) {};

    void deposit(double amount) {
        balance += amount;
        cout << "Amount added succeddfully!" << endl;
    }

    virtual void withdraw(double amount) {
        if (balance < amount) {
            cout << "Insufficient balance!" << endl; 
        }
        else {
            balance -= amount;
            cout << "Amount removed succeddfully!" << endl;
        }
    }

    // Intrest will be calculated accordingly wrt Account Type
    virtual void calculateInterest() { 
        cout << "Calculating interest: " << endl;
    }

    virtual void printStatement() {
        cout << "Account Number: " << accountNumber << "\nHolder: " << name
             << "\nBalance: $" << balance << "\nType: " << accountType << endl;
    }

    virtual void getAccountInfo() {
        cout << "Account No. " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account Type: " << accountType << endl;
    }

    virtual ~Account() {}

};

class SavingsAccount : public Account {
    protected:
    int interestRate;
    double minimumBalance;
    double transactionLimit;

    public:

    SavingsAccount (int accountNumber,  string name, double balance, string accountType, int interestRate, double minimumBalance, double transactionLimit = 56000.0)
    : Account (accountNumber,name,balance,accountType), interestRate(interestRate), minimumBalance(minimumBalance) {}

    void calculateInterest() override {
        double interest = (balance * interestRate) / 100;
        cout << "Interest Earned: $" << interest << endl;
    }
 

};

class CheckingAccount : public Account {
    double transactionLimit;

    public:
    CheckingAccount (int accountNumber,  string name, double balance, string accountType, int interestRate, double minimumBalance, double transactionLimit = 56000.0)
    : Account (accountNumber,name,balance,accountType)  {}

    void calculateInterest() override {
        cout << "Checking accounts do not earn interest." << endl;
    }

};

class FixedDepositAccount : public Account {
    protected:
    int maturityDate;
    double fixedInterestRate;

    public:

    FixedDepositAccount (int accountNumber,  string name, double balance, string accountType, int maturityDate, double fixedInterestRate)
    : Account (accountNumber,name,balance,accountType), maturityDate(maturityDate), fixedInterestRate(fixedInterestRate) {}

    void calculateInterest() override {
        double interest = (balance * fixedInterestRate * maturityDate) / 100;
        cout << "Fixed Deposit Interest Earned: $" << interest << endl;
    }

    void withdraw(double amount) override {
        cout << "Withdrawals are not allowed." << endl;
    }


};

int main() {

    Account* acc;

    SavingsAccount saving (24456, "Maryam", 2500, "Saving", 7, 2300.6);
    CheckingAccount check (34456, "Haleema", 3000, "Checking", 8, 2300.6);
    FixedDepositAccount fixed (34456, "Hina", 1200, "Fixed Deposit Account", 31725, 9 ); 

    acc = &saving;

    acc->calculateInterest();
    acc->getAccountInfo();

    cout << endl;

    acc = &check;
    acc->calculateInterest();
    acc->withdraw(20000);
    acc->getAccountInfo();

    cout << endl;

    acc = &fixed;
    acc->calculateInterest();
    acc->withdraw(20000);
    acc->getAccountInfo();

 
    return 0;
}

 
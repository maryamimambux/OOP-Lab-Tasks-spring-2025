#include <iostream>
using namespace std;

class Currency {
private:
    double amount;

public:
    Currency(double value = 0.0) : amount(value) {}

    Currency operator-() const {
        return Currency(-amount);
    }

    Currency operator+(const Currency& other) const {
        return Currency(amount + other.amount);
    }

    Currency operator-(const Currency& other) const {
        return Currency(amount - other.amount);
    }

    Currency& operator+=(const Currency& other) {
        amount += other.amount;
        return *this;
    }

    Currency& operator-=(const Currency& other) {
        amount -= other.amount;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Currency& c) {
        os << "$" << c.amount;
        return os;
    }
};

int main() {
    Currency price(100.0);
    Currency tax(15.0);
    Currency discount(10.0);

    Currency total = price + tax;
    cout << "Total after tax: " << total << endl;

    total -= discount;
    cout << "Total after discount: " << total << endl;

    Currency refund = -total;
    cout << "Refund (negative of total): " << refund << endl;

    Currency wallet(50.0);
    cout << "Initial wallet: " << wallet << endl;

    wallet += Currency(25.0);
    cout << "Wallet after adding $25: " << wallet << endl;

    wallet -= Currency(40.0);
    cout << "Wallet after spending $40: " << wallet << endl;

    return 0;
}

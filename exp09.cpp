// Exp 9: Custom exception hierarchy for banking transactions
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class BankException : public exception {
protected:
    string msg;
public:
    BankException(const string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class InsufficientFundsException : public BankException {
public:
    InsufficientFundsException(double balance, double amount)
        : BankException("Insufficient funds: balance " + to_string(balance) +
                        ", requested " + to_string(amount)) {}
};

class InvalidAmountException : public BankException {
public:
    InvalidAmountException(double amount)
        : BankException("Invalid amount: " + to_string(amount)) {}
};

class AccountLockedException : public BankException {
public:
    AccountLockedException() : BankException("Account is locked") {}
};

class Account {
    double balance;
    bool locked;
public:
    Account(double b) : balance(b), locked(false) {}
    void lock() { locked = true; }

    void deposit(double amt) {
        if (locked) throw AccountLockedException();
        if (amt <= 0) throw InvalidAmountException(amt);
        balance += amt;
        cout << "Deposited " << amt << ". Balance: " << balance << endl;
    }
    void withdraw(double amt) {
        if (locked) throw AccountLockedException();
        if (amt <= 0) throw InvalidAmountException(amt);
        if (amt > balance) throw InsufficientFundsException(balance, amt);
        balance -= amt;
        cout << "Withdrew " << amt << ". Balance: " << balance << endl;
    }
};

int main() {
    Account acc(1000);

    try { acc.deposit(500); acc.withdraw(200); acc.withdraw(5000); }
    catch (const InsufficientFundsException& e) { cout << "Caught: " << e.what() << endl; }

    try { acc.deposit(-50); }
    catch (const InvalidAmountException& e) { cout << "Caught: " << e.what() << endl; }

    acc.lock();
    try { acc.withdraw(10); }
    catch (const BankException& e) { cout << "Caught (base class): " << e.what() << endl; }

    return 0;
}
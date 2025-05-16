
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Account {
public:
    int accNo;
    string name;
    float balance;

    void create_account() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void show_account() const {
        cout << "Account No.: " << accNo << "\nName: " << name << "\nBalance: " << balance << endl;
    }

    void modify_account() {
        cout << "Modify Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Modify Balance: ";
        cin >> balance;
    }

    void deposit(float amount) {
        balance += amount;
    }

    void withdraw(float amount) {
        if (amount > balance) cout << "Insufficient Balance\n";
        else balance -= amount;
    }

    int getAccNo() const {
        return accNo;
    }
};

void write_account() {
    Account acc;
    ofstream outFile("accounts.dat", ios::binary | ios::app);
    acc.create_account();
    outFile.write(reinterpret_cast<char*>(&acc), sizeof(Account));
    outFile.close();
}

void display_account(int n) {
    Account acc;
    ifstream inFile("accounts.dat", ios::binary);
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.getAccNo() == n) {
            acc.show_account();
            found = true;
        }
    }
    inFile.close();
    if (!found) cout << "Account Not Found.\n";
}

int main() {
    int choice, num;
    do {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Create Account\n2. Display Account\n3. Exit\nChoose option: ";
        cin >> choice;
        switch (choice) {
            case 1: write_account(); break;
            case 2: cout << "Enter Account Number: "; cin >> num; display_account(num); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "Invalid Option.\n";
        }
    } while (choice != 3);
    return 0;
}

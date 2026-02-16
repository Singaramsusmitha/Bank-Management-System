#include <iostream>
#include <fstream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Initial Balance: ";
        cin >> balance;

        ofstream file("accounts.txt", ios::app);
        file << accountNumber << " " << name << " " << balance << endl;
        file.close();

        cout << "Account created successfully!\n";
    }

    void displayAccounts() {
        ifstream file("accounts.txt");
        int accNo;
        string accName;
        double accBalance;

        while (file >> accNo >> accName >> accBalance) {
            cout << "Account No: " << accNo
                 << ", Name: " << accName
                 << ", Balance: " << accBalance << endl;
        }

        file.close();
    }
};

int main() {
    BankAccount account;
    int choice;

    do {
        cout << "\n1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.createAccount();
                break;
            case 2:
                account.displayAccounts();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Structure to store account details
struct Account {
    int accountNumber;
    string accountHolderName;
    double balance;
};
////fgfgdfgdfgdfgdf

// Vector to store all accounts
vector<Account> accounts;

// Function to create a new account
void createAccount() {
    Account newAccount;
    cout << "\n--- Create New Account ---\n";
    cout << "Enter Account Number: ";
    cin >> newAccount.accountNumber;
    cin.ignore(); // Ignore trailing newline
    cout << "Enter Account Holder Name: ";
    getline(cin, newAccount.accountHolderName);
    newAccount.balance = 0.0; // New account starts with a balance of 0
    accounts.push_back(newAccount);
    cout << "Account created successfully!\n";
}

// Function to deposit money into an account
void depositMoney() {
    int accountNumber;
    double amount;
    cout << "\n--- Deposit Money ---\n";
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    // Find the account
    for (auto &acc : accounts) {
        if (acc.accountNumber == accountNumber) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc.balance += amount;
            cout << "Deposit successful! New Balance: $" << acc.balance << "\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

// Function to withdraw money from an account
void withdrawMoney() {
    int accountNumber;
    double amount;
    cout << "\n--- Withdraw Money ---\n";
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    // Find the account
    for (auto &acc : accounts) {
        if (acc.accountNumber == accountNumber) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (amount > acc.balance) {
                cout << "Insufficient balance!\n";
            } else {
                acc.balance -= amount;
                cout << "Withdrawal successful! New Balance: $" << acc.balance << "\n";
            }
            return;
        }
    }
    cout << "Account not found!\n";
}

// Function to check account balance
void checkBalance() {
    int accountNumber;
    cout << "\n--- Check Account Balance ---\n";
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    // Find the account
    for (const auto &acc : accounts) {
        if (acc.accountNumber == accountNumber) {
            cout << "Account Holder: " << acc.accountHolderName << "\n";
            cout << "Current Balance: $" << acc.balance << "\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

// Main menu function
void showMenu() {
    cout << "\n--- Banking Management System ---\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Check Balance\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

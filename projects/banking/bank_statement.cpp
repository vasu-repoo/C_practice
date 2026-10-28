
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

struct Transaction {
    string date;
    string type;
    double amount;
    double balance;
};

string getDate() {
    time_t now = time(nullptr);
    tm* local = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M", local);
    return buffer;
}

int main() {
    string name, account;
    vector<Transaction> transactions;
    double balance = 0.0;
    int choice;

    cout << "===== MINI BANK STATEMENT GENERATOR =====\n";
    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    getline(cin, account);

    do {
        cout << "\n1. Deposit\n2. Withdraw\n";
        cout << "3. View Statement\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            double amount;
            cout << "Enter amount (Rs.): ";
            cin >> amount;

            if (amount <= 0) {
                cout << "Amount must be positive.\n";
                continue;
            }

            if (choice == 2 && amount > balance) {
                cout << "Insufficient balance!\n";
                continue;
            }

            string type;

            if (choice == 1) {
                balance += amount;
                type = "Deposit";
            } else {
                balance -= amount;
                type = "Withdrawal";
            }

            transactions.push_back({
                getDate(), type, amount, balance
            });

            cout << type << " successful!\n";
            cout << "Current balance: Rs. "
                 << fixed << setprecision(2) << balance << "\n";
        }
        else if (choice == 3) {
            cout << "\n========== BANK STATEMENT ==========\n";
            cout << "Customer: " << name << "\n";
            cout << "Account: " << account << "\n";

            cout << left << setw(19) << "Date"
                 << setw(13) << "Type"
                 << right << setw(12) << "Amount"
                 << setw(13) << "Balance" << "\n";

            cout << string(57, '-') << "\n";
            cout << fixed << setprecision(2);

            for (const auto& t : transactions) {
                cout << left << setw(19) << t.date
                     << setw(13) << t.type
                     << right << setw(12) << t.amount
                     << setw(13) << t.balance << "\n";
            }

            cout << "\nAvailable Balance: Rs. " << balance << "\n";
        }
        else if (choice == 4) {
            cout << "Thank you for banking with us!\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double balance = 5000;
    double amount;
    int choice;

    do {
        cout << "\n===== DIGITAL ATM =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Choose option: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Balance: Rs. "
                     << fixed << setprecision(2)
                     << balance << endl;
                break;

            case 2:
                cout << "Deposit amount: ";
                if (!(cin >> amount) || amount <= 0) {
                    cout << "Invalid amount!\n";
                    return 1;
                }
                balance += amount;
                cout << "Deposit successful!\n";
                break;

            case 3:
                cout << "Withdrawal amount: ";
                if (!(cin >> amount) || amount <= 0) {
                    cout << "Invalid amount!\n";
                    return 1;
                }

                if (amount > balance)
                    cout << "Insufficient balance!\n";
                else {
                    balance -= amount;
                    cout << "Withdrawal successful!\n";
                }
                break;

            case 4:
                cout << "Thank you for using ATM!\n";
                break;

            default:
                cout << "Invalid option!\n";
        }

    } while (choice != 4);

    return 0;
}

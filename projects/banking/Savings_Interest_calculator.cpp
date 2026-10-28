
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double principal, rate, years;
    double simpleInterest, compoundInterest;
    double simpleAmount, compoundAmount;
    int choice, frequency;

    cout << "====================================\n";
    cout << "     SAVINGS INTEREST CALCULATOR\n";
    cout << "====================================\n";

    cout << "Enter principal amount (Rs.): ";
    cin >> principal;

    cout << "Enter annual interest rate (%): ";
    cin >> rate;

    cout << "Enter investment period (years): ";
    cin >> years;

    if (principal <= 0 || rate < 0 || years <= 0) {
        cout << "\nInvalid input! Please enter valid values.\n";
        return 1;
    }

    cout << "\nChoose Interest Type:\n";
    cout << "1. Simple Interest\n";
    cout << "2. Compound Interest\n";
    cout << "3. Both\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "Invalid choice!\n";
        return 1;
    }

    // Simple interest calculation
    simpleInterest = principal * rate * years / 100.0;
    simpleAmount = principal + simpleInterest;

    if (choice == 2 || choice == 3) {
        cout << "\nCompounding Frequency:\n";
        cout << "1. Annually\n";
        cout << "2. Half-yearly\n";
        cout << "3. Quarterly\n";
        cout << "4. Monthly\n";
        cout << "Enter choice: ";
        cin >> frequency;

        if (frequency < 1 || frequency > 4) {
            cout << "Invalid frequency!\n";
            return 1;
        }

        int n;

        switch (frequency) {
            case 1: n = 1;  break;
            case 2: n = 2;  break;
            case 3: n = 4;  break;
            case 4: n = 12; break;
            default: n = 1;
        }

        compoundAmount = principal *
            pow(1 + rate / (100.0 * n), n * years);

        compoundInterest = compoundAmount - principal;
    }

    cout << fixed << setprecision(2);
    cout << "\n========== RESULTS ==========\n";
    cout << "Principal Amount: Rs. " << principal << "\n";
    cout << "Annual Interest Rate: " << rate << "%\n";
    cout << "Investment Period: " << years << " years\n";

    if (choice == 1 || choice == 3) {
        cout << "\n--- Simple Interest ---\n";
        cout << "Interest Earned: Rs. "
             << simpleInterest << "\n";
        cout << "Maturity Amount: Rs. "
             << simpleAmount << "\n";
    }

    if (choice == 2 || choice == 3) {
        cout << "\n--- Compound Interest ---\n";
        cout << "Interest Earned: Rs. "
             << compoundInterest << "\n";
        cout << "Maturity Amount: Rs. "
             << compoundAmount << "\n";
    }

    cout << "\n=============================\n";
    cout << "Thank you for using the calculator!\n";

    return 0;
}

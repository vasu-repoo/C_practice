
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double principal, annualRate;
    double monthlyRate, emi;
    double totalPayment, totalInterest;
    int months;

    cout << "===== LOAN EMI CALCULATOR =====\n";

    cout << "Enter loan amount (Rs.): ";
    cin >> principal;

    cout << "Enter annual interest rate (%): ";
    cin >> annualRate;

    cout << "Enter loan duration (months): ";
    cin >> months;

    if (!cin || principal <= 0 ||
        annualRate < 0 || months <= 0) {
        cout << "Invalid input. Please enter valid values.\n";
        return 1;
    }

    monthlyRate = annualRate / 1200.0;

    if (monthlyRate == 0) {
        emi = principal / months;
    } else {
        double factor = pow(1 + monthlyRate, months);
        emi = principal * monthlyRate * factor
              / (factor - 1);
    }

    totalPayment = emi * months;
    totalInterest = totalPayment - principal;

    cout << fixed << setprecision(2);
    cout << "\n========== LOAN SUMMARY ==========\n";
    cout << "Loan Amount:      Rs. " << principal << "\n";
    cout << "Annual Rate:      " << annualRate << "%\n";
    cout << "Loan Duration:    " << months << " months\n";
    cout << "Monthly EMI:      Rs. " << emi << "\n";
    cout << "Total Interest:   Rs. " << totalInterest << "\n";
    cout << "Total Repayment:  Rs. " << totalPayment << "\n";

    return 0;
}

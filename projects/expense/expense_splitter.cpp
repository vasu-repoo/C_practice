
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double total = 0;

    cout << "===== EXPENSE SPLITTER =====\n";
    cout << "Number of people: ";

    if (!(cin >> n) || n <= 0 || n > 100) {
        cout << "Invalid number!";
        return 1;
    }

    vector<string> names(n);
    vector<double> expenses(n);

    for (int i = 0; i < n; i++) {
        cout << "\nName of person " << i + 1 << ": ";
        cin >> names[i];

        cout << "Expense paid: ";

        if (!(cin >> expenses[i]) || expenses[i] < 0) {
            cout << "Invalid expense!";
            return 1;
        }

        total += expenses[i];
    }

    double share = total / n;

    cout << fixed << setprecision(2);
    cout << "\nTotal expense: Rs. " << total;
    cout << "\nEach person's share: Rs. " << share;

    cout << "\n\nSettlement:\n";

    for (int i = 0; i < n; i++) {
        double difference = expenses[i] - share;

        if (difference > 0)
            cout << names[i] << " should receive Rs. "
                 << difference << endl;
        else if (difference < 0)
            cout << names[i] << " owes Rs. "
                 << -difference << endl;
        else
            cout << names[i] << " is settled.\n";
    }

    return 0;
}

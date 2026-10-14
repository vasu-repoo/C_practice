#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the size: ";
    cin >> n;

    // Upper half
    for (int i = 1; i <= n; i++) {

        // Left wing
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // Middle spaces
        for (int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }

        // Right wing
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    // Lower half
    for (int i = n - 1; i >= 1; i--) {

        // Left wing
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // Middle spaces
        for (int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }

        // Right wing
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
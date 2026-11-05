
#include <iostream>
using namespace std;

int main() {
    int n = 5;

    // Upper half
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // Print stars and inner spaces
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }

        cout << endl;
    }

    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // Print stars and inner spaces
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}

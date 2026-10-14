#include <iostream>
using namespace std;

int main() {
    int n = 5;

    // Upper half
    for (int i = 1; i <= n; i++) {

        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // Increasing numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        // Decreasing numbers
        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
    }

    // Lower half
    for (int i = n - 1; i >= 1; i--) {

        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // Increasing numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        // Decreasing numbers
        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}
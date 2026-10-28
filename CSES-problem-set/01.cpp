#include <iostream>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    // Print initial n
    cout << n;

    // Keep running until n becomes 1
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;          // Even case: divide by 2
        } else {
            n = 3 * n + 1;   // Odd case: 3n + 1
        }
        cout << " " << n;   // Print the updated n separated by a space
    }

    cout << "\n";
    return 0;
}
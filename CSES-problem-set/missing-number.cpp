#include <iostream>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    // Calculate total expected sum from 1 to n
    long long expected_sum = n * (n + 1) / 2;

    // Calculate actual sum of the given n - 1 numbers
    long long actual_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        long long x;
        cin >> x;
        actual_sum += x;
    }

    // The missing number is the difference
    cout << expected_sum - actual_sum << "\n";

    return 0;
}
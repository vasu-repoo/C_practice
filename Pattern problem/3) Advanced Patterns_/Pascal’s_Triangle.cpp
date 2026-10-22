
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    vector<long long> row = {1};

    // Generate each row of Pascal's Triangle
    for (int i = 0; i < n; i++) {
        // Print spaces to center the triangle
        for (int s = 0; s < n - i; s++) {
            cout << " ";
        }

        // Print the current row
        for (int j = 0; j < row.size(); j++) {
            cout << row[j] << " ";
        }
        cout << endl;

        // Calculate the next row
        vector<long long> nextRow(row.size() + 1, 1);

        for (int j = 1; j < row.size(); j++) {
            nextRow[j] = row[j - 1] + row[j];
        }

        row = nextRow;
    }

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int year;

    cout << "Enter a year: ";
    if (!(cin >> year) || year <= 0) {
        cout << "Invalid year!";
        return 1;
    }

    if (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0)) {
        cout << year << " is a leap year.";
    } else {
        cout << year << " is not a leap year.";
    }

    cout << endl;
    return 0;
}

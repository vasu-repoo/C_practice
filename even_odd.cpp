#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    bool isEven = (number % 2 == 0);

    if (isEven) {
        cout << "YES, THE NUMBER IS EVEN " << number << endl;
    } else {
        cout << "NO, THE NUMBER IS NOT EVEN " << number << endl;
    }
}
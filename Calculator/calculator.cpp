#include <iostream>
using namespace std;

int main() {
    double result, number;
    char op;

    cout << "Enter first number: ";
    cin >> result;

    while (true) {
        cout << "\nEnter operator (+, -, *, /, =): ";
        cin >> op;

        if (op == '=') {
            cout << "\nFinal Result = " << result << endl;
            break;
        }

        cout << "Enter next number: ";
        cin >> number;

        switch (op) {
            case '+':
                result += number;
                break;

            case '-':
                result -= number;
                break;

            case '*':
                result *= number;
                break;

            case '/':
                if (number == 0) {
                    cout << "Error: Cannot divide by zero!" << endl;
                    continue;
                }
                result /= number;
                break;

            default:
                cout << "Invalid operator!" << endl;
                continue;
        }

        cout << "Current Result = " << result << endl;
    }

    return 0;
}
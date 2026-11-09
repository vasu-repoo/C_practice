
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string password;
    int score = 0;

    cout << "===== PASSWORD STRENGTH CHECKER =====\n";
    cout << "Enter password: ";
    getline(cin, password);

    bool upper = false, lower = false;
    bool digit = false, special = false;

    for (char ch : password) {
        if (isupper(static_cast<unsigned char>(ch)))
            upper = true;
        else if (islower(static_cast<unsigned char>(ch)))
            lower = true;
        else if (isdigit(static_cast<unsigned char>(ch)))
            digit = true;
        else
            special = true;
    }

    if (password.length() >= 8) score++;
    if (password.length() >= 12) score++;
    if (upper) score++;
    if (lower) score++;
    if (digit) score++;
    if (special) score++;

    cout << "\nPassword analysis:\n";
    cout << "Uppercase: " << (upper ? "Yes" : "No") << endl;
    cout << "Lowercase: " << (lower ? "Yes" : "No") << endl;
    cout << "Digits: " << (digit ? "Yes" : "No") << endl;
    cout << "Special characters: " << (special ? "Yes" : "No") << endl;

    if (score <= 2)
        cout << "Strength: Weak\n";
    else if (score <= 4)
        cout << "Strength: Medium\n";
    else
        cout << "Strength: Strong\n";

    return 0;
}

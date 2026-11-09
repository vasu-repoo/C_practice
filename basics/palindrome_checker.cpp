
#include <iostream>
using namespace std;

bool isPalindrome(int number) {
    if (number < 0)
        return false;

    int original = number;
    long long reversed = 0;

    while (number > 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }

    return original == reversed;
}

int main() {
    int number;

    cout << "===== PALINDROME CHECKER =====\n";
    cout << "Enter a number: ";

    if (!(cin >> number)) {
        cout << "Invalid input!";
        return 1;
    }

    if (isPalindrome(number))
        cout << "It is a palindrome!";
    else
        cout << "It is not a palindrome.";

    cout << endl;
    return 0;
}


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int secret = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "================================\n";
    cout << "       NUMBER GUESSING GAME\n";
    cout << "================================\n";

    cout << "\nGuess a number between 1 and 100!\n";

    do {
        cout << "\nEnter your guess: ";
        cin >> guess;

        attempts++;

        if (guess > secret) {
            cout << "Too high! Try again.\n";
        }
        else if (guess < secret) {
            cout << "Too low! Try again.\n";
        }
        else {
            cout << "\nCONGRATULATIONS! YOU WON!\n";
            cout << "You guessed it in "
                 << attempts << " attempts!\n";
        }

    } while (guess != secret);

    cout << "\nThanks for playing!\n";

    return 0;
}
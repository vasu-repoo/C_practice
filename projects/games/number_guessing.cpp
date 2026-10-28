
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int num;
    int guess;
    int tries = 0;

    srand(time(0));
    num = (rand() % 100) + 1;

    std::cout << "==============================\n";
    std::cout << "     NUMBER GUESSING GAME\n";
    std::cout << "==============================\n";
    std::cout << "Guess a number between 1 and 100!\n";

    do {
        std::cout << "\nEnter your guess: ";
        std::cin >> guess;
        tries++;

        if (guess > num) {
            std::cout << "Too high! Try again.\n";
        }
        else if (guess < num) {
            std::cout << "Too low! Try again.\n";
        }
        else {
            std::cout << "\nCORRECT! You guessed it!\n";
            std::cout << "Number of tries: " << tries << '\n';
        }

    } while (guess != num);

    std::cout << "==============================\n";
    std::cout << "         GAME OVER!\n";
    std::cout << "==============================\n";

    return 0;
}
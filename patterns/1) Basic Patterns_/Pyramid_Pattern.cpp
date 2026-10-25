
#include <iostream>

int main() {
    int rows;
    char symbol;

    std::cout << "Enter number of rows: ";
    std::cin >> rows;

    std::cout << "Enter a symbol: ";
    std::cin >> symbol;

    for (int i = 1; i <= rows; i++) {

        for (int j = 1; j <= rows - i; j++) {
            std::cout << " ";
        }

        for (int k = 1; k <= 2 * i - 1; k++) {
            std::cout << symbol;
        }

        std::cout << '\n';
    }

    return 0;
}

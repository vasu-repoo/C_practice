#include <iostream>

int main()
{
    int rows;
    int columns;
    char symbol;

    std::cout << "How many rows: ";
    std::cin >> rows;

    std::cout << "How many columns: ";
    std::cin >> columns;

    std::cout << "Enter your symbol: ";
    std::cin >> symbol;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            if (i == 1 || i == rows || j == columns || j == 1) {
                std::cout << symbol;
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
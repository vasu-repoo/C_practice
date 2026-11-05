#include <iostream>

int main()
{
    int rows;
// systematic manner
    std::cout << "How many rows: ";
    std::cin >> rows;

    // Upper half of the diamond
    for (int i = 1; i <= rows; i++)
    {
        // Print spaces
        for (int j = 1; j <= rows - i; j++)
        {
            std::cout << " ";
        }

        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }

    // Lower half of the diamond
    for (int i = rows - 1; i >= 1; i--)
    {
        // Print spaces
        for (int j = 1; j <= rows - i; j++)
        {
            std::cout << " ";
        }

        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }

    return 0;
}
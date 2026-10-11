#include <iostream>

int main(){
    int i;
    int row;

    std::cout << "ENTER THE NO. OF ROWS: ";std::cin >> row;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j<=row-i+1; j++)
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }

    return 0;
}
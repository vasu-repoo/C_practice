#include <iostream>

int main()
{
    int rows;
    
    std::cout << "How many rows: ";
    std::cin >> rows;    

    // loop
    for (int i=1; i<=rows; i++){
        for (int j = 1; j <= rows-i; j++)
        {// spaces
            std::cout << " ";
        }

        // Loop 2: Print stars
        for (int k = 1; k <= i; k++)
        {
            std::cout << "*";
        }

        std::cout<< "\n";
    }

    return 0;
}
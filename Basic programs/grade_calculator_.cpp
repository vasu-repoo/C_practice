#include <iostream>

int main()
{
    int num;
    std::cout << "Enter your number: ";
    std::cin >> num;
// ***** C++ does not support chained comparisons like 90 < num <= 100 so ****
    if (num > 90 && num <= 100) {
        std::cout << "A";
    }
    else if (num > 80 && num <= 90) {
        std::cout << "B";
    }
    else if (num > 70 && num <= 80) {
        std::cout << "C";
    }
    else if (num > 60 && num <= 70) {
        std::cout << "D";
    }
    else if (num > 50 && num <= 60) {
        std::cout << "E";
    }
    else if (num >= 40 && num <= 50) {
        std::cout << "PASS";
    }
    else {
        std::cout << "Fail";
    }

    return 0;
}
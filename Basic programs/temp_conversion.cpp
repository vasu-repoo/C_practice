#include <iostream>

int main()
{
    float temp;
    char unit;

    std::cout << "Temperature Conversion\n";
    std::cout << "F for Fahrenheit\n";
    std::cout << "C for Celsius\n";
    std::cout << "Enter F or C:";std::cin >> unit;
    

    std::cout << "Enter the Temp: ";
    std::cin >> temp;

    if (unit == 'F' || unit == 'f') {
        temp = (temp - 32.0) / 1.8;
        std::cout << "Temperature is: " << temp << " C\n";
    }
    else if (unit == 'C' || unit == 'c') {
        temp = (1.8 * temp) + 32.0;
        std::cout << "Temperature is: " << temp << " F\n";
    }
    else {
        std::cout << "Enter only C or F\n";
    }

    return 0;
}
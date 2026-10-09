#include <iostream>
#include <cmath>

int main() {
    double a, b, c;

    std::cout << "Enter the lengths a: ";
    std::cin >> a;
    std::cout << "Enter the length b: ";
    std::cin >> b;

    // for Calculate the length of the hypotenuse using Pythagoras' theorem
    // c = std::sqrt(a * a + b * b);
    a = std::pow(a, 2);
    b = std::pow(b, 2);
    c = std::sqrt(a + b);

    std::cout << "The length of the hypotenuse (c) is: " << c << std::endl;

    return 0;
}
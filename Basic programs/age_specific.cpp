#include <iostream>

int main() 
{
    int age;
    
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    if (age >= 18 && age <= 84) {
    std::cout << "You are eligible for the entry.";
}
else if (age >= 85) {
    std::cout << "You are too old to enter.";
}
else if (age >= 0 && age < 18) {
    std::cout << "You are not old enough to enter.";
}
else {
    std::cout << "Invalid age.";
}

return 0;
}
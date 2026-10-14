#include <iostream>
#include <string>
#include <cctype>

// Credit Card Validator using the Luhn Algorithm

std::string cleanCardNumber(const std::string& input) {
    std::string number;

    for (unsigned char ch : input) {
        if (std::isdigit(ch)) {
            number += static_cast<char>(ch);
        } else if (ch != ' ' && ch != '-') {
            return ""; // Invalid character
        }
    }

    return number;
}

int evenReverseSum(const std::string& number, int size) {
    int sum = 0;

    // Double every second digit from the right
    for (int i = size - 2; i >= 0; i -= 2) {
        int digit = number[i] - '0';
        digit *= 2;

        if (digit > 9) {
            digit -= 9;
        }

        sum += digit;
    }

    return sum;
}

int oddReverseSum(const std::string& number, int size) {
    int sum = 0;

    // Add the remaining digits
    for (int i = size - 1; i >= 0; i -= 2) {
        sum += number[i] - '0';
    }

    return sum;
}

bool isValidCardNumber(const std::string& number) {
    if (number.length() < 12 || number.length() > 19) {
        return false;
    }

    int sum = evenReverseSum(number, number.length());
    sum += oddReverseSum(number, number.length());

    return sum % 10 == 0;
}

int main() {
    std::string input;

    std::cout << "====================================\n";
    std::cout << "       CREDIT CARD VALIDATOR\n";
    std::cout << "====================================\n";

    std::cout << "Enter a card number: ";
    std::getline(std::cin, input);

    std::string cardNumber = cleanCardNumber(input);

    if (cardNumber.empty()) {
        std::cout << "Error: Please enter digits only, "
                     "with optional spaces or hyphens.\n";
        return 1;
    }

    if (cardNumber.length() < 12 || cardNumber.length() > 19) {
        std::cout << "Error: Card number must contain "
                     "12 to 19 digits.\n";
        return 1;
    }

    if (isValidCardNumber(cardNumber)) {
        std::cout << "Result: Luhn checksum passed! HURRAY!!!\n";
    } else {
        std::cout << "Result: Luhn checksum failed.\n";
    }

    std::cout << "Note: This checks the checksum only, "
                 "not whether the card or account is genuine.\n";

    return 0;
}
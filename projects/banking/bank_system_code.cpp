#include <iostream>
#include <iomanip>
#include <limits>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
    double balance = 0;
    int choice = 0;

    do {
        std::cout << "***********************\n";
        std::cout << "Enter your choice:\n";
        std::cout << "***********************\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input! Enter a number.\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n'
            );
            continue;
        }

        switch (choice) {
            case 1:
                showBalance(balance);
                break;

            case 2:
                balance += deposit();
                break;

            case 3:
                balance -= withdraw(balance);
                break;

            case 4:
                std::cout << "Thanks for visiting!\n";
                break;

            default:
                std::cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}

void showBalance(double balance)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your current balance is: $"
              << balance << '\n';
}

double deposit()
{
    double amount = 0;

    std::cout << "Enter amount to deposit: $";

    if (!(std::cin >> amount)) {
        std::cout << "Invalid input!\n";
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );
        return 0;
    }

    if (amount <= 0) {
        std::cout << "Invalid deposit amount!\n";
        return 0;
    }

    std::cout << "Deposit successful!\n";
    return amount;
}

double withdraw(double balance)
{
    double amount = 0;

    std::cout << "Enter amount to withdraw: $";

    if (!(std::cin >> amount)) {
        std::cout << "Invalid input!\n";
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n'
        );
        return 0;
    }

    if (amount <= 0) {
        std::cout << "Invalid withdrawal amount!\n";
        return 0;
    }

    if (amount > balance) {
        std::cout << "Insufficient funds!\n";
        return 0;
    }

    std::cout << "Withdrawal successful!\n";
    return amount;
}

#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main()
{
    char player;
    char computer;

    player = getUserChoice();
    std::cout << "Your choice: ";
    showChoice(player);

    computer = getComputerChoice();
    std::cout << "Computer's choice: ";
    showChoice(computer);

    chooseWinner(player, computer);

    return 0;
}

char getUserChoice()
{
    char player;

    do
    {
        std::cout << "Rock-Paper-Scissors\n";
        std::cout << "************************\n";
        std::cout << "r for Rock\n";
        std::cout << "p for Paper\n";
        std::cout << "s for Scissors\n";
        std::cin >> player;
    }
    while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerChoice()
{
    int num = rand() % 3 + 1;

    switch (num)
    {
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }

    return '\0';
}

void showChoice(char choice)
{
    switch (choice)
    {
        case 'r': std::cout << "Rock\n"; break;
        case 'p': std::cout << "Paper\n"; break;
        case 's': std::cout << "Scissors\n"; break;
    }
}

void chooseWinner(char player, char computer)
{
    if (player == computer)
    {
        std::cout << "It's a tie!\n";
    }
    else if (player == 'r' && computer == 's')
    {
        std::cout << "You win!\n";
    }
    else if (player == 'p' && computer == 'r')
    {
        std::cout << "You win!\n";
    }
    else if (player == 's' && computer == 'p')
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }
}

#include <iostream>
using namespace std;

void birthdayWish(string name) {
    cout << "\n******************************\n";
    cout << "      HAPPY BIRTHDAY!  \n";
    cout << "******************************\n";
    cout << "Happy Birthday, " << name << "!\n";
    cout << "May your day be full of joy!\n";
    cout << "Wishing you happiness and success!\n";
    cout << "******************************\n";
}

int main() {
    birthdayWish("Best Friend");
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    string questions[] = {
        "Which language is used for system programming?",
        "What is the size of an int commonly on modern systems?",
        "Which keyword creates a class in C++?",
        "Which container follows FIFO?",
        "Which operator is used for remainder?"
    };

    string options[][4] = {
        {"1. HTML", "2. C++", "3. CSS", "4. SQL"},
        {"1. 1 byte", "2. 2 bytes", "3. 4 bytes", "4. 16 bytes"},
        {"1. struct", "2. define", "3. class", "4. object"},
        {"1. Stack", "2. Queue", "3. Tree", "4. Graph"},
        {"1. /", "2. *", "3. %", "4. +"}
    };

    int answers[] = {2, 3, 3, 2, 3};
    int score = 0;
    int choice;

    cout << "===== C++ QUIZ =====\n";

    for (int i = 0; i < 5; i++) {
        cout << "\n" << i + 1 << ". " << questions[i] << endl;

        for (int j = 0; j < 4; j++)
            cout << options[i][j] << endl;

        cout << "Your answer: ";

        if (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid answer!\n";
            return 1;
        }

        if (choice == answers[i]) {
            score++;
            cout << "Correct!\n";
        } else {
            cout << "Incorrect!\n";
        }
    }

    cout << "\nFinal Score: " << score << "/5\n";

    return 0;
}

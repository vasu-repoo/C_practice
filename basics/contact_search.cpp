
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
};

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        cout << "\n===== CONTACT MANAGER =====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) return 1;
        cin.ignore(10000, '\n');

        if (choice == 1) {
            Contact c;

            cout << "Enter name: ";
            getline(cin, c.name);

            cout << "Enter phone: ";
            getline(cin, c.phone);

            if (c.name.empty() || c.phone.empty()) {
                cout << "Fields cannot be empty!\n";
            } else {
                contacts.push_back(c);
                cout << "Contact saved!\n";
            }
        }
        else if (choice == 2) {
            for (const auto& c : contacts)
                cout << c.name << " - " << c.phone << endl;
        }
        else if (choice == 3) {
            string search;
            cout << "Enter name to search: ";
            getline(cin, search);

            bool found = false;

            for (const auto& c : contacts) {
                if (c.name == search) {
                    cout << c.name << " - " << c.phone << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "Contact not found!\n";
        }

    } while (choice != 4);

    return 0;
}

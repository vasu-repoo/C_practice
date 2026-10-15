#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>

using namespace std;

struct Contact {
    int id;
    string name;
    string phone;
    string email;
};

class ContactBook {
private:
    vector<Contact> contacts;
    const string filename = "contacts.csv";
    int nextId = 1;

    string readText(const string& prompt) {
        string value;
        cout << prompt;
        getline(cin, value);

        // Remove surrounding whitespace
        size_t first = value.find_first_not_of(" \t\r\n");
        if (first == string::npos) return "";

        size_t last = value.find_last_not_of(" \t\r\n");
        return value.substr(first, last - first + 1);
    }

    string csvEscape(const string& value) {
        string result = "\"";

        for (char c : value) {
            if (c == '"')
                result += "\"\"";
            else
                result += c;
        }

        result += '"';
        return result;
    }

    vector<string> parseCsvLine(const string& line) {
        vector<string> fields;
        string field;
        bool quoted = false;

        for (size_t i = 0; i < line.size(); i++) {
            char c = line[i];

            if (quoted) {
                if (c == '"') {
                    if (i + 1 < line.size() &&
                        line[i + 1] == '"') {
                        field += '"';
                        i++;
                    } else {
                        quoted = false;
                    }
                } else {
                    field += c;
                }
            } else if (c == ',' && !quoted) {
                fields.push_back(field);
                field.clear();
            } else if (c == '"' && field.empty()) {
                quoted = true;
            } else {
                field += c;
            }
        }

        if (quoted) return {};

        fields.push_back(field);
        return fields;
    }

    void loadContacts() {
        ifstream file(filename);
        if (!file) return;

        string line;
        getline(file, line); // Skip header

        while (getline(file, line)) {
            vector<string> fields = parseCsvLine(line);

            if (fields.size() != 4) continue;

            try {
                size_t used = 0;
                int id = stoi(fields[0], &used);

                if (used != fields[0].size() || id < 1)
                    continue;

                if (fields[1].empty() || fields[2].empty())
                    continue;

                contacts.push_back({
                    id, fields[1], fields[2], fields[3]
                });

                nextId = max(nextId, id + 1);
            } catch (...) {
                // Ignore invalid CSV records
            }
        }
    }

    bool saveContacts() {
        ofstream file(filename, ios::trunc);

        if (!file) {
            cout << "Error: Could not save contacts.\n";
            return false;
        }

        file << "id,name,phone,email\n";

        for (const auto& contact : contacts) {
            file << contact.id << ','
                 << csvEscape(contact.name) << ','
                 << csvEscape(contact.phone) << ','
                 << csvEscape(contact.email) << '\n';
        }

        file.flush();

        if (!file) {
            cout << "Error while writing contacts.\n";
            return false;
        }

        return true;
    }

    void printContact(const Contact& contact) {
        cout << "\nID: " << contact.id
             << "\nName: " << contact.name
             << "\nPhone: " << contact.phone
             << "\nEmail: " << contact.email
             << "\n--------------------------\n";
    }

    void addContact() {
        cout << "\n--- Add Contact ---\n";

        string name = readText("Enter name: ");
        if (name.empty()) {
            cout << "Name cannot be empty.\n";
            return;
        }

        string phone = readText("Enter phone number: ");
        if (phone.empty()) {
            cout << "Phone number cannot be empty.\n";
            return;
        }

        string email = readText("Enter email (optional): ");

        contacts.push_back({nextId, name, phone, email});

        if (saveContacts()) {
            cout << "Contact added successfully! ID: "
                 << nextId << '\n';
            nextId++;
        } else {
            contacts.pop_back();
            cout << "Contact was not saved.\n";
        }
    }

    void viewContacts() {
        cout << "\n--- All Contacts ---\n";

        if (contacts.empty()) {
            cout << "No contacts found.\n";
            return;
        }

        for (const auto& contact : contacts)
            printContact(contact);
    }

    void searchContact() {
        string query = readText("Enter name to search: ");

        if (query.empty()) {
            cout << "Search name cannot be empty.\n";
            return;
        }

        auto toLower = [](string text) {
            transform(text.begin(), text.end(), text.begin(),
                [](unsigned char c) {
                    return static_cast<char>(tolower(c));
                });
            return text;
        };

        query = toLower(query);
        bool found = false;

        for (const auto& contact : contacts) {
            if (toLower(contact.name).find(query)
                != string::npos) {
                printContact(contact);
                found = true;
            }
        }

        if (!found)
            cout << "No matching contact found.\n";
    }

    void deleteContact() {
        cout << "\n--- Delete Contact ---\n";

        string input = readText("Enter contact ID: ");
        stringstream ss(input);
        int id;
        char extra;

        if (!(ss >> id) || (ss >> extra) || id < 1) {
            cout << "Invalid ID.\n";
            return;
        }

        auto it = find_if(
            contacts.begin(), contacts.end(),
            [id](const Contact& contact) {
                return contact.id == id;
            }
        );

        if (it == contacts.end()) {
            cout << "Contact not found.\n";
            return;
        }

        Contact removed = *it;
        contacts.erase(it);

        if (saveContacts()) {
            cout << "Contact deleted successfully.\n";
        } else {
            contacts.push_back(removed);
            cout << "Could not save deletion.\n";
        }
    }

public:
    ContactBook() {
        loadContacts();
    }

    void run() {
        cout << "============================\n";
        cout << "       CONTACT BOOK\n";
        cout << "============================\n";

        while (true) {
            cout << "\n1. Add Contact\n";
            cout << "2. View All Contacts\n";
            cout << "3. Search Contact\n";
            cout << "4. Delete Contact\n";
            cout << "0. Exit\n";

            string input = readText("Choose an option: ");
            stringstream ss(input);
            int choice;
            char extra;

            if (!(ss >> choice) || (ss >> extra)) {
                cout << "Please enter a valid option.\n";
                continue;
            }

            switch (choice) {
                case 1:
                    addContact();
                    break;
                case 2:
                    viewContacts();
                    break;
                case 3:
                    searchContact();
                    break;
                case 4:
                    deleteContact();
                    break;
                case 0:
                    cout << "Contacts saved. Goodbye!\n";
                    return;
                default:
                    cout << "Choose an option from 0 to 4.\n";
            }
        }
    }
};

int main() {
    ContactBook book;
    book.run();
    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

struct Expense {
    int id;
    string date;
    string category;
    double amount;
    string description;
};

class ExpenseTracker {
private:
    vector<Expense> expenses;
    const string filename = "expenses.csv";
    int nextId = 1;

    string trim(const string& text) const {
        size_t first = text.find_first_not_of(" \t\r\n");
        if (first == string::npos) return "";
        size_t last = text.find_last_not_of(" \t\r\n");
        return text.substr(first, last - first + 1);
    }

    string readText(const string& prompt) const {
        string value;
        cout << prompt;
        getline(cin, value);
        return trim(value);
    }

    int readInt(const string& prompt) const {
        while (true) {
            cout << prompt;
            string line;
            getline(cin, line);
            stringstream ss(line);
            int value;
            char extra;

            if (ss >> value && !(ss >> extra))
                return value;

            cout << "Please enter a valid whole number.\n";
        }
    }

    double readAmount() const {
        while (true) {
            cout << "Amount: ";
            string line;
            getline(cin, line);

            stringstream ss(line);
            double value;
            char extra;

            if (ss >> value && !(ss >> extra) &&
                isfinite(value) && value > 0.0 &&
                value <= 1.0e12) {
                return value;
            }

            cout << "Enter a valid amount greater than zero.\n";
        }
    }

    string csvEscape(const string& value) const {
        string result = "\"";
        for (char c : value) {
            if (c == '"') result += "\"\"";
            else result += c;
        }
        result += '"';
        return result;
    }

    vector<string> parseCsvLine(const string& line) const {
        vector<string> fields;
        string field;
        bool quoted = false;

        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];

            if (quoted) {
                if (c == '"') {
                    if (i + 1 < line.size() &&
                        line[i + 1] == '"') {
                        field += '"';
                        ++i;
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

    bool validDate(const string& date) const {
        if (date.size() != 10 ||
            date[4] != '-' || date[7] != '-')
            return false;

        for (int i = 0; i < 10; ++i) {
            if (i == 4 || i == 7) continue;
            if (!isdigit(static_cast<unsigned char>(date[i])))
                return false;
        }

        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        if (year < 1 || month < 1 || month > 12)
            return false;

        const int daysInMonth[] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int maxDay = daysInMonth[month - 1];

        bool leap = (year % 400 == 0) ||
                    (year % 4 == 0 && year % 100 != 0);

        if (month == 2 && leap) maxDay = 29;

        return day >= 1 && day <= maxDay;
    }

    void loadExpenses() {
        ifstream file(filename);
        if (!file) return;

        string line;
        getline(file, line); // Skip CSV header

        while (getline(file, line)) {
            vector<string> fields = parseCsvLine(line);

            if (fields.size() != 5) continue;

            try {
                size_t used = 0;
                int id = stoi(fields[0], &used);
                if (used != fields[0].size() || id < 1)
                    continue;

                if (!validDate(fields[1])) continue;

                size_t amountUsed = 0;
                double amount = stod(fields[3], &amountUsed);

                if (amountUsed != fields[3].size() ||
                    !isfinite(amount) || amount <= 0.0 ||
                    amount > 1.0e12)
                    continue;

                if (fields[2].empty() || fields[4].empty())
                    continue;

                expenses.push_back({
                    id, fields[1], fields[2],
                    amount, fields[4]
                });

                nextId = max(nextId, id + 1);
            } catch (...) {
                // Skip malformed records.
            }
        }
    }

    bool saveExpenses() const {
        ofstream file(filename, ios::trunc);
        if (!file) {
            cerr << "Error: Could not save expenses.\n";
            return false;
        }

        file << "id,date,category,amount,description\n";
        file << fixed << setprecision(2);

        for (const auto& e : expenses) {
            file << e.id << ','
                 << csvEscape(e.date) << ','
                 << csvEscape(e.category) << ','
                 << e.amount << ','
                 << csvEscape(e.description) << '\n';
        }

        file.flush();
        if (!file) {
            cerr << "Error while writing the CSV file.\n";
            return false;
        }

        return true;
    }

    void printExpense(const Expense& e) const {
        cout << left
             << setw(5) << e.id
             << setw(13) << e.date
             << setw(16) << e.category
             << right << setw(12) << fixed
             << setprecision(2) << e.amount
             << "  " << e.description << '\n';
    }

    void printHeader() const {
        cout << left
             << setw(5) << "ID"
             << setw(13) << "Date"
             << setw(16) << "Category"
             << right << setw(12) << "Amount"
             << "  Description\n";

        cout << string(75, '-') << '\n';
    }

    void addExpense() {
        cout << "\n--- Add Expense ---\n";

        string date;
        while (true) {
            date = readText("Date (YYYY-MM-DD): ");
            if (validDate(date)) break;
            cout << "Invalid date. Use a real date in YYYY-MM-DD format.\n";
        }

        string category = readText(
            "Category (Food/Travel/Bills/Shopping/Other): ");

        if (category.empty()) {
            cout << "Category cannot be empty.\n";
            return;
        }

        double amount = readAmount();

        string description = readText("Description: ");
        if (description.empty()) {
            cout << "Description cannot be empty.\n";
            return;
        }

        expenses.push_back({
            nextId, date, category, amount, description
        });

        if (saveExpenses()) {
            cout << "Expense added successfully! ID: "
                 << nextId << '\n';
            ++nextId;
        } else {
            expenses.pop_back();
            cout << "Expense was not saved.\n";
        }
    }

    void viewExpenses() const {
        cout << "\n--- All Expenses ---\n";

        if (expenses.empty()) {
            cout << "No expenses recorded yet.\n";
            return;
        }

        printHeader();

        double total = 0.0;
        for (const auto& e : expenses) {
            printExpense(e);
            total += e.amount;
        }

        cout << string(75, '-') << '\n';
        cout << "Total expenses: " << fixed
             << setprecision(2) << total << '\n';
    }

    void searchByCategory() const {
        string category = readText("Enter category: ");

        if (category.empty()) {
            cout << "Category cannot be empty.\n";
            return;
        }

        auto equalIgnoreCase = [](string a, string b) {
            transform(a.begin(), a.end(), a.begin(),
                [](unsigned char c) { return tolower(c); });
            transform(b.begin(), b.end(), b.begin(),
                [](unsigned char c) { return tolower(c); });
            return a == b;
        };

        bool found = false;
        double total = 0.0;

        for (const auto& e : expenses) {
            if (equalIgnoreCase(e.category, category)) {
                if (!found) {
                    printHeader();
                    found = true;
                }
                printExpense(e);
                total += e.amount;
            }
        }

        if (!found) {
            cout << "No expenses found in that category.\n";
        } else {
            cout << "Category total: " << fixed
                 << setprecision(2) << total << '\n';
        }
    }

    void searchByDescription() const {
        string query = readText("Search description: ");

        if (query.empty()) {
            cout << "Search text cannot be empty.\n";
            return;
        }

        auto lower = [](string s) {
            transform(s.begin(), s.end(), s.begin(),
                [](unsigned char c) { return tolower(c); });
            return s;
        };

        query = lower(query);
        bool found = false;

        for (const auto& e : expenses) {
            if (lower(e.description).find(query) != string::npos) {
                if (!found) printHeader();
                printExpense(e);
                found = true;
            }
        }

        if (!found) cout << "No matching expenses found.\n";
    }

    void monthlySummary() const {
        string month = readText("Enter month (YYYY-MM): ");

        if (month.size() != 7 ||
            month[4] != '-' ||
            !all_of(month.begin(), month.begin() + 4,
                [](unsigned char c) { return isdigit(c); }) ||
            !all_of(month.begin() + 5, month.end(),
                [](unsigned char c) { return isdigit(c); }) ||
            stoi(month.substr(5, 2)) < 1 ||
            stoi(month.substr(5, 2)) > 12) {
            cout << "Invalid month. Use YYYY-MM.\n";
            return;
        }

        double total = 0.0;
        int count = 0;

        cout << "\n--- Monthly Summary: " << month << " ---\n";
        printHeader();

        for (const auto& e : expenses) {
            if (e.date.substr(0, 7) == month) {
                printExpense(e);
                total += e.amount;
                ++count;
            }
        }

        if (count == 0) {
            cout << "No expenses found for this month.\n";
        } else {
            cout << string(75, '-') << '\n';
            cout << "Number of expenses: " << count << '\n';
            cout << "Total spending: " << fixed
                 << setprecision(2) << total << '\n';
            cout << "Average expense: " << total / count << '\n';
        }
    }

    void deleteExpense() {
        int id = readInt("Enter expense ID to delete: ");

        auto it = find_if(expenses.begin(), expenses.end(),
            [id](const Expense& e) { return e.id == id; });

        if (it == expenses.end()) {
            cout << "Expense ID not found.\n";
            return;
        }

        Expense removed = *it;
        expenses.erase(it);

        if (saveExpenses()) {
            cout << "Expense deleted successfully.\n";
        } else {
            expenses.push_back(removed);
            cout << "Deletion could not be saved. "
                 << "Please check the CSV file.\n";
        }
    }

public:
    ExpenseTracker() {
        loadExpenses();
    }

    void run() {
        cout << "====================================\n";
        cout << "       PERSONAL EXPENSE TRACKER\n";
        cout << "====================================\n";

        while (true) {
            cout << "\n1. Add Expense\n";
            cout << "2. View All Expenses\n";
            cout << "3. Search by Category\n";
            cout << "4. Search by Description\n";
            cout << "5. Monthly Summary\n";
            cout << "6. Delete Expense\n";
            cout << "0. Exit\n";

            int choice = readInt("Choose an option: ");

            switch (choice) {
                case 1: addExpense(); break;
                case 2: viewExpenses(); break;
                case 3: searchByCategory(); break;
                case 4: searchByDescription(); break;
                case 5: monthlySummary(); break;
                case 6: deleteExpense(); break;
                case 0:
                    cout << "Your expenses are saved. Goodbye!\n";
                    return;
                default:
                    cout << "Invalid option. Choose 0-6.\n";
            }
        }
    }
};

int main() {
    ExpenseTracker tracker;
    tracker.run();
    return 0;
}
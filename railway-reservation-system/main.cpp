
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <limits>
#include <cctype>

using namespace std;

const string DATA_FILE = "bookings.txt";

struct Train {
    int number;
    string name;
    string source;
    string destination;
    int totalSeats;
};

struct Booking {
    int pnr;
    int trainNumber;
    bool active;
    vector<string> passengers;
};

vector<Train> trains = {
    {12001, "Shatabdi Express", "Delhi", "Jaipur", 50},
    {12002, "Rajdhani Express", "Delhi", "Mumbai", 60},
    {12003, "Chennai Express", "Chennai", "Bengaluru", 40},
    {12004, "Eastern Express", "Kolkata", "Patna", 45},
    {12005, "Lucknow Express", "Delhi", "Lucknow", 50}
};

vector<Booking> bookings;

// Convert a string to lowercase for searching.
string lowerCase(string text) {
    transform(text.begin(), text.end(), text.begin(),
        [](unsigned char c) {
            return static_cast<char>(tolower(c));
        });
    return text;
}

void loadBookings() {
    ifstream file(DATA_FILE);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string pnrText, trainText, activeText, countText;
        string namesText;

        if (!getline(ss, pnrText, '|') ||
            !getline(ss, trainText, '|') ||
            !getline(ss, activeText, '|') ||
            !getline(ss, countText, '|') ||
            !getline(ss, namesText)) {
            continue;
        }

        try {
            Booking b;
            b.pnr = stoi(pnrText);
            b.trainNumber = stoi(trainText);

            if ((activeText != "0" && activeText != "1") ||
                b.pnr <= 0 || b.trainNumber <= 0) {
                continue;
            }

            b.active = (activeText == "1");
            int count = stoi(countText);

            if (count < 1 || count > 100) {
                continue;
            }

            stringstream nameStream(namesText);
            string name;

            while (getline(nameStream, name, '~')) {
                if (!name.empty()) {
                    b.passengers.push_back(name);
                }
            }

            if (static_cast<int>(b.passengers.size()) == count) {
                bookings.push_back(b);
            }
        } catch (...) {
            // Ignore malformed records.
        }
    }
}

void saveBookings() {
    ofstream file(DATA_FILE);

    if (!file) {
        cout << "Error: Could not save booking data.\n";
        return;
    }

    for (const Booking &b : bookings) {
        file << b.pnr << '|'
             << b.trainNumber << '|'
             << (b.active ? 1 : 0) << '|'
             << b.passengers.size() << '|';

        for (size_t i = 0; i < b.passengers.size(); ++i) {
            if (i > 0) file << '~';
            file << b.passengers[i];
        }

        file << '\n';
    }
}

const Train* findTrain(int number) {
    for (const Train &t : trains) {
        if (t.number == number) {
            return &t;
        }
    }
    return nullptr;
}

int availableSeats(int trainNumber) {
    const Train* train = findTrain(trainNumber);

    if (train == nullptr) return 0;

    int occupied = 0;

    for (const Booking &b : bookings) {
        if (b.trainNumber == trainNumber && b.active) {
            occupied += static_cast<int>(b.passengers.size());
        }
    }

    return train->totalSeats - occupied;
}

void displayTrains() {
    cout << "\n"
         << "------------------------------------------------"
         << "--------------------------------\n";
    cout << "                 AVAILABLE TRAINS\n";
    cout << "------------------------------------------------"
         << "--------------------------------\n";

    cout << "Train No.  Train Name           Source"
         << "          Destination       Seats\n";

    cout << "------------------------------------------------"
         << "--------------------------------\n";

    for (const Train &t : trains) {
        cout << t.number << "     ";

        cout << t.name;
        if (t.name.size() < 20)
            cout << string(20 - t.name.size(), ' ');

        cout << t.source;
        if (t.source.size() < 17)
            cout << string(17 - t.source.size(), ' ');

        cout << t.destination;
        if (t.destination.size() < 17)
            cout << string(17 - t.destination.size(), ' ');

        cout << availableSeats(t.number) << '\n';
    }

    cout << "------------------------------------------------"
         << "--------------------------------\n";
}

void searchTrains() {
    string source, destination;

    cout << "Enter source city: ";
    getline(cin, source);

    cout << "Enter destination city: ";
    getline(cin, destination);

    bool found = false;

    cout << "\nSearch results:\n";

    for (const Train &t : trains) {
        if (lowerCase(t.source) == lowerCase(source) &&
            lowerCase(t.destination) == lowerCase(destination)) {

            cout << t.number << " | " << t.name
                 << " | " << t.source << " -> "
                 << t.destination
                 << " | Available seats: "
                 << availableSeats(t.number) << '\n';

            found = true;
        }
    }

    if (!found) {
        cout << "No trains found for this route.\n";
    }
}

int generatePNR() {
    static mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(100000, 999999);

    while (true) {
        int candidate = distribution(generator);
        bool exists = false;

        for (const Booking &b : bookings) {
            if (b.pnr == candidate) {
                exists = true;
                break;
            }
        }

        if (!exists) return candidate;
    }
}

bool validPassengerName(const string &name) {
    return !name.empty() &&
           name.find('|') == string::npos &&
           name.find('~') == string::npos;
}

void bookTicket() {
    displayTrains();

    int trainNumber;

    cout << "Enter train number: ";
    if (!(cin >> trainNumber)) {
        cout << "Invalid train number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    const Train* train = findTrain(trainNumber);

    if (train == nullptr) {
        cout << "Train not found.\n";
        return;
    }

    int count;
    cout << "Enter number of passengers (1-6): ";

    if (!(cin >> count)) {
        cout << "Invalid passenger count.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (count < 1 || count > 6) {
        cout << "You can book for 1 to 6 passengers.\n";
        return;
    }

    if (availableSeats(trainNumber) < count) {
        cout << "Not enough seats available.\n";
        return;
    }

    Booking b;
    b.pnr = generatePNR();
    b.trainNumber = trainNumber;
    b.active = true;

    for (int i = 0; i < count; ++i) {
        string name;

        cout << "Enter name of passenger " << i + 1 << ": ";
        getline(cin, name);

        if (!validPassengerName(name)) {
            cout << "Invalid name. Booking cancelled.\n";
            return;
        }

        b.passengers.push_back(name);
    }

    bookings.push_back(b);
    saveBookings();

    cout << "\nTicket booked successfully!\n";
    cout << "PNR Number: " << b.pnr << '\n';
    cout << "Train: " << train->name << '\n';
    cout << "Route: " << train->source << " -> "
         << train->destination << '\n';
    cout << "Passengers: " << b.passengers.size() << '\n';
}

void checkPNR() {
    int pnr;

    cout << "Enter PNR number: ";
    if (!(cin >> pnr)) {
        cout << "Invalid PNR.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (const Booking &b : bookings) {
        if (b.pnr == pnr) {
            cout << "\n--------- BOOKING DETAILS ---------\n";
            cout << "PNR: " << b.pnr << '\n';
            cout << "Status: "
                 << (b.active ? "CONFIRMED" : "CANCELLED")
                 << '\n';

            const Train* train = findTrain(b.trainNumber);

            if (train != nullptr) {
                cout << "Train: " << train->name << '\n';
                cout << "Route: " << train->source << " -> "
                     << train->destination << '\n';
            }

            cout << "Passengers:\n";
            for (const string &name : b.passengers) {
                cout << "- " << name << '\n';
            }

            cout << "-----------------------------------\n";
            return;
        }
    }

    cout << "Booking not found. Please check the PNR.\n";
}

void cancelTicket() {
    int pnr;

    cout << "Enter PNR to cancel: ";
    if (!(cin >> pnr)) {
        cout << "Invalid PNR.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (Booking &b : bookings) {
        if (b.pnr == pnr) {
            if (!b.active) {
                cout << "This booking is already cancelled.\n";
                return;
            }

            b.active = false;
            saveBookings();

            cout << "Booking cancelled successfully.\n";
            cout << "PNR: " << b.pnr << '\n';
            cout << "Seats have been released.\n";
            return;
        }
    }

    cout << "Booking not found.\n";
}

void displayAllBookings() {
    bool found = false;

    cout << "\n--------- ALL BOOKINGS ---------\n";

    for (const Booking &b : bookings) {
        found = true;

        const Train* train = findTrain(b.trainNumber);

        cout << "PNR: " << b.pnr
             << " | Train: " << b.trainNumber
             << " | Passengers: " << b.passengers.size()
             << " | Status: "
             << (b.active ? "CONFIRMED" : "CANCELLED");

        if (train != nullptr) {
            cout << " | " << train->source
                 << " -> " << train->destination;
        }

        cout << '\n';
    }

    if (!found) {
        cout << "No bookings available.\n";
    }

    cout << "--------------------------------\n";
}

int main() {
    loadBookings();

    int choice;

    do {
        cout << "\n====================================\n";
        cout << "   RAILWAY RESERVATION SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Display All Trains\n";
        cout << "2. Search Trains by Route\n";
        cout << "3. Book Ticket\n";
        cout << "4. Check PNR Status\n";
        cout << "5. Cancel Ticket\n";
        cout << "6. Display All Bookings\n";
        cout << "7. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number from 1 to 7.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                displayTrains();
                break;
            case 2:
                searchTrains();
                break;
            case 3:
                bookTicket();
                break;
            case 4:
                checkPNR();
                break;
            case 5:
                cancelTicket();
                break;
            case 6:
                displayAllBookings();
                break;
            case 7:
                cout << "Thank you for using Railway Reservation System!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}

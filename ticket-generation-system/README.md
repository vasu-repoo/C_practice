
# 🚆 Railway Reservation System in C++

A console-based Railway Reservation System built using C++17.
This project simulates railway ticket booking, passenger management,
PNR tracking, ticket cancellation, and ticket generation.

## 📌 Project Information

- **Language:** C++
- **Standard:** C++17
- **Project Type:** Console Application
- **Level:** Intermediate
- **Repository:** vasu-repoo
- **Folder:** c++practise

## ✨ Features

- Display available trains and routes
- Search trains by source and destination
- Book tickets for multiple passengers
- Generate unique six-digit PNR numbers
- Check booking status using PNR
- Cancel confirmed tickets
- Automatically release cancelled seats
- Display all booking records
- Generate printable text-based tickets
- Save bookings to a local text file
- Load saved bookings when restarting the program

## 🛠️ Technologies Used

- C++17
- Structures and vectors
- File handling
- String manipulation
- Random number generation
- Standard Template Library (STL)

## 📂 Project Structure

    c++practise/
    ├── main.cpp
    ├── README.md
    ├── .gitignore
    ├── bookings.txt
    └── ticket_<PNR>.txt

Note: The booking and ticket files are generated automatically
when the program is used.

## ⚙️ Requirements

- GCC or MinGW-w64 C++ compiler
- C++17 support
- Visual Studio Code or another code editor
- Terminal or command prompt

## 🖥️ Application Menu

    ====================================
        RAILWAY RESERVATION SYSTEM
    ====================================
    1. Display All Trains
    2. Search Trains by Route
    3. Book Ticket
    4. Check PNR Status
    5. Cancel Ticket
    6. Display All Bookings
    7. Generate / Print Ticket
    8. Exit
    ====================================

## 🎫 Ticket Generation

After successfully booking a ticket:

1. Copy the generated PNR number.
2. Select the ticket generation option.
3. Enter the PNR number.
4. View the generated ticket in the terminal.
5. Open the generated ticket text file.

Example filename:

    ticket_482731.txt

The PNR shown is an example. Your program generates a new
number for each booking.

## 💾 Data Storage

The program uses local text files:

- `bookings.txt` stores booking records.
- `ticket_<PNR>.txt` stores individual ticket receipts.

Booking records are loaded when the application starts.

## 📚 Concepts Practiced

- Structures and user-defined data types
- Vectors and loops
- Functions and modular programming
- File input and output
- Input validation
- Searching and filtering
- Random number generation
- Menu-driven programming

## ⚠️ Limitations

- Train information is sample data.
- No live railway service is connected.
- No real train schedules or fares are provided.
- Data is stored locally without encryption.
- Generated tickets are educational receipts, not official tickets.

## 🔮 Future Improvements

- Add train schedules and departure times.
- Add fare calculation and payment simulation.
- Integrate an SQLite or MySQL database.
- Add administrator and passenger login.
- Export tickets to PDF.
- Add automated tests.

## 👨‍💻 Author

**Vasu**

GitHub: https://github.com/vasu-repoo

## 📄 License

This project is intended for educational and practice purposes.

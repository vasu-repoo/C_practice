Railway Reservation System in C++

A console-based Railway Reservation System developed in C++17 as an intermediate-level programming project.

Features
Display available trains and seat counts
Search trains by source and destination
Book tickets for multiple passengers
Generate unique six-digit PNR numbers
Check booking status using a PNR
Cancel confirmed bookings
Automatically release cancelled seats
View all booking records
Store booking information in a local text file
Validate user input and handle invalid menu choices
Technologies Used
C++17
Structures and vectors
File handling (ifstream and ofstream)
String processing
Random number generation
Project Structure
text
Railway-Reservation-System/
├── main.cpp
├── README.md
├── .gitignore
└── bookings.txt   # Generated automatically

Requirements
A C++17-compatible compiler
GCC, Clang, or a compatible C++ compiler
A terminal or command prompt
Installation and Setup
1. Clone the repository
bash
git clone https://github.com/vasu-repoo/C_practice/tree/main/railway-reservation-system
cd Railway-Reservation-System


2. Compile the program

Using GCC:

bash
g++ -std=c++17 -Wall -Wextra main.cpp -o railway

3. Run the program

Windows:

bash
railway.exe


Linux/macOS:

bash
./railway

How to Use
Select Display All Trains to see the available routes.
Select Search Trains by Route to find a train.
Select Book Ticket and enter the train number and passenger names.
Save the generated PNR number.
Use Check PNR Status to view booking details.
Use Cancel Ticket to cancel a booking.
Select Display All Bookings to review booking records.
Data Storage

Bookings are saved in bookings.txt in the directory where the program is run. Records are loaded when the application starts, so bookings persist between sessions.

The application uses sample train data and is intended for educational purposes. It does not connect to a real railway booking service.

Limitations
Train schedules, fares, and routes are sample data.
The application is not connected to a live railway database.
There is no login or administrator authentication.
Booking data is stored locally without encryption.
PNR numbers are generated for this local simulation and are not official railway PNRs.
Future Improvements
Add ticket fares and total cost calculations.
Add train schedules and departure times.
Add administrator login and train management.
Introduce a database such as SQLite or MySQL.
Generate printable tickets.
Add unit tests and improved input validation.
License

This project is available under the MIT License.
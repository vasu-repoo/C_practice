
# Railway Reservation System in C++

A console-based Railway Reservation System developed using C++17.
This project simulates basic railway ticket booking operations and
demonstrates object-oriented programming concepts, file handling,
and data management.

## Features

- Display all available trains
- Search trains by source and destination
- Book tickets for multiple passengers
- Generate unique six-digit PNR numbers
- Check booking status using PNR
- Cancel confirmed bookings
- Release seats after cancellation
- Display all booking records
- Save bookings to a local text file
- Handle invalid menu input

## Technologies Used

- C++17
- Structures and vectors
- File handling
- String processing
- Random number generation

## Project Structure

    Railway-Reservation-System/
    |
    |-- main.cpp
    |-- README.md
    |-- .gitignore
    |-- bookings.txt  (created automatically)

## Requirements

- A C++17-compatible compiler
- GCC, MinGW-w64, or Clang
- Terminal or command prompt

## Installation and Setup

### Step 1: Clone the Repository

    git clone https://github.com/vasu-repoo/C_practice/tree/main/railway-reservation-system

Enter the project directory:

    cd railway-reservation-system

### Step 2: Compile the Program

Using GCC:

    g++ -std=c++17 -Wall -Wextra main.cpp -o railway

### Step 3: Run the Program

On Windows:

    railway.exe

On Linux or macOS:

    ./railway

## How to Use

1. Run the program.
2. Select Display All Trains to view available trains.
3. Select Search Trains by Route to find a train.
4. Select Book Ticket to reserve seats.
5. Save the generated PNR number.
6. Select Check PNR Status to view booking details.
7. Select Cancel Ticket to cancel a booking.
8. Select Display All Bookings to view all records.
9. Select Exit to close the application.

## Sample Output

    ====================================
       RAILWAY RESERVATION SYSTEM
    ====================================
    1. Display All Trains
    2. Search Trains by Route
    3. Book Ticket
    4. Check PNR Status
    5. Cancel Ticket
    6. Display All Bookings
    7. Exit
    ====================================
    Enter your choice: 1

    AVAILABLE TRAINS

    Train No.  Train Name
    12001      Shatabdi Express
    12002      Rajdhani Express
    12003      Chennai Express
    12004      Eastern Express
    12005      Lucknow Express

Example booking:

    Enter your choice: 3
    Enter train number: 12001
    Enter number of passengers (1-6): 2
    Enter name of passenger 1: Rahul
    Enter name of passenger 2: Priya

    Ticket booked successfully!
    PNR Number: 482731
    Train: Shatabdi Express
    Route: Delhi -> Jaipur
    Passengers: 2

Note: The PNR shown above is an example. The program generates
a different number when a booking is created.

## Data Storage

Booking records are saved in bookings.txt.

The program loads saved records when it starts, allowing bookings
to persist between sessions.

The file is created automatically when booking data is saved.

## Limitations

- Uses sample train information.
- Does not connect to a real railway reservation service.
- Does not include user authentication.
- Stores data locally in a plain-text file.
- Does not provide real ticket fares or schedules.

## Future Improvements

- Add ticket fare calculation.
- Add train departure and arrival times.
- Add administrator login.
- Integrate an SQLite or MySQL database.
- Generate printable tickets.
- Add unit tests.

## License

This project is available under the MIT License.

## Author

Your Name

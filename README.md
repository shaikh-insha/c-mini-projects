# 💻 mini-c-projects

A curated collection of beginner to intermediate C programs developed for learning, practice, and fun. These projects help reinforce core C concepts like file handling, structs, functions, loops, conditionals, and user interaction.

---

## 📦 Projects Included

### 1. ✈️ Flight Reservation System (`flight_reservation_system.c`)
A menu-driven flight booking app using file handling and structs.

- View available flights
- Book and cancel reservations
- View current bookings
- Data is saved in binary files (`flights.dat`, `bookings.dat`)

> Practice: structs, binary file handling, user input validation

---

### 2. 📔 Personal Diary System (`personal_diary_system.c`)
A text-based diary system to store and manage daily entries.

- Add timestamped entries
- View full diary contents
- Edit by date (WIP)
- Delete all entries

> Practice: file I/O, timestamps (`<time.h>`), string handling

---

### 3. 🧠 Structured Quiz Game (`structured_quiz_game.c`)
Quiz game using an array of `struct` to hold questions and answers.

- Clean reusable logic
- Easy to expand with more questions
- Real-time feedback and score

> Practice: structs, loops, conditionals

---

### 4. 💱 Currency Converter (`currency_converter.c`)
Convert INR into foreign currencies like USD, EUR, GBP, and JPY.

- Menu-based input
- Simple calculation logic with fixed rates

> Practice: functions, switch-case, float handling

---

### 5. 🧮 Collatz Conjecture (`collatz_conjecture.c`)
A program that calculates how many steps it takes for a number to reach 1 using the Collatz rule.

- If even → divide by 2
- If odd → multiply by 3 and add 1

> Practice: loops, mathematical logic

---

## 🚀 How to Run Any Program

```bash
gcc filename.c -o outputname
./outputname

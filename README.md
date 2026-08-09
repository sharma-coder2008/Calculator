# C++ Calculator

A menu-driven calculator built in C++ as the final project for the Codédex C++ course. Supports addition and multiplication of multiple numbers, and subtraction/division of two numbers — all without using classes or OOP.

## Features

- **Add** — Add two or more numbers
- **Subtract** — Subtract two numbers
- **Multiply** — Multiply two or more numbers
- **Divide** — Divide one number by another
- **Exit** — Cleanly exit the program

## Highlights

- Uses `std::vector<int>` to store user input dynamically (`push_back`)
- Functions take `nums` and `n` **by reference (`&`)** so changes made inside a function (like appending numbers or updating a value) are reflected back in `main()`, without copying data unnecessarily
- Handles **division by zero** — keeps re-prompting for a valid second number instead of crashing
- Handles **invalid menu choices** — loops until the user enters a valid option (1–5)
- Uses `static_cast<double>` in `divide()` to avoid integer division truncation (e.g. so `7 / 2` correctly gives `3.5`, not `3`)
- Loop-based menu — perform multiple calculations in one run without restarting the program

## How It Works

1. `welcome()` and `menu()` display the intro and options
2. User enters a choice (1–5); invalid choices are re-prompted
3. Based on the choice:
   - **Add/Multiply**: user specifies how many numbers to enter, then `input()` collects them into the vector
   - **Subtract/Divide**: exactly 2 numbers are collected
4. The corresponding function (`add`, `subtract`, `multiply`, `divide`) computes and returns the result
5. Result is printed, the vector is reset, and the user is asked for their next choice
6. Choosing `5` exits the loop and prints a closing message

## Sample Run

```
====================
=====CALCULATOR=====
====================

Welcome to my Calculator
Here you can add a list of numbers, multiply them and subtract or divide two numbers
Enter 1 : To Add two or more numbers.
Enter 2 : To Subtract two numbers.
Enter 3 : To Multiply two or numbers.
Enter 4 : To Divide one number by other number.
Enter 5 : To Exit the program.
Enter your choice : 1

Enter how many numbers will input to add : 4
Enter the numbers :
5 10 15 20
Sum of the numbers : 50
Enter Your Next Choice : 4

Enter the numbers :
9 0
INVALID INPUT : DIVISION BY ZERO!!!!!!
Enter a valid input : 3
Quotient when 9 is divded by 3 is : 3
Enter Your Next Choice : 5

THANK YOU!!!!
Hope you found my calculator useful
```

## How to Compile & Run

```bash
g++ -std=c++17 -Wall -Wextra -o calculator main.cpp
./calculator
```

## What I Learned

- Passing variables **by reference (`&`)** in C++ isn't optional the way it can feel in Python/Java — you have to explicitly opt in, whereas Python/Java handle it implicitly based on whether the type is a primitive or an object
- Debugging undefined behavior (indexing into an empty vector before switching to `push_back`)
- Why return types matter — storing a `double` result in an `int` variable silently truncates the decimal part
- Using `static_cast<double>` to avoid integer division bugs

## Tech Stack

- C++17
- Standard Library: `<iostream>`, `<string>`, `<vector>`

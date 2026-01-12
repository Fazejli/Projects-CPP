# C++ Module 00

**Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff**

## 📋 Table of Contents

- [About](#about)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Exercises](#exercises)
  - [Exercise 00: Megaphone](#exercise-00-megaphone)
  - [Exercise 01: My Awesome PhoneBook](#exercise-01-my-awesome-phonebook)
  - [Exercise 02: The Job Of Your Dreams](#exercise-02-the-job-of-your-dreams)
- [Project Structure](#project-structure)
- [Learning Objectives](#learning-objectives)

## 📖 About

This is the first module of the C++ curriculum at 42. It introduces the fundamental concepts of Object-Oriented Programming using C++98 standard. This module focuses on basic C++ syntax, classes, and member functions.

**Version:** 11.0

## ⚙️ Requirements

- **Compiler:** `c++`
- **Standard:** C++98
- **Compilation flags:** `-Wall -Wextra -Werror -std=c++98`

### Forbidden

- External libraries (C++11, Boost, etc.)
- `*printf()`, `*alloc()`, `free()`
- `using namespace` and `friend` keywords
- STL Containers and Algorithms (reserved for Modules 08-09)

## 🔨 Compilation

Each exercise directory contains a Makefile with the following rules:

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild everything
```

## 📚 Exercises

### Exercise 00: Megaphone

**Turn-in files:** `Makefile`, `megaphone.cpp`

A simple program that converts command-line arguments to uppercase.

**Usage:**
```bash
./megaphone "shhhhh... I think the students are asleep..."
# Output: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
# Output: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

**Concepts learned:**
- Basic C++ syntax
- Command-line arguments
- String manipulation
- Standard output

---

### Exercise 01: My Awesome PhoneBook

**Turn-in files:** `Makefile`, `*.cpp`, `*.{h, hpp}`

An interactive phonebook application from the 80s technology era.

**Features:**
- Store up to 8 contacts
- FIFO replacement (oldest contact replaced when adding 9th)
- Three commands: `ADD`, `SEARCH`, `EXIT`

**Contact fields:**
- First name
- Last name
- Nickname
- Phone number
- Darkest secret

**Commands:**

| Command | Description |
|---------|-------------|
| `ADD` | Add a new contact (prompts for each field) |
| `SEARCH` | Display contacts list and select one to view details |
| `EXIT` | Quit the program |

**Search display format:**
- 4 columns: index, first name, last name, nickname
- Each column is 10 characters wide
- Right-aligned text
- Truncated text with '.' if longer than column width

**Concepts learned:**
- Class design (`PhoneBook`, `Contact`)
- Private vs Public members
- Arrays (no dynamic allocation)
- Input/output manipulation (`iomanip`)
- Data formatting and truncation

**Resources:**
- [std::string reference](http://www.cplusplus.com/reference/string/string/)
- [iomanip reference](http://www.cplusplus.com/reference/iomanip/)

---

### Exercise 02: The Job Of Your Dreams

**Turn-in files:** `Makefile`, `Account.cpp`, `Account.hpp`, `tests.cpp`

**⚠️ OPTIONAL EXERCISE** (not mandatory to pass the module)

Recreate a missing `Account.cpp` file based on:
- Provided `Account.hpp` header file
- Provided `tests.cpp` test file
- A log file showing expected output

**Scenario:**
You're a new developer at GlobalBanksters United. A source file was accidentally deleted, and you must recreate it by reverse-engineering from the header, tests, and log output.

**Challenge:**
- Match the exact output from the log file
- Implement all methods declared in `Account.hpp`
- Timestamps will differ (but format should match)

**Concepts learned:**
- Static class members
- Member function implementation
- Working with existing code/APIs
- Reverse engineering from tests
- Understanding class architecture

**Note:** Destructor call order may vary by compiler/OS.

---

## 📁 Project Structure

```
Module00/
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── Contact.hpp
│   ├── Contact.cpp
│   ├── PhoneBook.hpp
│   ├── PhoneBook.cpp
│   └── main.cpp
├── ex02/                    # Optional
│   ├── Makefile
│   ├── Account.hpp          # Provided
│   ├── Account.cpp          # To implement
│   ├── tests.cpp            # Provided
│   └── 19920104_091532.log  # Provided
└── README.md
```

## 🎯 Learning Objectives

By completing this module, you will understand:

1. **Basic C++ Syntax**
   - Difference between C and C++
   - C++ compilation and linking
   - Standard library usage

2. **Object-Oriented Programming Basics**
   - Classes and objects
   - Member functions
   - Private vs Public access
   - Constructors and destructors

3. **C++ I/O Streams**
   - `std::cout`, `std::cin`, `std::cerr`
   - Stream manipulators (`iomanip`)
   - Formatted output

4. **Class Design Principles**
   - Encapsulation
   - Data hiding
   - Class interfaces

5. **Memory Management Awareness**
   - Stack vs Heap (preparation for later modules)
   - No dynamic allocation yet (Module 01)

## 📝 Important Notes

- Read the entire module before starting!
- No Norminette - write clean, readable code
- Test your programs thoroughly
- Check for compilation warnings
- Memory leaks will be checked in later modules
- Use C++ features, not C functions

## 🚀 Tips

- Start with ex00 to familiarize yourself with C++ syntax
- For ex01, design your classes before coding
- Use `std::string` instead of C-style strings
- Practice using `std::cout` and `std::cin`
- ex02 is optional but great practice for understanding class implementation

## 📚 Resources

- [CPlusPlus.com Reference](http://www.cplusplus.com/)
- [C++98 Standard Documentation](https://en.cppreference.com/w/cpp/98)
- Module intranet videos

---

**Good luck with your C++ journey! 🎓**

*Remember: The learning journey is more important than the result. Build strong foundations without shortcuts!*

## Author
fadzejli

# C++ Module 01

**Memory allocation, pointers to members, references and switch statements**

## 📋 Table of Contents

- [About](#about)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Exercises](#exercises)
  - [Exercise 00: BraiiiiiiinnnzzzZ](#exercise-00-braiiiiiiinnnzzzzz)
  - [Exercise 01: Moar brainz!](#exercise-01-moar-brainz)
  - [Exercise 02: HI THIS IS BRAIN](#exercise-02-hi-this-is-brain)
  - [Exercise 03: Unnecessary violence](#exercise-03-unnecessary-violence)
  - [Exercise 04: Sed is for losers](#exercise-04-sed-is-for-losers)
  - [Exercise 05: Harl 2.0](#exercise-05-harl-20)
  - [Exercise 06: Harl filter](#exercise-06-harl-filter)
- [Project Structure](#project-structure)
- [Learning Objectives](#learning-objectives)

## 📖 About

Module 01 of the C++ curriculum focuses on memory management, the difference between stack and heap allocation, pointers to members, references, and control flow with switch statements.

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

### Exercise 00: BraiiiiiiinnnzzzZ

**Turn-in files:** `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`

Create a `Zombie` class with a private `name` attribute.

**Member functions:**
- `void announce(void)` - Zombie announces itself: `<name>: BraiiiiiiinnnzzzZ...`

**Required functions:**
```cpp
Zombie* newZombie(std::string name);  // Creates zombie on heap
void randomChump(std::string name);   // Creates zombie on stack
```

**Key concept:** Determine when to allocate on **stack** vs **heap**
- Stack: When the zombie dies at the end of the function
- Heap: When the zombie needs to live beyond the function scope

**Memory management:**
- Destructor must print zombie's name for debugging
- Don't forget to `delete` heap-allocated zombies!

**Concepts learned:**
- Stack vs Heap allocation
- `new` and `delete` operators
- Destructors
- Memory lifecycle

---

### Exercise 01: Moar brainz!

**Turn-in files:** `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `zombieHorde.cpp`

Create a horde of zombies with a single allocation!

**Required function:**
```cpp
Zombie* zombieHorde(int N, std::string name);
```

**Requirements:**
- Allocate `N` Zombie objects in a **single allocation**
- Initialize all zombies with the given name
- Return pointer to the first zombie
- Call `announce()` for each zombie in tests
- Use `delete[]` to deallocate the entire horde

**Concepts learned:**
- Array allocation with `new[]`
- Array deallocation with `delete[]`
- Single allocation for multiple objects
- Preventing memory leaks

---

### Exercise 02: HI THIS IS BRAIN

**Turn-in files:** `Makefile`, `main.cpp`

Demystify references by comparing them to pointers.

**Program requirements:**
```cpp
std::string brain = "HI THIS IS BRAIN";
std::string* stringPTR = &brain;  // Pointer to string
std::string& stringREF = brain;    // Reference to string
```

**Display:**
1. Memory address of `brain`
2. Memory address held by `stringPTR`
3. Memory address held by `stringREF`
4. Value of `brain`
5. Value pointed to by `stringPTR`
6. Value pointed to by `stringREF`

**Goal:** Understand that references are just another syntax for address manipulation!

**Concepts learned:**
- References vs Pointers
- Memory addresses
- Reference initialization
- Address-of operator (`&`)

---

### Exercise 03: Unnecessary violence

**Turn-in files:** `Makefile`, `main.cpp`, `Weapon.{h,hpp}`, `Weapon.cpp`, `HumanA.{h,hpp}`, `HumanA.cpp`, `HumanB.{h,hpp}`, `HumanB.cpp`

Implement a weapon system with two types of humans.

**Weapon class:**
```cpp
private:
    std::string type;
public:
    const std::string& getType();
    void setType(std::string newType);
```

**HumanA and HumanB classes:**
- Both have a `Weapon` and a `name`
- Both have `void attack()` displaying: `<name> attacks with their <weapon type>`

**Key differences:**
- **HumanA:** Takes weapon in constructor, **always armed**
- **HumanB:** Doesn't take weapon in constructor, **may not have weapon**

**Test code:**
```cpp
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();  // Should use new weapon type
}
```

**Think about it:** When to use pointer vs reference?
- **Reference:** When the object must always exist (HumanA)
- **Pointer:** When the object might not exist (HumanB)

**Concepts learned:**
- References vs Pointers in practice
- Const references
- Object relationships
- When to use each approach

---

### Exercise 04: Sed is for losers

**Turn-in files:** `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`

**Forbidden:** `std::string::replace()`

Create a file string replacement program.

**Usage:**
```bash
./replace <filename> <s1> <s2>
```

**Behavior:**
- Opens `<filename>`
- Creates `<filename>.replace`
- Replaces all occurrences of `s1` with `s2`
- Copies result to the new file

**Requirements:**
- No C file functions (use C++ streams)
- Can use any `std::string` member functions except `replace()`
- Handle errors and unexpected inputs
- Create your own tests

**Concepts learned:**
- File I/O with `std::ifstream` and `std::ofstream`
- String manipulation (`find()`, `insert()`, `erase()`)
- Error handling
- Stream operations

---

## 📁 Project Structure

```
Module01/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── Zombie.hpp
│   ├── Zombie.cpp
│   ├── newZombie.cpp
│   └── randomChump.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── Zombie.hpp
│   ├── Zombie.cpp
│   └── zombieHorde.cpp
├── ex02/
│   ├── Makefile
│   └── main.cpp
├── ex03/
│   ├── Makefile
│   ├── main.cpp
│   ├── Weapon.hpp
│   ├── Weapon.cpp
│   ├── HumanA.hpp
│   ├── HumanA.cpp
│   ├── HumanB.hpp
│   └── HumanB.cpp
├── ex04/
│   ├── Makefile
│   ├── main.cpp
│   ├── test.cpp
│   └── tests/
│       ├── test1.txt
│       ├── test2.txt
│       └── test3.txt
├── ex05/ (Not done yet)
├── ex06/ (Not done yet)
└── README.md
```

## 🎯 Learning Objectives

By completing this module, you will understand:

1. **Memory Management**
   - Stack allocation (automatic)
   - Heap allocation (`new`/`delete`)
   - When to use each
   - Memory leak prevention

2. **Pointers vs References**
   - Syntax differences
   - Use cases for each
   - Const references
   - Reference semantics

3. **Advanced Function Concepts**
   - Pointers to member functions
   - Function pointer arrays
   - Callback mechanisms

4. **File I/O**
   - Stream-based file operations
   - `ifstream` and `ofstream`
   - Error handling with files

5. **Control Flow**
   - Switch statements
   - Fall-through behavior
   - Switch vs if/else chains

## 🧠 Key Concepts

### Stack vs Heap

| Aspect | Stack | Heap |
|--------|-------|------|
| **Allocation** | Automatic | Manual (`new`) |
| **Deallocation** | Automatic | Manual (`delete`) |
| **Lifetime** | Function scope | Until `delete` |
| **Speed** | Faster | Slower |
| **Size** | Limited | Larger |
| **Use case** | Local variables | Dynamic objects |

### References vs Pointers

| Feature | Reference | Pointer |
|---------|-----------|---------|
| **Syntax** | `int& ref = var` | `int* ptr = &var` |
| **Nullable** | No | Yes (`nullptr`) |
| **Reassignment** | No | Yes |
| **Indirection** | Transparent | Explicit (`*ptr`) |
| **Use case** | Must exist | May be null |

## 📝 Important Notes

- Always `delete` what you `new`
- Always `delete[]` what you `new[]`
- Check for memory leaks with `valgrind`
- Destructors are your friends for cleanup
- Think about object lifetime before choosing stack/heap
- References are safer than pointers when object must exist

## 🚀 Tips

- Use `valgrind` to check for memory leaks:
  ```bash
  valgrind --leak-check=full ./program
  ```
- Test edge cases (empty strings, invalid inputs)
- ex06 is optional but teaches valuable switch concepts

## 🐛 Common Pitfalls

- Forgetting to `delete` heap-allocated objects
- Using `delete` instead of `delete[]` for arrays
- Dereferencing null pointers
- Using dangling pointers/references
- Not initializing pointers

---

**Remember: Memory management is crucial! Always clean up after yourself! 🧹**

*The learning journey is more important than the result. Build strong foundations without shortcuts!*

## Author
fadzejli

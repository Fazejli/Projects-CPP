# Exercise 04: Sed is for losers

**File String Replacement Tool**

## 📋 Description

A C++98 program that replaces all occurrences of a string in a file and writes the result to a new file with the `.replace` extension.

## 🎯 Objective

Learn file I/O operations in C++ using streams and string manipulation without using the `std::string::replace()` function.

## 📝 Requirements

- **Turn-in files:** `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`
- **Forbidden functions:** `std::string::replace()`
- **Forbidden:** C file manipulation functions (must use C++ streams)

## 💻 Usage

```bash
./replace <filename> <s1> <s2>
```

### Parameters

| Parameter | Description |
|-----------|-------------|
| `filename` | The input file to process |
| `s1` | The string to search for (cannot be empty) |
| `s2` | The replacement string (can be empty) |

### Example

```bash
./replace myfile.txt "hello" "world"
```

This will:
- Read `myfile.txt`
- Replace all occurrences of "hello" with "world"
- Create `myfile.txt.replace` with the result

## ⚙️ Implementation Details

### Algorithm

1. Open the input file for reading
2. Create output file `<filename>.replace` for writing
3. Read file line by line
4. For each line:
   - Find all occurrences of `s1`
   - Replace each with `s2`
   - Write modified line to output file
5. Close both files

### Key Functions

```cpp
// String operations allowed (except replace())
std::string::find()    // Find substring position
std::string::erase()   // Remove characters
std::string::insert()  // Insert characters
```

### File I/O

```cpp
std::ifstream inputFile(filename);      // Read from file
std::ofstream outputFile(filename + ".replace");  // Write to file
std::getline(inputFile, line);          // Read line by line
```

## 🔨 Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild everything
make test   # Run automated tests (if available)
```

### Compilation Flags

- `-Wall -Wextra -Werror`: All warnings enabled and treated as errors
- `-std=c++98`: Use C++98 standard

## 🧪 Testing

### Test Setup

Create test files in the `tests/` directory:

```bash
mkdir -p tests
echo "abc123" > tests/test1.txt
echo "Hexxo worxd !" > tests/test2.txt
printf "line1: test\nline2: Test\nline3: testtest !" > tests/test3.txt
```

### Test Cases

The included test suite (`test.cpp`) covers:

1. **Basic Replacement:** Simple string replacement
   ```bash
   ./replace tests/test1.txt "abc" "def"
   # Expected: def123
   ```

2. **Multiple Replacements:** Multiple occurrences in one line
   ```bash
   ./replace tests/test2.txt "x" "l"
   # Expected: Hello world !
   ```

3. **Multi-line Files:** Replacement across multiple lines
   ```bash
   ./replace tests/test3.txt "test" "TEST"
   # Expected: line1: TEST, line2: Test, line3: TESTTEST !
   ```

4. **Error Handling - File Not Found:**
   ```bash
   ./replace nonexistent.txt "test" "TEST"
   # Expected: Error: cannot open file nonexistent.txt
   ```

5. **Error Handling - Empty s1:**
   ```bash
   ./replace tests/test1.txt "" "TEST"
   # Expected: Filename and <s1> can not be empty
   ```

### Run Tests

```bash
make test
```

## ❌ Error Handling

The program handles the following error cases:

| Error | Message |
|-------|---------|
| Wrong number of arguments | `Check yout inputs` |
| Empty filename or s1 | `Filename and <s1> can not be empty` |
| Cannot open input file | `Error: cannot open file <filename>` |
| Cannot create output file | `Error: cannot open file <filename>.replace` |

## 📁 Project Structure

```
ex04/
├── Makefile              # Build configuration
├── main.cpp              # Main program
├── test.cpp              # Test suite (optional)
├── tests/                # Test files directory
│   ├── test1.txt
│   ├── test2.txt
│   └── test3.txt
└── README.md             # This file
```

## 🎓 Concepts Learned

1. **File I/O with C++ Streams**
   - `std::ifstream` for reading
   - `std::ofstream` for writing
   - `std::getline()` for line-by-line reading

2. **String Manipulation**
   - `find()` to locate substrings
   - `erase()` to remove characters
   - `insert()` to add characters
   - Understanding string positions

3. **Error Handling**
   - Checking file open status
   - Validating input parameters
   - Providing meaningful error messages

4. **Memory Management**
   - Efficient line-by-line processing
   - Avoiding loading entire file into memory

## 💡 Tips

- Test with various edge cases (empty strings, special characters)
- Consider what happens when `s1` appears multiple times consecutively
- Think about the order of operations: find, erase, insert
- After insertion, adjust your position to avoid infinite loops
- Don't forget to handle the case where `s2` contains `s1`

## 🐛 Common Pitfalls

- **Infinite loop:** If not advancing position after replacement
- **Wrong position:** Not updating search position after insert
- **Memory issues:** Loading entire file instead of line-by-line
- **File not closed:** Forgetting to close file streams
- **Empty lines:** Not preserving empty lines in output

## 🔍 Example Walkthrough

Given: `"hello hello world"`, replace `"hello"` with `"hi"`

```cpp
std::string line = "hello hello world";
std::string s1 = "hello";
std::string s2 = "hi";
size_t pos = 0;

// First occurrence at pos 0
pos = line.find(s1, 0);  // pos = 0
line.erase(0, 5);         // "hello world"
line.insert(0, "hi");     // "hi hello world"
pos = 0 + 2;              // pos = 2

// Second occurrence at pos 3
pos = line.find(s1, 2);   // pos = 3
line.erase(3, 5);         // "hi world"
line.insert(3, "hi");     // "hi hi world"
pos = 3 + 2;              // pos = 5

// No more occurrences
```

## 📚 Allowed `std::string` Functions

- `find(str, pos)` - Find substring
- `erase(pos, len)` - Erase characters
- `insert(pos, str)` - Insert string
- `length()` / `size()` - Get string length
- `empty()` - Check if empty
- `c_str()` - Get C-string
- `substr()` - Extract substring
- `operator+` - Concatenate strings

**NOT ALLOWED:** `replace()`

## 🚀 Going Further

Once you master the basics, consider:
- Handling special characters and escape sequences
- Case-insensitive replacement option
- Regex pattern support (in later modules)
- Backup file creation
- Multiple file processing

---

**Good luck! May your replacements be swift and your files forever uncorrupted! 📝**

*Remember: Test thoroughly and handle all edge cases!*

## Author
fadzejli
# AI Prompts Used - Learning Journal

This document tracks all the AI prompts I used while learning C++ and building this project.

---

## Initial Learning Phase

### Prompt 1: Understanding C++
**Prompt**: "What is C++ and what is it used for? Explain in beginner-friendly terms."

**What I Learned**: C++ is a compiled language used for high-performance applications, games, and systems programming. It gives you more control over hardware than languages like Python.

---

### Prompt 2: Setting Up Environment
**Prompt**: "How do I install a C++ compiler on [Mac/Windows/Linux]? What's the easiest way for a beginner?"

**What I Learned**: g++ is the most common compiler. On Mac, it comes with Xcode Command Line Tools. On Windows, MinGW or Visual Studio work well.

---

### Prompt 3: First Program
**Prompt**: "Show me a simple 'Hello World' program in C++ and explain each line."

**What I Learned**: 
- `#include <iostream>` imports input/output functionality
- `using namespace std;` lets us use `cout` instead of `std::cout`
- `int main()` is where the program starts
- `return 0;` means the program ended successfully

---

## Planning Phase

### Prompt 4: Project Ideas
**Prompt**: "What are some simple C++ project ideas for a complete beginner? Something more interesting than Hello World but still manageable."

**What I Learned**: To-do lists, calculators, and number guessing games are good starter projects that teach multiple concepts.

---

### Prompt 5: Project Structure
**Prompt**: "How should I structure a simple to-do list CLI application in C++? What functions and data structures do I need?"

**What I Learned**: 
- Use a struct to hold task data
- Use a vector to store multiple tasks
- Create separate functions for each action (add, view, delete)
- Use a while loop for the menu

---

## Development Phase

### Prompt 6: Understanding Vectors
**Prompt**: "What is a vector in C++ and how is it different from an array? Show me examples of adding and removing items."

**What I Learned**: Vectors are dynamic arrays that can grow/shrink. Use `push_back()` to add, `erase()` to remove, and `size()` to get length.

---

### Prompt 7: Structs vs Classes
**Prompt**: "Should I use a struct or class for storing task data in my to-do list? What's the difference?"

**What I Learned**: Structs are simpler for basic data containers. Classes are better when you need methods and encapsulation. For this project, struct is perfect.

---

### Prompt 8: File I/O
**Prompt**: "How do I save and load data from a text file in C++? I want to persist my to-do list between runs."

**What I Learned**: 
- Use `ofstream` for writing to files
- Use `ifstream` for reading from files
- Need to handle the case where file doesn't exist yet
- Choose a format (I used: `completed|description`)

---

### Prompt 9: Input Handling
**Prompt**: "Why does my program skip the getline() after cin >> number? How do I fix this?"

**What I Learned**: `cin >>` leaves a newline character in the buffer. Use `cin.ignore()` after it to clear the buffer before using `getline()`.

---

### Prompt 10: Menu Loop
**Prompt**: "How do I create a menu that keeps showing until the user chooses to exit?"

**What I Learned**: Use a `while(running)` loop with a boolean flag. Set `running = false` when user chooses exit option.

---

## Debugging Phase

### Prompt 11: Compilation Error
**Prompt**: "I'm getting 'expected ; before }' error. What does this mean?"

**What I Learned**: Missing semicolon somewhere before the closing brace. C++ requires semicolons after statements.

---

### Prompt 12: Vector Index Error
**Prompt**: "How do I safely access a vector element by index? I want to avoid crashes."

**What I Learned**: Check if index is valid: `if (index >= 0 && index < tasks.size())`. Remember vectors are 0-indexed but users think in 1-indexed terms.

---

### Prompt 13: Function Parameters
**Prompt**: "When should I use & in function parameters? What does void addTask(vector<Task>& tasks) mean?"

**What I Learned**: The `&` means pass by reference - the function modifies the original vector instead of making a copy. This is more efficient and necessary when you want changes to persist.

---

## Enhancement Ideas (Future)

### Prompt 14: Adding Features
**Prompt**: "What features could I add to make my to-do list more advanced while still being beginner-friendly?"

**Ideas Generated**:
- Task priorities (high, medium, low)
- Due dates
- Categories/tags
- Search functionality
- Color-coded output using ANSI codes
- Edit existing tasks

---

### Prompt 15: Code Organization
**Prompt**: "How would I split my C++ program into multiple files (header files and source files)?"

**What I Learned**: 
- Put function declarations in `.h` files
- Put implementations in `.cpp` files
- Use `#ifndef` guards to prevent double inclusion
- This is good practice for larger projects

---

## Reflection Prompts

### Prompt 16: Best Practices
**Prompt**: "What are some C++ best practices I should follow as a beginner?"

**Key Takeaways**:
- Use meaningful variable names
- Comment your code
- Keep functions small and focused
- Handle errors gracefully
- Initialize variables when declaring them
- Use const when values shouldn't change

---

### Prompt 17: Next Steps
**Prompt**: "After building a simple CLI to-do list, what C++ concepts should I learn next?"

**Learning Path**:
1. Classes and object-oriented programming
2. Pointers and dynamic memory
3. Standard Template Library (STL)
4. Error handling (try/catch)
5. Working with multiple files
6. Building larger projects

---

## Summary

**Total Prompts Used**: 17

**Most Helpful Prompts**: 
- File I/O explanation (saved me hours of trial and error)
- Input handling with cin.ignore() (solved a frustrating bug)
- Vector operations (core to the entire project)

**What I'd Ask Differently**:
- Should have asked about error handling earlier
- Could have asked for code review prompts
- Would ask about testing strategies

**Key Insight**: Breaking down the project into small questions and learning one concept at a time made C++ much less intimidating than trying to learn everything at once.

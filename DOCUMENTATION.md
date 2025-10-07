# C++ To-Do List - Capstone Documentation

**Student Name**: [Your Name]  
**Date**: October 2024  
**Technology**: C++  
**Project**: Command-Line To-Do List Application

---

## 1. Introduction

### What is C++?
C++ is a powerful, general-purpose programming language created by Bjarne Stroustrup in 1985. It's an extension of the C language with object-oriented features. C++ is used for:
- Operating systems (Windows, macOS, Linux)
- Game development (Unreal Engine)
- High-performance applications
- Embedded systems
- Financial systems

### Why Learn C++?
- **Performance**: One of the fastest programming languages
- **Control**: Direct memory management and hardware access
- **Industry Standard**: Widely used in systems programming and game development
- **Foundation**: Understanding C++ makes learning other languages easier

### Project Goal
Build a simple command-line to-do list application to learn C++ fundamentals including variables, functions, loops, conditionals, data structures, and file I/O.

---

## 2. Setup Instructions

### Step 1: Install a C++ Compiler

**For Mac:**
\`\`\`bash
# Install Xcode Command Line Tools
xcode-select --install
\`\`\`

**For Windows:**
1. Download MinGW-w64 from https://www.mingw-w64.org/
2. Install and add to PATH
3. Or install Visual Studio Community with C++ workload

**For Linux:**
\`\`\`bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install g++

# Fedora/CentOS
sudo yum install gcc-c++
\`\`\`

### Step 2: Verify Installation
\`\`\`bash
g++ --version
\`\`\`
You should see version information if installed correctly.

### Step 3: Create Project Folder
\`\`\`bash
mkdir cpp-todo-list
cd cpp-todo-list
\`\`\`

### Step 4: Create the Source File
Create a file named `main.cpp` and paste the code from the project.

### Step 5: Compile the Program
\`\`\`bash
g++ main.cpp -o todo
\`\`\`

### Step 6: Run the Program
\`\`\`bash
./todo        # Mac/Linux
todo.exe      # Windows
\`\`\`

---

## 3. How It Works

### Program Structure

The program is organized into several key components:

1. **Data Structure (Task struct)**
   \`\`\`cpp
   struct Task {
       string description;
       bool completed;
   };
   \`\`\`
   - Holds task information
   - `description`: what the task is
   - `completed`: whether it's done or not

2. **Main Function**
   - Entry point of the program
   - Loads saved tasks
   - Displays menu in a loop
   - Handles user choices

3. **Helper Functions**
   - `displayMenu()`: Shows options to user
   - `addTask()`: Creates new tasks
   - `viewTasks()`: Displays all tasks
   - `markComplete()`: Marks tasks as done
   - `deleteTask()`: Removes tasks
   - `saveTasks()`: Writes tasks to file
   - `loadTasks()`: Reads tasks from file

### Key C++ Concepts Used

**1. Variables and Data Types**
\`\`\`cpp
int choice;           // Integer for menu selection
string description;   // Text for task description
bool completed;       // True/false for task status
\`\`\`

**2. Vectors (Dynamic Arrays)**
\`\`\`cpp
vector<Task> tasks;   // Grows/shrinks as needed
tasks.push_back(newTask);  // Add to end
tasks.erase(tasks.begin() + index);  // Remove item
\`\`\`

**3. Loops**
\`\`\`cpp
while (running) {     // Keep showing menu
    // ...
}

for (size_t i = 0; i < tasks.size(); i++) {  // Iterate through tasks
    // ...
}
\`\`\`

**4. Conditionals**
\`\`\`cpp
if (tasks.empty()) {
    // Handle empty list
} else {
    // Show tasks
}

switch (choice) {
    case 1: addTask(); break;
    case 2: viewTasks(); break;
    // ...
}
\`\`\`

**5. Functions**
\`\`\`cpp
void addTask(vector<Task>& tasks) {
    // & means pass by reference (modify original)
}
\`\`\`

**6. File I/O**
\`\`\`cpp
ofstream file("tasks.txt");  // Write to file
ifstream file("tasks.txt");  // Read from file
\`\`\`

### Program Flow

1. Program starts → Load saved tasks from `tasks.txt`
2. Display welcome message
3. Show menu → Get user choice
4. Execute chosen action
5. Repeat until user chooses "Save and Exit"
6. Save tasks to file → Exit

---

## 4. Common Errors and Solutions

### Compilation Errors

**Error: "g++ command not found"**
- **Cause**: C++ compiler not installed or not in PATH
- **Solution**: Install g++ (see Setup Instructions)

**Error: "main.cpp: No such file or directory"**
- **Cause**: File doesn't exist or you're in wrong directory
- **Solution**: Check file name and current directory with `ls` or `dir`

**Error: "expected ';' before '}'"**
- **Cause**: Missing semicolon in code
- **Solution**: Check line mentioned in error, add semicolon

### Runtime Errors

**Error: "Segmentation fault"**
- **Cause**: Accessing invalid memory (rare in this simple program)
- **Solution**: Check array/vector bounds

**Problem: Tasks not saving**
- **Cause**: No write permissions or disk full
- **Solution**: Check folder permissions, ensure disk space

**Problem: Invalid input crashes program**
- **Cause**: Entering text when number expected
- **Solution**: Program uses `cin.ignore()` to handle this, but could be improved with better validation

### Logic Errors

**Problem: Wrong task gets deleted/completed**
- **Cause**: Off-by-one error (array indexing starts at 0)
- **Solution**: Code uses `taskNum - 1` to convert user input (1-based) to array index (0-based)

---

## 5. Testing the Application

### Test Case 1: Add Tasks
1. Run program
2. Choose option 1
3. Enter "Buy groceries"
4. Choose option 2 to view
5. **Expected**: Task appears in list as incomplete

### Test Case 2: Mark Complete
1. Add a task
2. Choose option 3
3. Enter task number
4. View tasks
5. **Expected**: Task shows [✓] checkmark

### Test Case 3: Delete Task
1. Add multiple tasks
2. Choose option 4
3. Enter task number
4. View tasks
5. **Expected**: Task is removed from list

### Test Case 4: Persistence
1. Add tasks
2. Choose option 5 to exit
3. Run program again
4. **Expected**: Previous tasks are loaded

### Test Case 5: Empty List
1. Start with no tasks
2. Try to mark complete or delete
3. **Expected**: Appropriate message shown

---

## 6. Learning Reflections

### What I Learned

**Technical Skills:**
- How to compile and run C++ programs
- Working with vectors (dynamic arrays)
- Creating and using structs (custom data types)
- Reading from and writing to files
- Handling user input safely
- Organizing code with functions

**Problem-Solving:**
- Breaking down a project into smaller functions
- Handling edge cases (empty lists, invalid input)
- Debugging compilation errors
- Testing different scenarios

**C++ Specific:**
- The difference between `#include <iostream>` and `#include "myfile.h"`
- Using `namespace std` to avoid writing `std::` everywhere
- Pass by reference (`&`) vs pass by value
- The importance of `cin.ignore()` after reading numbers

### Challenges Faced

1. **Understanding Pointers and References**
   - Initially confused about when to use `&`
   - Learned that `&` in function parameters means "modify the original"

2. **File I/O Format**
   - Had to decide how to store tasks in file
   - Used `|` as separator between completed status and description

3. **Input Handling**
   - Mixing `cin >>` and `getline()` caused issues
   - Solved with `cin.ignore()` to clear newline characters

### What I Would Do Differently

- Add input validation (check if user enters valid numbers)
- Use colors in terminal output for better UX
- Add task priorities or due dates
- Implement search functionality
- Use a better file format (JSON or CSV)

### Next Steps

To continue learning C++:
1. Learn about classes and object-oriented programming
2. Explore pointers and dynamic memory allocation
3. Study the Standard Template Library (STL)
4. Build a project with multiple files
5. Learn about error handling with try/catch

---

## 7. AI Prompts Used

See `AI_PROMPTS.md` for detailed list of prompts used during development.

---

## 8. Resources

### Official Documentation
- C++ Reference: https://en.cppreference.com/
- C++ Tutorial: https://www.learncpp.com/

### Recommended Learning
- "C++ Primer" by Stanley Lippman
- "Programming: Principles and Practice Using C++" by Bjarne Stroustrup
- YouTube: "C++ Tutorial for Beginners" by freeCodeCamp

### Tools
- Online Compiler: https://replit.com/languages/cpp
- IDE: Visual Studio Code with C++ extension
- Debugger: GDB (GNU Debugger)

---

## Conclusion

This project demonstrates fundamental C++ concepts through a practical application. The to-do list is simple but covers essential programming concepts: data structures, functions, loops, conditionals, and file I/O. These foundations are applicable to more complex C++ projects and other programming languages.

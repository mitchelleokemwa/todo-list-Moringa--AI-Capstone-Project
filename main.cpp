#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Structure to hold a task
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markComplete(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void saveTasks(const vector<Task>& tasks);
void loadTasks(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    loadTasks(tasks);
    
    int choice;
    bool running = true;
    
    cout << "=================================\n";
    cout << "  Welcome to C++ To-Do List!\n";
    cout << "=================================\n\n";
    
    while (running) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character
        
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markComplete(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                saveTasks(tasks);
                cout << "\nTasks saved! Goodbye!\n";
                running = false;
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n\n";
        }
    }
    
    return 0;
}

void displayMenu() {
    cout << "--- To-Do List Menu ---\n";
    cout << "1. Add a new task\n";
    cout << "2. View all tasks\n";
    cout << "3. Mark task as complete\n";
    cout << "4. Delete a task\n";
    cout << "5. Save and Exit\n";
    cout << "-----------------------\n";
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "\nEnter task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n\n";
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\n--- Your Tasks ---\n";
    if (tasks.empty()) {
        cout << "No tasks yet. Add one to get started!\n\n";
        return;
    }
    
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". ";
        if (tasks[i].completed) {
            cout << "[✓] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i].description << "\n";
    }
    cout << "------------------\n\n";
}

void markComplete(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks to mark as complete.\n\n";
        return;
    }
    
    viewTasks(tasks);
    int taskNum;
    cout << "Enter task number to mark as complete: ";
    cin >> taskNum;
    cin.ignore();
    
    if (taskNum > 0 && taskNum <= static_cast<int>(tasks.size())) {
        tasks[taskNum - 1].completed = true;
        cout << "Task marked as complete!\n\n";
    } else {
        cout << "Invalid task number.\n\n";
    }
}

void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks to delete.\n\n";
        return;
    }
    
    viewTasks(tasks);
    int taskNum;
    cout << "Enter task number to delete: ";
    cin >> taskNum;
    cin.ignore();
    
    if (taskNum > 0 && taskNum <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "Task deleted successfully!\n\n";
    } else {
        cout << "Invalid task number.\n\n";
    }
}

void saveTasks(const vector<Task>& tasks) {
    ofstream file("tasks.txt");
    if (!file) {
        cout << "Error saving tasks.\n";
        return;
    }
    
    for (const auto& task : tasks) {
        file << task.completed << "|" << task.description << "\n";
    }
    file.close();
}

void loadTasks(vector<Task>& tasks) {
    ifstream file("tasks.txt");
    if (!file) {
        return; // No saved tasks yet
    }
    
    Task task;
    string line;
    while (getline(file, line)) {
        size_t pos = line.find('|');
        if (pos != string::npos) {
            task.completed = (line[0] == '1');
            task.description = line.substr(pos + 1);
            tasks.push_back(task);
        }
    }
    file.close();
}

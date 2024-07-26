#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(std::string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskDescription) {
        tasks.emplace_back(taskDescription);
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description 
                      << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << std::endl;
        }
    }

    void markTaskCompleted(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
};

void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    ToDoList toDoList;
    int choice;
    std::string taskDescription;
    size_t taskIndex;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore(); // To ignore the newline character left in the buffer
                std::getline(std::cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            case 2:
                toDoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskIndex;
                toDoList.markTaskCompleted(taskIndex);
                break;
            case 4:
                std::cout << "Enter task number to remove: ";
                std::cin >> taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            case 5:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
#include <iostream>
#include <cstring>

const int MAX_TASKS = 100;

struct Task {
    char description[100];
    bool completed;
};

void addTask(Task taskList[], int& taskCount, const char* description) {
    if (taskCount < MAX_TASKS) {
        Task newTask;
        strcpy(newTask.description, description);
        newTask.completed = false;
        taskList[taskCount++] = newTask;
        std::cout << "Task added successfully.\n";
    } else {
        std::cout << "Task list is full. Cannot add more tasks.\n";
    }
}

void viewTasks(const Task taskList[], int taskCount) {
    std::cout << "Task List:\n";
    for (int i = 0; i < taskCount; ++i) {
        std::cout << (i + 1) << ". " << taskList[i].description << " - "
                  << (taskList[i].completed ? "Completed" : "Pending") << "\n";
    }
}

void markCompleted(Task taskList[], int taskCount, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskCount) {
        taskList[taskIndex - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

void removeTask(Task taskList[], int& taskCount, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskCount) {
        for (int i = taskIndex - 1; i < taskCount - 1; ++i) {
            taskList[i] = taskList[i + 1];
        }
        --taskCount;
        std::cout << "Task removed successfully.\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

int main() {
    Task taskList[MAX_TASKS];
    int taskCount = 0;

    while (true) {
        std::cout << "\n1. Add Task\n"
                  << "2. View Tasks\n"
                  << "3. Mark Task as Completed\n"
                  << "4. Remove Task\n"
                  << "5. Exit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                char description[100];
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Clear the input buffer
                std::cin.getline(description, sizeof(description));
                addTask(taskList, taskCount, description);
                break;
            }
            case 2:
                viewTasks(taskList, taskCount);
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> taskIndex;
                markCompleted(taskList, taskCount, taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter task index to remove: ";
                std::cin >> taskIndex;
                removeTask(taskList, taskCount, taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

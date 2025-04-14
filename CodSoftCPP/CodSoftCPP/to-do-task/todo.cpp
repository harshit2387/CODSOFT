#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask(string description) {
    tasks.push_back({ description, false });
    cout << "Task added: " << description << endl;
}

void viewTasks() {
    cout << "\nTo-Do List:\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    }
    else {
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].description
                << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }
}

void markTaskCompleted(int index) {
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed: " << tasks[index - 1].description << endl;
    }
    else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(int index) {
    if (index > 0 && index <= tasks.size()) {
        cout << "Removing task: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + index - 1);
    }
    else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice;
    string task;
    int taskNumber;

    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore extra newline

        switch (choice) {
        case 1:
            cout << "Enter task description: ";
            getline(cin, task);
            addTask(task);
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            cout << "Enter task number to mark as completed: ";
            cin >> taskNumber;
			if (cin.fail()) {
				cin.clear(); // clear the fail state
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
				cout << "Invalid input. Please enter a number.\n";
				continue;
			}
            markTaskCompleted(taskNumber);
            break;
        case 4:
            cout << "Enter task number to remove: ";
            cin >> taskNumber;
            removeTask(taskNumber);
            break;
        case 5:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
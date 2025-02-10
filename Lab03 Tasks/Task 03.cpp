// Task 03
#include <iostream>
using namespace std;

// CLASS PLANNER
class Planner {
public:
    string tasks[12][31]; // 12 months, max 31 days per month

    // ADD TASK FUNCTION
    void add(int month, int day) {
        if (isValidDate(month, day)) {
            cout << "Enter task for day " << day << " of month " << month << ": ";
            cin.ignore();
            getline(cin, tasks[month - 1][day - 1]);
        } else {
            cout << "Invalid Date!\n";
        }
    }

    // REMOVE FUNCTION
    void remove(int month, int day) {
        if (isValidDate(month, day)) {
            tasks[month - 1][day - 1] = "";
            cout << "Task for day " << day << " of month " << month << " is removed!\n";
        } else {
            cout << "Invalid Date!\n";
        }
    }

    // DISPLAY FUNCTION
    void display() {
        for (int i = 0; i < 12; i++) {
            cout << "\nTasks for Month " << i + 1 << ":\n";
            for (int j = 0; j < daysInMonth(i + 1); j++) {
                if (!tasks[i][j].empty()) {
                    cout << "Day " << j + 1 << ": " << tasks[i][j] << endl;
                }
            }
        }
    } 
    
    // Function to check if a date  valid
    bool isValidDate(int month, int day) {
        return (month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth(month));
    }

    // Function to get number of days in a given month
    int daysInMonth(int month) {
        if (month == 2) return 28; // February
        if (month == 4 || month == 6 || month == 9 || month == 11) return 30; // Months with 30 days
        return 31; // Months with 31 days
    }
};

int main() {
    Planner p1;
    int choice, month, day;

    while (true) {
        cout << "\n0. Exit the Planner.\n";
        cout << "1. Add a task.\n";
        cout << "2. Remove a Task.\n";
        cout << "3. Display all tasks.\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                return 0;
            case 1:
                cout << "\nAdding Task.\nEnter month and day: ";
                cin >> month >> day;
                p1.add(month, day);
                break;
            case 2:
                cout << "\nRemoving Task.\nEnter month and day: ";
                cin >> month >> day;
                p1.remove(month, day);
                break;
            case 3:
                cout << "\nDisplaying Tasks.\n";
                p1.display();
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    }
}




#include "TaskManager.hpp"

#include <iostream>
#include <string>
#include <limits>


int readInt(const std::string& prompt) {
    int val;

    while (true) {
        std::cout << prompt;

        if (std::cin >> val) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return val;
        }

        std::cout << "Invalid input. Please enter a number.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string readLine(const std::string& prompt) {
    std::string val;

    std::cout << prompt;
    std::getline(std::cin, val);

    return val;
}


int main() {
    
    TaskManager manager;
    
    int choice;

    while (true) {
        std::cout << "\n1. Add basic task\n";
        std::cout << "2. Add deadline task\n";
        std::cout << "3. Mark completed\n";
        std::cout << "4. Print all\n";
        std::cout << "5. Add recurring task\n";
        std::cout << "6. Save tasks\n";
        std::cout << "0. Exit\n";

        choice = readInt("Choice: ");

        switch (choice) {
            case 0: {
                std::cout << "Exit\n";
                return 0;
            }

            case 1: {
                std::string title = readLine("Add basic task - enter title:\n");
    
                manager.addTask(title);
                std::cout << "Task Added.\n";
                break;
            }

            case 2: {
                std::string title = readLine("Add deadline task - title and deadline\nEnter title:\n");
                std::string deadline = readLine("Enter deadline:\n");
                
                manager.addDeadlineTask(title, deadline);
                std::cout << "Task Added.\n";
                break;
            }

            case 3: {
                int id = readInt("Mark completed\nEnter Task ID:\n");

                if (manager.markTaskCompleted(id)) {
                    std::cout << "Task marked as completed.\n";
                } else {
                    std::cout << "Task not found.\n";
                }

                break;
            }

            case 4: {
                manager.printAllTasks();
                break;
            }
            
            case 5: {
                std::string title = readLine("Add recurring task\nEnter title:\n");
                std::string frequency = readLine("Enter frequency (Daily/Weekly/Monthly):\n");

                manager.addRecurringTask(title, frequency);
                std::cout << "Task Added.\n";
                break;
            }

            case 6: {
                manager.saveToFile("tasks.txt");
                std::cout << "Tasks saved\n";
                break;
            }

            default: {
                std::cout << "Invalid choice\n";
                break;
            }
        }
    }

    return 0;
}
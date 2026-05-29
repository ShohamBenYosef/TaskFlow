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


int main() {
    
    TaskManager manager;
    
    int choice;

    while (true) {
        std::cout << "\n1. Add basic task\n";
        std::cout << "2. Add deadline task\n";
        std::cout << "3. Mark completed\n";
        std::cout << "4. Print all\n";
        std::cout << "0. Exit\n";

        choice = readInt("Choice: ");

        switch (choice) {
            case 0: {
                std::cout << "Exit\n";
                return 0;
            }

            case 1: {
                std::string title;

                std::cout << "Add basic task - enter title:\n";
                
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, title);

                manager.addTask(title);
                std::cout << "Task Added.\n";
                break;
            }

            case 2: {
                std::string title, deadline;

                std::cout << "Add deadline task - title and deadline\nEnter title:\n";

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, title);

                std::cout << "Enter deadline:\n";
                std::getline(std::cin, deadline);
                
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

            default: {
                std::cout << "Invalid choice\n";
                break;
            }
        }
    }

    return 0;
}
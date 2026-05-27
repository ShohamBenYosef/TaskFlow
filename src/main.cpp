#include "../include/Task.hpp"
#include "../include/TaskManager.hpp"

#include <iostream>

int main () {

    TaskManager manager;

    manager.addTask("Learn Constructor.");
    manager.addTask("Practice OOP");

    manager.printAllTasks();
    
    manager.markTaskCompleted(1);

    std::cout << "\n\n";
    
    manager.printAllTasks();
    


    return 0;
}

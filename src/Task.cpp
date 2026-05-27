#include "Task.hpp"

#include <iostream>
#include <string>



Task(int id, std::string title)

int getId() const {
    return this.id;
}

std::string getTitle() const {
    return this.title;
}

bool isCompleted() const {
    return this.completed;
}

void markCompleted() {
    this.completed = true;
}

void printTask() const {
    std::cout << "Task no: " << this.id << "name: " << this.name << "is: " << this.complete << std::endl;
}
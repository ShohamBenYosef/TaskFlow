#include "Task.hpp"

#include <iostream>
#include <string>



Task::Task(int id, std::string title)
    : id(id), title(title), completed(false) {
}


int Task::getId() const {
    return this->id;
}

std::string Task::getTitle() const {
    return this->title;
}

bool Task::isCompleted() const {
    return this->completed;
}

void Task::markCompleted() {
    this->completed = true;
}

void Task::printTask() const {
    std::cout << "Task no: " << this->id
              << " | name: " << this->title
              << " | completed: " << (this->completed ? "yes" : "no")
              << std::endl;
}
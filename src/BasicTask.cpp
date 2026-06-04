#include "BasicTask.hpp"

#include <iostream>
#include <string>

BasicTask::BasicTask(int id, std::string title)
    :   Task(id, title) {
};

void BasicTask::printTask() const {
    std::cout << "Task no: " << this->id
              << " | name: " << this->title
              << " | completed: " << (this->completed ? "yes" : "no")
              << std::endl;
}

std::string BasicTask::serialize() const {
    return "BASIC|" + std::to_string(this->id) + "|"
     + this->title + "|" + (this->completed ? "1" : "0");
}


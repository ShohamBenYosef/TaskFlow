#include "DeadlineTask.hpp"

#include <iostream>
#include <string>


DeadLineTask::DeadLineTask(int id, std::string title, std::string deadline)
    : Task(id, title), deadline(deadline) {
}

void DeadLineTask::printTask() const {
    std::cout << "Task no: " << this->id
              << " | name: " << this->title
              << " | completed: " << (this->completed ? "yes" : "no")
              << " | deadline: " << this->deadline
              << std::endl;
}

std::string DeadLineTask::serialize() const {
    return "BASIC | " + std::to_string(this->id) + " | "
     + this->title + " | " + (this->completed ? "1" : "0") +
    " | " + this->deadline;
}
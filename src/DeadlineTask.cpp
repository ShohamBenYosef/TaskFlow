#include "DeadlineTask.hpp"

#include <iostream>

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
#include "RecurringTask.hpp"

#include <iostream>
#include <string>

RecurringTask::RecurringTask(int id, std::string title, std::string frequency)
    : Task(id,title), frequency(frequency) {
}

void RecurringTask::printTask() const {
    std::cout << "Task no: " << this->id
              << " | name: " << this->title
              << " | completed: " << (this->completed ? "yes" : "no")
              << " | frequency: " << this->frequency
              << std::endl;
}

std::string RecurringTask::serialize() const {
    return "RECURRING|" + std::to_string(this->id) + "|" +
           this->title + "|" +
           (this->completed ? "1" : "0") + "|" +
           this->frequency;
}
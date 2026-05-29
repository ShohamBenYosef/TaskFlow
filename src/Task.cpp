#include "Task.hpp"

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

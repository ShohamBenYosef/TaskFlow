#include "TaskManager.hpp"

TaskManager::TaskManager() 
    : nextId(1) {
    }

void TaskManager::addTask(const std::string& title) {
    this->tasks.emplace_back(nextId, title);
    this->nextId++;
}

void TaskManager::printAllTasks() const {
    for (const Task& t : tasks)
        t.printTask();
}

bool TaskManager::markTaskCompleted(int id) {
    for (Task& t : tasks) {
        if (t.getId() == id) {
            t.markCompleted();
            return true;
        }
    }
    return false;
}
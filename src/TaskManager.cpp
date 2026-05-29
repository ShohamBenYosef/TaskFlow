#include "TaskManager.hpp"
#include "DeadlineTask.hpp"
#include "BasicTask.hpp"


#include <memory>


TaskManager::TaskManager() 
    : nextId(1) {
}

void TaskManager::addTask(const std::string& title) {
    this->tasks.push_back(std::make_unique<BasicTask>(this->nextId, title));
    this->nextId++;
}

void TaskManager::addDeadlineTask(const std::string& title, const std::string& deadline) {
    this->tasks.push_back(std::make_unique<DeadLineTask>(this->nextId, title, deadline));
    this->nextId++;
}

void TaskManager::printAllTasks() const {
    for (const auto& t : this->tasks)
        t->printTask();
}

bool TaskManager::markTaskCompleted(int id) {
    for (auto& t : tasks) {
        if (t->getId() == id) {
            t->markCompleted();
            return true;
        }
    }
    return false;
}

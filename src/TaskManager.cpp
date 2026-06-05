#include "TaskManager.hpp"
#include "DeadlineTask.hpp"
#include "BasicTask.hpp"
#include "RecurringTask.hpp"
#include "TaskFactory.hpp"


#include <memory>
#include <fstream>
#include <iostream>
#include <vector>

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

void TaskManager::addRecurringTask(const std::string& title, const std::string& frequency) {
    this->tasks.push_back(std::make_unique<RecurringTask>(this->nextId, title, frequency));
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


void TaskManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    for (const auto& task : this->tasks) {
        file << task->serialize() << '\n';
    }
}

std::vector<std::string> splitLine(const std::string& line, char delimeter) {
    std::vector<std::string> res;
    std::string current;

    for (char c : line) {
        if (c == delimeter) {
            res.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }
    res.push_back(current);
    return res;
}

void TaskManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    this->tasks.clear();
    this->nextId = 1;

    std::string line;

    while (std::getline(file, line)) {
        std::vector<std::string> parts = splitLine(line, '|');

        auto task = TaskFactory::createTask(parts);

        if (task) {
            int loadedId = task->getId();

            this->tasks.push_back(std::move(task));

            if (loadedId >= this->nextId) {
                this->nextId = loadedId + 1;
            }
        } else {
            std::cerr << "Failed to parse task from line: " << line << std::endl;
        }
    }
}

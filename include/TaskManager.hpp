#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include "Task.hpp"

#include <vector>
#include <string>

class TaskManager {
    private:
        std::vector<Task> tasks;
        int nextId;
    public:
        TaskManager();

        void addTask(const std::string& title);
        void printAllTasks() const;
        bool markTaskCompleted(int id);
};

#endif


